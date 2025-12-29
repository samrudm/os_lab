// sstf
#include <stdio.h>
#include <math.h>

int main()
{
    int queue[100], t[100];
    int head, seek = 0, n, i, j, temp;
    float avg;

    printf("*** SSTF Disk Scheduling Algorithm ***\n");

    printf("Enter the size of Queue\t");
    scanf("%d", &n);

    printf("Enter the Queue\t");
    for (i = 0; i < n; i++)
        scanf("%d", &queue[i]);

    printf("Enter the initial head position\t");
    scanf("%d", &head);

    /* Calculate distance from head */
    for (i = 0; i < n; i++)
        t[i] = abs(head - queue[i]);

    /* Sort according to shortest seek time */
    for (i = 0; i < n; i++)
    {
        for (j = i + 1; j < n; j++)
        {
            if (t[i] > t[j])
            {
                temp = t[i];
                t[i] = t[j];
                t[j] = temp;

                temp = queue[i];
                queue[i] = queue[j];
                queue[j] = temp;
            }
        }
    }

    /* Calculate total seek time */
    for (i = 0; i < n; i++)
    {
        seek += abs(head - queue[i]);
        head = queue[i];
    }

    printf("\nTotal Seek Time is %d\t", seek);

    avg = seek / (float)n;
    printf("\nAverage Seek Time is %f\t", avg);

    return 0;
}
// scan sheduling
#include <stdio.h>

int main()
{
    int t[20], d[20], atr[20];
    int h, i, j, n, temp, k, p;
    int sum = 0;

    printf("Enter the no of tracks to be traversed: ");
    scanf("%d", &n);

    printf("Enter the position of head: ");
    scanf("%d", &h);

    /* Initialize */
    t[0] = 0;
    t[1] = h;

    printf("Enter the tracks:\n");
    for (i = 2; i < n + 2; i++)
        scanf("%d", &t[i]);

    /* Sort the tracks */
    for (i = 0; i < n + 2; i++)
    {
        for (j = 0; j < (n + 1) - i; j++)
        {
            if (t[j] > t[j + 1])
            {
                temp = t[j];
                t[j] = t[j + 1];
                t[j + 1] = temp;
            }
        }
    }

    /* Find head position */
    for (i = 0; i < n + 2; i++)
        if (t[i] == h)
            break;

    j = i;
    k = i;
    p = 0;

    /* Move towards 0 */
    while (j >= 0)
        atr[p++] = t[j--];

    /* Move towards higher tracks */
    for (i = k + 1; i < n + 2; i++)
        atr[p++] = t[i];

    /* Calculate head movements */
    for (i = 0; i < p - 1; i++)
    {
        d[i] = atr[i] > atr[i + 1] ? atr[i] - atr[i + 1] : atr[i + 1] - atr[i];
        sum += d[i];
    }

    printf("\nAverage header movements: %f\n", (float)sum / n);

    return 0;
}
