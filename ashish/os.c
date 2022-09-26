
#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>

int main()
{
  printf("Anirudh Semwal : A \n");
  int x = fork();
  if(x>0)
   {
   printf("\nProcess ID from Parent:%d",getpid());
    printf("\nFrom Parent Process \n ");
    exit(0);
    }
  else
  {
    sleep(2);
    printf("\nFrom Child Process \n");
    printf("\nProcess ID from child :%d",getppid());
   }
  return 0;
}
