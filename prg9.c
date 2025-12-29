// fifo
#include <stdio.h>

int main()
{
    int i, j, k, f, pf = 0, count = 0;
    int rs[25], m[10], n;

    printf("\nEnter the length of reference string -- ");
    scanf("%d", &n);

    printf("\nEnter the reference string -- ");
    for (i = 0; i < n; i++)
        scanf("%d", &rs[i]);

    printf("\nEnter no. of frames -- ");
    scanf("%d", &f);

    for (i = 0; i < f; i++)
        m[i] = -1;

    printf("\nThe Page Replacement Process is --\n");

    for (i = 0; i < n; i++)
    {
        for (k = 0; k < f; k++)
        {
            if (m[k] == rs[i])
                break;
        }

        if (k == f)
        {
            m[count] = rs[i];
            count = (count + 1) % f;
            pf++;
        }

        for (j = 0; j < f; j++)
            printf("\t%d", m[j]);

        if (k == f)
            printf("\tPF No. %d", pf);

        printf("\n");
    }

    printf("\nThe number of Page Faults using FIFO are %d\n", pf);

    return 0;
}
// LRU
#include <stdio.h>

int main()
{
    int i, j, min;
    int rs[25], m[10], count[10], flag[25];
    int n, f, pf = 0, next = 1;

    printf("Enter the length of reference string -- ");
    scanf("%d", &n);

    printf("Enter the reference string -- ");
    for (i = 0; i < n; i++)
    {
        scanf("%d", &rs[i]);
        flag[i] = 0;
    }

    printf("Enter the number of frames -- ");
    scanf("%d", &f);

    for (i = 0; i < f; i++)
    {
        count[i] = 0;
        m[i] = -1;
    }

    printf("\nThe Page Replacement process is -- \n");

    for (i = 0; i < n; i++)
    {
        for (j = 0; j < f; j++)
        {
            if (m[j] == rs[i])
            {
                flag[i] = 1;
                count[j] = next++;
            }
        }

        if (flag[i] == 0)
        {
            if (i < f)
            {
                m[i] = rs[i];
                count[i] = next++;
            }
            else
            {
                min = 0;
                for (j = 1; j < f; j++)
                    if (count[j] < count[min])
                        min = j;

                m[min] = rs[i];
                count[min] = next++;
            }
            pf++;
        }

        for (j = 0; j < f; j++)
            printf("%d\t", m[j]);

        if (flag[i] == 0)
            printf("PF No. -- %d", pf);

        printf("\n");
    }

    printf("\nThe number of page faults using LRU are %d\n", pf);

    return 0;
}
