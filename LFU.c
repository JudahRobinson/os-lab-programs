#include <stdio.h>

int main()
{
    int pages[50], frame[10], freq[10];
    int n, f, i, j, pos, faults = 0;
    int found, min;

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
        freq[i] = 0;
    }

    for(i = 0; i < n; i++)
    {
        found = 0;

        for(j = 0; j < f; j++)
        {
            if(frame[j] == pages[i])
            {
                freq[j]++;
                found = 1;
                break;
            }
        }

        if(found == 0)
        {
            min = freq[0];
            pos = 0;

            for(j = 1; j < f; j++)
            {
                if(freq[j] < min)
                {
                    min = freq[j];
                    pos = j;
                }
            }

            frame[pos] = pages[i];
            freq[pos] = 1;
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
