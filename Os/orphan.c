#include <stdio.h>
#include <unistd.h> 
#include<stdlib.h>

int main()
{
    printf("Ashish Joshi Sec - A \n");
    int process = fork();
    if (process > 0)
    {
        printf("From Parent Process \n ");
        printf("Process ID from parent :%d", getpid());
        exit(0);
    }
    else
    {
        sleep(2);
        printf("From Child Process \n");
        printf("Process ID from child :%d", getppid());
    }
    return 0;
}
