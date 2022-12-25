#include <stdio.h>
#include <unistd.h>
int main()
{
    printf("Ashish Joshi Sec - A\n");
    int odd = 0, even = 0;
    int arr[5] = {1, 2, 3, 4, 5};
    int pid = fork();

    if (pid != 0)
    {
        for (int i = 0; i < 5; i++)
        {
            if (arr[i] % 2 == 0)
                even += arr[i];
        }
        printf("Even sum = %d and Process Id:%d\n", even, getpid());
    }
    else
    {
        for (int i = 0; i < 5; i++)
        {
            if (arr[i] % 2 != 0)
                odd += arr[i];
        }
        printf("Odd sum = %d  and Process Id:%d \n", odd, getpid());
    }
}
