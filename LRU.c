#include <stdio.h>

int main()
{
    int pages[50], frame[10], time[10];
    int n, f, i, j, pos, faults = 0, counter = 0;
    int found;

    printf("Enter number of pages: ");
    scanf("%d", &n);

    printf("Enter page reference string:\n");
    for(i = 0; i < n; i++)
        scanf("%d", &pages[i]);

    printf("Enter number of frames: ");
    scanf("%d", &f);

    for(i = 0; i < f; i++)
    {
        frame[i] = -1;
        time[i] = 0;
    }

    for(i = 0; i < n; i++)
    {
        found = 0;

        for(j = 0; j < f; j++)
        {
            if(frame[j] == pages[i])
            {
                counter++;
                time[j] = counter;
                found = 1;
                break;
            }
        }

        if(found == 0)
        {
            pos = 0;

            for(j = 1; j < f; j++)
            {
                if(time[j] < time[pos])
                    pos = j;
            }

            frame[pos] = pages[i];
            counter++;
            time[pos] = counter;
            faults++;
        }

        printf("Frame: ");

        for(j = 0; j < f; j++)
        {
            if(frame[j] != -1)
                printf("%d ", frame[j]);
            else
                printf("- ");
        }

        printf("\n");
    }

    printf("Total Page Faults = %d\n", faults);

    return 0;
}
