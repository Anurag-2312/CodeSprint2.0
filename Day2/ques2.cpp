#include <bits/stdc++.h>
using namespace std;

int fun(vector<int> &arr, int n)
{
    int count = 0;

    for (int i = 1; i < n; i++)
    {
        if (arr[i] >= 50 && arr[i] > arr[i - 1])
        {
            count++;
        }
    }
    return count;
}

int main()
{
    int n;
    cout << "enter no of hours: ";
    cin >> n;

    vector<int> arr(n);
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    int ans = fun(arr, n);
    cout << "the no of critical jam hours are:" << ans << endl;
    return 0;
}