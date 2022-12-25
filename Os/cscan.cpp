#include <bits/stdc++.h>
using namespace std;
bool find(int j,int arr[],int n,int head)
{
   for(int i=0;i<n;i++)
   {
    if(arr[i]==j && arr[i]>head)
    {
        return true;
    }
   }
   return false;
}
bool find1(int j,int arr[],int n,int head)
{
   for(int i=0;i<n;i++)
   {
    if(arr[i]==j && arr[i]<head)
    {
        return true;
    }
   }
   return false;
}
int main()
{
   int n;
   int head;
   cout<<"Enter total seeks :";
   cin>>n;
   cout<<"Enter head pointer :";
   cin>>head;
    int total=0;
   int arr[n];
   cout<<"Enter seeks :";
   for(int i=0;i<n;i++)
   {
    cin>>arr[i];
   }
   vector<int>sequence;
  int tracks;
  cout<<"Enter total tracks : ";
  cin>>tracks;
   for(int j=head;j<=tracks;j++)
   {
        if(find(j,arr,n,head))
        {
            sequence.push_back(j);
        }
   }
   int x=0;
   for(int i=0;i<head;i++)
   {
     if(find1(i,arr,n,head))
     {
        sequence.push_back(i);
        x=i;
     }
   }

   total=(tracks-head)+tracks+x;
   cout<<"Total seek distance is :"<<total<<endl;

   cout<<"Sequence is : ";
   for(int i=0;i<sequence.size();i++)
   {
    cout<<sequence[i]<<" ";
   }

}