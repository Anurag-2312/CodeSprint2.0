#include <bits/stdc++.h>
using namespace std;

int fun(vector<int> &arr, int k)
{
    int n = arr.size();
    vector<int> dp(n);
    dp[0] = arr[0];
    deque<int> dq;
    dq.push_back(0);

    for (int i = 1; i < n; ++i)
    {
        while (!dq.empty() && dq.front() < i - k)
            dq.pop_front();

        dp[i] = arr[i] + dp[dq.front()];

        while (!dq.empty() && dp[i] >= dp[dq.back()])
            dq.pop_back();

        dq.push_back(i);
    }
    return dp[n - 1];
}

int main()
{
    int n, k;
    cout << "Enter number of rooms: ";
    cin >> n;
    vector<int> arr(n);
    cout << "Enter room scores: ";
    for (int i = 0; i < n; ++i)
        cin >> arr[i];
    cout << "Enter maximum jump distance: ";
    cin >> k;

    int result = fun(arr, k);
    cout << "Maximum path score: " << result << endl;
    return 0;
}
