#include <stdio.h>
int find(int frames[], int page, int m)
{
    for (int i = 0; i < m; i++)
    {
        if (frames[i] == page)
        {
            return 1;
        }
    }
    return 0;
}
int main()
{
    int n, m;
    printf("\nEnter number of pages and frames :");
    scanf("%d%d", &n, &m);

    int pages[n];
    int frames[m];
    printf("Enter pages : ");
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &pages[i]);
    }
    for (int j = 0; j < m; j++)
    {
        frames[j] = -1;
    }
    printf("\nFrame 1\t\tFrame 2\t\tFrame 3\t\tFrame 4\n");
    int count = 0, i = 0, pc = 0;
    while (i < n)
    {

        if (frames[pc] == -1 && pc < m)
        {
            if (!find(frames, pages[i], m))
            {

                frames[pc] = pages[i];
                pc++;
                pc = pc % m;
                count++;
                i++;
            }
            else
            {
                i++;
            }
        }
        else
        {
            if (find(frames, pages[i], m))
            {
                i++;
            }
            else
            {
                frames[pc] = pages[i];
                count++;
                i++;
                pc++;
                pc = pc % m;
            }
        }
        for (int i = 0; i < m; i++)
        {
            if (frames[i] != -1)
            {
                printf("%d\t\t", frames[i]);
            }
            else
            {
                printf("-\t\t");
            }
        }
        printf("\n");
    }

    printf("\nNumber of Page Faults :%d\n", count);
}