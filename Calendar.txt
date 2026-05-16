#include <stdio.h>
#include <string.h>

#define MAX_DAYS 7
#define MAX_TASKS 3
#define MAX_TASK_LENGTH 50

struct Day {
    char dayName[20];
    char tasks[MAX_TASKS][MAX_TASK_LENGTH];
    int taskCount;
};

int main() {
    struct Day week[MAX_DAYS] = {
        {"Monday", {}, 0},
        {"Tuesday", {}, 0},
        {"Wednesday", {}, 0},
        {"Thursday", {}, 0},
        {"Friday", {}, 0},
        {"Saturday", {}, 0},
        {"Sunday", {}, 0}
    };

    int choice, numTasks, i, j;


    for(i = 0; i < MAX_DAYS; i++) {
        printf("\nEnter number of tasks for %s (max 3): ",
               week[i].dayName);
        scanf("%d", &numTasks);

        if(numTasks > MAX_TASKS)
            numTasks = MAX_TASKS;

        week[i].taskCount = numTasks;

        getchar();

        for(j = 0; j < numTasks; j++) {
            printf("Enter task %d: ", j + 1);
            fgets(week[i].tasks[j], MAX_TASK_LENGTH, stdin);

            week[i].tasks[j][strcspn(week[i].tasks[j], "\n")] = '\0';
        }
    }

    printf("\n Weekly Calendar \n");

    for(i = 0; i < MAX_DAYS; i++) {
        printf("\n%s:\n", week[i].dayName);

        if(week[i].taskCount == 0) {
            printf("No tasks\n");
        } else {
            for(j = 0; j < week[i].taskCount; j++) {
                printf("- %s\n", week[i].tasks[j]);
            }
        }
    }

    return 0;
}