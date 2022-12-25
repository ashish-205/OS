#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    int head;
    cout << "Enter total seeks :";
    cin >> n;
    cout << "Enter head : ";
    cin >> head;
    int arr[n];
    int temp=head;
    int total=0;
    cout<<"Enter seeks :";
    for(int i=0;i<n;i++)
    {
        cin>>arr[i];
    }
    for(int i=0;i<n;i++)
    {
        total+=abs(head-arr[i]);
        head=arr[i];
    }
    cout<<"Total seek distance is :"<<total<<endl;
   cout<<"Sequence is :"<<temp<<" ";
    for(int j=0;j<n;j++)
    {
        cout<<arr[j]<<" ";
    }
    cout<<endl;
    

}