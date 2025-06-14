#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin >> n;
    vector<int> arr(n);
    for (int i = 0; i < n; ++i)
    {
        cin >> arr[i];
    }

    int m;
    cin >> m;
    vector<int> nums(m);
    for (int i = 0; i < m; ++i)
    {
        cin >> nums[i];
    }

    int maxi = *max_element(nums.begin(), nums.end());

    int total = 0;
    for (int power : arr)
    {
        if (power <= maxi)
        {
            total += (maxi - power + 1);
        }
    }

    cout << total << endl;
    return 0;
}
