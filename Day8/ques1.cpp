#include <bits/stdc++.h>
using namespace std;

int fun(vector<int> &arr, int n, int target)
{
    int l = 0, r = 0, sum = 0;
    int len = INT_MAX;
    while (r < n)
    {
        sum += arr[r];
        while (sum >= target)
        {
            len = min(len, r - l + 1);
            sum -= arr[l];
            l++;
        }
        r++;
    }
    if (len == INT_MAX)
    {
        return 0;
    }
    return len;
}
int main()
{
    int n, target;
    cout << "enter array size :";
    cin >> n;
    cout << "enter target :";
    cin >> target;

    vector<int> arr(n);
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    cout << fun(arr, n, target) << endl;
    return 0;
}