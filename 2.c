// Write a C program in which parent process computes the sum of even Numbers and child process computes the sum of odd number stored in an array using a fork().
// First the child process should print its answer i.e sum of odd number then the parent process should print its answer i.e the sum of even number.


#include<stdio.h> #include<unistd.h> int main()
{
printf(“Ashish Joshi : A \n”);
int odd_sum=0,even_sum=0; 
  int a[5]={1,2,3,4,5};
int x=fork(); if(x!=0)
{
  for(int i=0;i<5;i++)
  {
    if(a[i]%2==0) 
      even_sum += a[i];
  }
  printf("Even sum = %d and Process id = %d\n",even_sum,getpid());
  }
  else
  {
    for(int i=0;i<5;i++)
    {
      if(a[i]%2!=0) 
        odd_sum += a[i];
    }
  printf("Odd sum = %d and Process id = %d\n",odd_sum,getpid());
}
}
