#include <bits/stdc++.h>
using namespace std;
bool find(int j,int arr[],int n)
{
   for(int i=0;i<n;i++)
   {
    if(arr[i]==j)
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
    cout << "Enter total seeks :";
    cin >> n;
    cout << "Enter head : ";
    cin >> head;
    int arr[n];
    int total=0;
    int maxi=INT_MIN;
    vector<int>sequence;
    cout<<"Enter seeks :";
    for(int i=0;i<n;i++)
    {
        cin>>arr[i];
        maxi=max(maxi,arr[i]);
    }
    for(int i=head;i>=0;i--)
    {
        if(find(i,arr,n))
        {
            sequence.push_back(i);
        }
    }
    for(int i=0;i<200;i++)
    {
        if(find(i,arr,n) && i>head)
        {
            sequence.push_back(i);
        }
    }
    total=head+maxi;

    cout<<"Total seek distance is :"<<total<<endl;
    cout<<"Sequence is :";
    for(int j=0;j<sequence.size();j++)
    {
        cout<<sequence[j]<<" ";
    }
}