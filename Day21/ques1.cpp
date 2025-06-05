#include <bits/stdc++.h>
using namespace std;

int fun(vector<int> &arr, int k)
{
    int time = 0;
    for (int i = 0; i < arr.size(); ++i)
    {
        if (i <= k)
            time += min(arr[i], arr[k]);
        else
            time += min(arr[i], arr[k] - 1);
    }
    return time;
}

int main()
{
    int n, k;
    cout << "Enter number of people in the queue: ";
    cin >> n;

    vector<int> arr(n);
    cout << "Enter number of tickets each person wants: ";
    for (int i = 0; i < n; ++i)
    {
        cin >> arr[i];
    }

    cout << "Enter the position of the target person: ";
    cin >> k;

    cout << "Time required: " << fun(arr, k) << endl;
    return 0;
}
