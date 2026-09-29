#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_HISTORY 5
#define MAX_CMD 100

char history[MAX_HISTORY][MAX_CMD];
int count = 0;

void add_history(char *cmd)
{
    if (count < MAX_HISTORY)
    {
        strcpy(history[count], cmd);
        count++;
    }
    else
    {
        for (int i = 1; i < MAX_HISTORY; i++)
            strcpy(history[i - 1], history[i]);

        strcpy(history[MAX_HISTORY - 1], cmd);
    }
}

void display_history()
{
    printf("\n--- Command History ---\n");

    for (int i = 0; i < count; i++)
        printf("%d  %s\n", i + 1, history[i]);
}

int main()
{
    char command[MAX_CMD];

    printf("Command History Demo\n");
    printf("Type 'history' to display history\n");
    printf("Type 'exit' to quit\n\n");

    while (1)
    {
        printf("$ ");
        fgets(command, MAX_CMD, stdin);

        command[strcspn(command, "\n")] = '\0';

        if (strcmp(command, "exit") == 0)
            break;

        if (strcmp(command, "history") == 0)
        {
            display_history();
            continue;
        }

        if (strlen(command) > 0)
            add_history(command);
    }

    return 0;
}
