#include <stdio.h>
#include <stdlib.h>
struct gp{
     int pid;
     int at;
     int bt;
     int ct,tat,wt; 
};
int com(const void *p, const void *q)
{
	int l = ((struct gp *)p)->at;
	int r = ((struct gp *)q)->at;
	return (l - r);
}
int com1(const void *p, const void *q)
{
	int l = ((struct gp *)p)->pid;
	int r = ((struct gp *)q)->pid;
	return (l - r);
}
int main(){
     int n;
int idele=0;
     printf("Enter number of process:\n");
     scanf("%d",&n);
     struct gp arr[n],t;
     printf("Enter Arrival and Burst Time\n");
     for(int i=0;i<n;i++)
	{
     arr[i].pid=i+1;
     scanf("%d%d",&arr[i].at,&arr[i].bt);
     }
     qsort((void*)arr, n, sizeof(arr[0]), com);
     int sum=0;
     arr[0].ct=arr[0].at+arr[0].bt;
     arr[0].tat= arr[0].ct-arr[0].at;
     arr[0].wt=arr[0].tat-arr[0].bt;
     int sum_tat=arr[0].tat;
     int sum_wait=arr[0].wt;
     int rt=arr[0].ct-arr[0].bt;
     float averagewt=0,averagetat=0;
	for(int i=1;i<n;i++){
          if(arr[i].at<=arr[i-1].ct)
		{ 
			arr[i].ct=arr[i-1].ct+arr[i].bt;
 		}         
		else 
		{
			idele=idele+arr[i].at+arr[i-1].ct;
			 arr[i].ct=arr[i].bt+arr[i].at;
          }
          arr[i].tat= arr[i].ct-arr[i].at;
          arr[i].wt=arr[i].tat-arr[i].bt;
          sum_tat+=arr[i].tat;
          sum_wait=arr[i].wt;
          rt+=arr[i].ct-arr[i].bt;
     }
float l_cycle=arr[n-1].ct-arr[0].at;
     float cpu=((l_cycle-idele)/l_cycle)*100;
float throput=n/l_cycle;
     qsort((void*)arr, n, sizeof(arr[0]), com1);
     printf("pid\tat\tbt\tct\ttat\twt\n");
     for(int i=0;i<n;i++){
			averagewt=averagewt+arr[i].wt;
			averagetat=averagetat+arr[i].tat;
			
          printf("%d\t%d\t%d\t%d\t%d\t%d\n",arr[i].pid,arr[i].at,arr[i].bt,arr[i].ct,arr[i].tat,arr[i].wt);
     }
     
     printf("Average waiting time :%f\nAverage turn around :%f\n\n",averagewt,averagetat);
     printf("Turn around time  :%d \n Total Waiting time:%d\n Length Cycle :%f\n Idele time is :%d\nCPU utilization time:%f\nThroughPut is :%f",sum_tat,sum_wait,l_cycle,idele,cpu,throput);
     return 0;
}
