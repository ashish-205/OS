#include<stdio.h>
#include<math.h>

int main()
{
	int n ;
	printf("Enter the values of the matrix\n");
	scanf("%d", &n);
	
	float arr[n][n+1] ;
	
	for(int i = 0 ; i < n ; i++) 
	{
		for(int j = 0 ; j <= n ; j++) 
		{
			scanf("%d", &arr[i][j]) ;
		}
	}

	for(int i = 1 ; i < n ; j++) 
	{
		int curr = arr[i][0] ;
		for(int j = 0 ; j <= n ; j++) 
		{
			int y = arr[i-1][j] ; 
			
			arr[i][j] = 
			
		}
	}

}



















#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>

int main()
{
  printf("Ashish Joshi : A \n");
  int x = fork();
  if(x>0)
   {
    printf("parent process \n ");
    exit(0);
    }
  else
  {
    sleep(2);
    printf("child process \n");
   }
  return 0;
}
















