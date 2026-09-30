#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

#define MAX_JOBS 20

typedef struct
{
    int job_id;
    pid_t pid;
    pid_t pgid;
    char command[100];
    char state[20];
} Job;

Job jobs[MAX_JOBS];
int job_count = 0;
int next_job_id = 1;

void add_job(pid_t pid, pid_t pgid, const char *command)
{
    if (job_count >= MAX_JOBS)
    {
        printf("Job table full.\n");
        return;
    }

    jobs[job_count].job_id = next_job_id++;
    jobs[job_count].pid = pid;
    jobs[job_count].pgid = pgid;

    strncpy(jobs[job_count].command,
            command,
            sizeof(jobs[job_count].command) - 1);

    jobs[job_count].command[
        sizeof(jobs[job_count].command) - 1
    ] = '\0';

    strcpy(jobs[job_count].state, "RUNNING");

    printf("[%d] %d started in background: %s\n",
           jobs[job_count].job_id,
           pid,
           command);

    job_count++;
}

void remove_job(int index)
{
    for (int i = index; i < job_count - 1; i++)
    {
        jobs[i] = jobs[i + 1];
    }

    job_count--;
}

void update_jobs()
{
    int status;

    for (int i = 0; i < job_count;)
    {
        pid_t result = waitpid(
            jobs[i].pid,
            &status,
            WNOHANG
        );

        if (result == 0)
        {
            i++;
        }
        else if (result == jobs[i].pid)
        {
            strcpy(jobs[i].state, "DONE");

            printf("\n[%d] DONE: %s\n",
                   jobs[i].job_id,
                   jobs[i].command);

            remove_job(i);
        }
        else
        {
            i++;
        }
    }
}

void list_jobs()
{
    update_jobs();

    if (job_count == 0)
    {
        printf("No active background jobs.\n");
        return;
    }

    printf("\nJOB TABLE\n");
    printf("-------------------------------------------------\n");
    printf("ID\tPID\tPGID\tSTATE\t\tCOMMAND\n");
    printf("-------------------------------------------------\n");

    for (int i = 0; i < job_count; i++)
    {
        printf("[%d]\t%d\t%d\t%s\t\t%s\n",
               jobs[i].job_id,
               jobs[i].pid,
               jobs[i].pgid,
               jobs[i].state,
               jobs[i].command);
    }

    printf("-------------------------------------------------\n");
}

void start_background_job(int seconds)
{
    pid_t pid = fork();

    if (pid < 0)
    {
        perror("fork");
        return;
    }

    if (pid == 0)
    {
        /*
         * Child becomes leader of its own
         * process group.
         */
        setpgid(0, 0);

        printf("Background process %d running for %d seconds...\n",
               getpid(),
               seconds);

        sleep(seconds);

        printf("Background process %d finished.\n",
               getpid());

        exit(0);
    }

    /*
     * Parent also attempts to place the child
     * into its own process group.
     */
    setpgid(pid, pid);

    add_job(pid, pid, "background-task");

    /*
     * IMPORTANT:
     * Parent does NOT wait here.
     * Therefore the shell/prompt can continue.
     */
}

int main()
{
    char input[100];

    printf("========================================\n");
    printf("       SHELLFORGE JOB CONTROL\n");
    printf("========================================\n");

    printf("\nCommands:\n");
    printf("  bg      - start background job\n");
    printf("  jobs    - list active jobs\n");
    printf("  check   - update job states\n");
    printf("  exit    - quit\n");

    while (1)
    {
        update_jobs();

        printf("\nSHELLFORGE-JOBS$ ");
        fflush(stdout);

        if (fgets(input, sizeof(input), stdin) == NULL)
        {
            break;
        }

        input[strcspn(input, "\n")] = '\0';

        if (strcmp(input, "bg") == 0)
        {
            start_background_job(10);
        }
        else if (strcmp(input, "jobs") == 0)
        {
            list_jobs();
        }
        else if (strcmp(input, "check") == 0)
        {
            update_jobs();
            printf("Job states updated.\n");
        }
        else if (strcmp(input, "exit") == 0)
        {
            break;
        }
        else if (strlen(input) == 0)
        {
            continue;
        }
        else
        {
            printf("Unknown command: %s\n", input);
        }
    }

    return 0;
}
