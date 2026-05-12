#include <stdio.h>

int main()
{
    int alloc[10][10], req[10][10];
    int avail[10], finish[10];
    int p, r, i, j, count = 0;

    printf("Enter number of processes: ");
    scanf("%d", &p);

    printf("Enter number of resources: ");
    scanf("%d", &r);

    printf("Enter Allocation Matrix:\n");

    for(i = 0; i < p; i++)
    {
        for(j = 0; j < r; j++)
            scanf("%d", &alloc[i][j]);
    }

    printf("Enter Request Matrix:\n");

    for(i = 0; i < p; i++)
    {
        for(j = 0; j < r; j++)
            scanf("%d", &req[i][j]);
    }

    printf("Enter Available Resources:\n");

    for(i = 0; i < r; i++)
        scanf("%d", &avail[i]);

    for(i = 0; i < p; i++)
        finish[i] = 0;

    while(count < p)
    {
        int found = 0;

        for(i = 0; i < p; i++)
        {
            if(finish[i] == 0)
            {
                int possible = 1;

                for(j = 0; j < r; j++)
                {
                    if(req[i][j] > avail[j])
                    {
                        possible = 0;
                        break;
                    }
                }

                if(possible)
                {
                    for(j = 0; j < r; j++)
                        avail[j] += alloc[i][j];

                    finish[i] = 1;
                    found = 1;
                    count++;
                }
            }
        }

        if(found == 0)
            break;
    }

    printf("\nDeadlocked Processes:\n");

    int deadlock = 0;

    for(i = 0; i < p; i++)
    {
        if(finish[i] == 0)
        {
            printf("P%d ", i);
            deadlock = 1;
        }
    }

    if(deadlock == 0)
        printf("No Deadlock");

    return 0;
}
