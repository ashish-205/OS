#include<stdio.h>
#include<stdlib.h>

struct pr{
    int pid;
    int at;
    int bt;
    int ct;
    int tat;
    int wt;
    int st;
    int rt;
};
int comp(const void * p,const void * q)
{
    int l=((struct pr *)p)->at;
    int r=((struct pr *)q)->at;
    return (l-r);
}
int main()
{
    int n;
    printf("Enter number of process :");
    scanf("%d",&n);
    struct pr a[n];
   int idle=0;
    printf("Enter at and bt :\n");
    for(int i=0;i<n;i++)
    {
        a[i].pid=i+1;
        scanf("%d%d",&a[i].at,&a[i].bt);
    }
    qsort((void*)a,n,sizeof(a[0]),comp);
    a[0].ct=a[0].bt;
    a[0].tat=a[0].bt;
    a[0].wt=0;
    a[0].rt=0;
    a[0].st=a[0].at;
    for(int i=1;i<n;i++)
    {
        if(a[i-1].ct> a[i].at)
        {
            a[i].ct=a[i].bt + a[i-1].ct;  
        }
        else
        {
            idle+=a[i].at-a[i-1].ct;
            a[i].ct=a[i].at+a[i].bt;
        }
        a[i].tat=a[i].ct-a[i].at;
        a[i].wt=a[i].tat-a[i].bt;
        a[i].st=a[i].ct-a[i].bt;
        a[i].rt=a[i].st-a[i].at;
    }
    float avgtat=0,avgwt=0,avgrt=0;
    printf("Pid\tat\tbt\tct\ttat\twt\trt\tst\n");
    for(int i=0;i<n;i++)
    {
        printf("%d\t%d\t%d\t%d\t%d\t%d\t%d\t%d\n",a[i].pid,a[i].at,a[i].bt,a[i].ct,a[i].tat,a[i].wt,a[i].rt,a[i].st);
        avgtat+=a[i].tat;
        avgwt+=a[i].wt;
        avgrt+=a[i].rt;
    }

    int length=a[n-1].ct-a[0].at;
    float x=length-idle;
    float cpu=(float)x/(float)length;
    float tp=(float)n/(float)length;
    printf("\nAverage tat %0.2f",avgtat/n);
    printf("\nAverage wt %0.2f",avgwt/n);
    printf("\nAverage rt %0.2f",avgrt/n);
    printf("\nCycle time :%d",length);
    printf("\nIdle time is %d",idle);
    printf("\nCpu utilization is %0.2f",cpu*100,"%");
    printf("\nThroughput is :%0.2f",tp);
}