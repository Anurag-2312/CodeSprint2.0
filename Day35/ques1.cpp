#include <bits/stdc++.h>
using namespace std;

bool isvalid(vector<int> &parcels, int k, int maxwt)
{
    int load = 0, groups = 1;
    for (int wt : parcels)
    {
        if (wt > maxwt)
            return false;
        if (load + wt <= maxwt)
        {
            load += wt;
        }
        else
        {
            groups++;
            load = wt;
        }
    }
    return groups <= k;
}

int fun(vector<int> &arr, int k)
{
    int low = *max_element(arr.begin(), arr.end());
    int high = accumulate(arr.begin(), arr.end(), 0);

    while (low <= high)
    {
        int mid = (low + high) / 2;
        if (isvalid(arr, k, mid))
        {
            high = mid - 1;
        }
        else
        {
            low = mid + 1;
        }
    }
    return low;
}

int main()
{
    int n, k;
    cin >> n >> k;
    vector<int> arr(n);
    for (int i = 0; i < n; ++i)
    {
        cin >> arr[i];
    }

    cout << fun(arr, k) << endl;
    return 0;
}
