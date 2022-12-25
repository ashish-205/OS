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
    int temp=head;
    int arr[n];
    int maxi = 0;
    cout<<"Enter seeks :";
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
        maxi = max(maxi, arr[i]);
    }
    int total = 0;
    vector<int> visited(maxi + 1, 0);
    vector<int> sequence;

    for (int i = 0; i < n - 1; i++)
    {
        int diff = INT_MAX;
        bool flag = 0;
        for (int j = 0; j < n; j++)
        {
            if (abs(head - arr[j]) < diff && visited[arr[j]] == 0)
            {
                diff = abs(head - arr[j]);

                if (arr[j] > head)
                {
                    flag = 1;
                }
                else
                {
                    flag = 0;
                }
            }
        }
            if (flag == 1)
            {
                head = head + diff;
                visited[head] = 1;
            }
            else
            {
                head = head - diff;
                visited[head] = 1;
            }
            total += diff;
            sequence.push_back(head);
    }
        for (int i = 0; i < n; i++)
        {
            if (visited[arr[i]] == 0)
            {
                total = total + abs(head - arr[i]);
                sequence.push_back(arr[i]);
                break;
            }
        }
        cout << "Total seek distance is : " << total << endl;
        cout << "Sequence for seek distance is :"<<temp<<" ";
        for (int i = 0; i < sequence.size(); i++)
        {
            cout << sequence[i] << "  ";
        }
    }