#include <stdio.h>

int main()
{
    int alloc[10][10], max[10][10], need[10][10];
    int avail[10], finish[10];
    int safe[10];

    int n, m, i, j, k, count = 0;

    printf("Enter number of processes: ");
    scanf("%d", &n);

    printf("Enter number of resources: ");
    scanf("%d", &m);

    printf("Enter Allocation Matrix:\n");

    for(i = 0; i < n; i++)
    {
        for(j = 0; j < m; j++)
            scanf("%d", &alloc[i][j]);
    }

    printf("Enter Max Matrix:\n");

    for(i = 0; i < n; i++)
    {
        for(j = 0; j < m; j++)
            scanf("%d", &max[i][j]);
    }

    printf("Enter Available Resources:\n");

    for(i = 0; i < m; i++)
        scanf("%d", &avail[i]);

    for(i = 0; i < n; i++)
    {
        finish[i] = 0;

        for(j = 0; j < m; j++)
            need[i][j] = max[i][j] - alloc[i][j];
    }

    while(count < n)
    {
        int found = 0;

        for(i = 0; i < n; i++)
        {
            if(finish[i] == 0)
            {
                int possible = 1;

                for(j = 0; j < m; j++)
                {
                    if(need[i][j] > avail[j])
                    {
                        possible = 0;
                        break;
                    }
                }

                if(possible)
                {
                    for(j = 0; j < m; j++)
                        avail[j] += alloc[i][j];

                    safe[count] = i;
                    count++;
                    finish[i] = 1;
                    found = 1;
                }
            }
        }

        if(found == 0)
        {
            printf("System is not in safe state\n");
            return 0;
        }
    }

    printf("Safe Sequence:\n");

    for(i = 0; i < n; i++)
        printf("P%d ", safe[i]);

    return 0;
}
