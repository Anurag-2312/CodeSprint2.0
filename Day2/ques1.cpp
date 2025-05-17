#include <bits/stdc++.h>
using namespace std;

int fun(vector<int> &arr, int n)
{
    int count = 0;
    for (int i = 1; i < n - 1; i++)
    {
        if (arr[i] > arr[i - 1] && arr[i] > arr[i + 1])
        {
            count++;
        }
    }
    return count;
}

int main()
{
    int n;
    cout << "enter no of days: ";
    cin >> n;

    vector<int> arr(n);

    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    int ans = fun(arr, n);
    cout << "the number of magical days are :" << ans << endl;

    return 0;
}