// Write a C program to demonstrate the use of fork() system call.

#include<unistd.h>
#include<stdio.h> 
int main()
{
 printf("Ashish Joshi : A \n");
fork();
printf("Program id: %d\n",getpid());
}
