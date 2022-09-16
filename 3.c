// WAP to implement Zombie process.


#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>

int main()
{
printf(“Ashish Joshi section :A \n”);
int x = fork();
if(x>0)
{
  sleep(2);
  printf("parent process \n ");
}
else
{
  printf("child process \n");
  exit(0);
}
  return 0;
}
