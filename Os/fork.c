#include<unistd.h>
 #include<stdio.h> 
 int main()
{
   printf("Ashish Joshi Section : A \n");
   fork();
   printf("Program id: %d\n",getpid());
}
