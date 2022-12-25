#include<stdio.h>
#include<stdbool.h>
typedef struct process 
{
    int pid , at , bt , st , ct , tat , wt , rt , rem_bt ;
}process;

int comp(const void *p,const void *q)
{
    int l=((struct process *)p)->at;
    int r=((struct process *)q)->at;
    return (l-r);
}
int findMax(int a,int b)
{
    return a>b?a:b ;
}
int main()
{
    int n , i , q ;
    printf("Enter No. of Process : ");
    scanf("%d",&n) ;
    process p[n] ;
    printf("Enter Pid AT BT \n");
    for(i=0;i<n;i++)
    {
        scanf("%d%d%d",&p[i].pid,&p[i].at,&p[i].bt);
        p[i].rem_bt = p[i].bt ;
    }
    printf("Enter Time Quanta : ");
    scanf("%d",&q) ;
    int queue[100] ;
    int front , rear ;
    bool visited[100] = {false} ;
    front = rear = 0 ;
    //Sorting on the basis of Arrival Time 
    qsort(p,n,sizeof(process),comp) ;
    printf("Pid\tAT\tBT\n");
    for(i=0;i<n;i++)
    {
        printf("P%d\t%d\t%d\n",p[i].pid,p[i].at,p[i].bt) ;
    }
    printf("\n");
    int curr_time = 0 , completed = 0 ;
    queue[rear] = 0 ;
    visited[0] = true ;
    int ind ;
    while(completed!=n)
    {
        ind = queue[front] ; 
        front++ ;
        if(p[ind].rem_bt == p[ind].bt)
        {
            p[ind].st = findMax(curr_time,p[ind].at) ;
            curr_time = p[ind].st ;
        }
        //visited[ind] = true ;
        if(p[ind].rem_bt - q >0)
        {
            p[ind].rem_bt -= q ;
            curr_time += q ;
        }
        else
        {
            int t = p[ind].rem_bt ;
            p[ind].rem_bt -= t ;
            curr_time += t ;
            completed ++ ;
            p[ind].ct = curr_time ; 
            p[ind].tat = p[ind].ct - p[ind].at ; 
            p[ind].wt  = p[ind].tat - p[ind].bt ; 
            p[ind].rt  = p[ind].st - p[ind].at ;
        }
        for(i=1;i<n;i++)
        {
            if(p[i].rem_bt>0 && p[i].at<=curr_time && visited[i]==false)
            {
                queue[++rear] = i ;
                visited[i] = true ;
            }
        }
        if(p[ind].rem_bt>0)
        {
            queue[++rear] = ind ;
        }
        if(front>rear) 
        {
            for(i=1;i<n;i++)
            {
                if(p[i].rem_bt>0)
                {
                    queue[++rear] = i ;
                    visited[i] = true ;
                    break ;
                }
            }
        }
    }
    printf("Pid\tAT\tBT\tCT\tTAT\tWT\tRT\n");
    for(i=0;i<n;i++)
    {
        printf("P%d\t%d\t%d\t%d\t%d\t%d\t%d\n",p[i].pid,p[i].at,p[i].bt,p[i].ct,p[i].tat,p[i].wt,p[i].rt) ;
    }
    return 0 ;
}