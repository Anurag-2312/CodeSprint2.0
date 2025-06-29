#include <bits/stdc++.h>
using namespace std;

vector<int> fun(vector<int> &nums)
{
    int n = nums.size();
    vector<int> left(n, 1), right(n, 1), result(n);

    for (int i = 1; i < n; i++)
        left[i] = left[i - 1] * nums[i - 1];

    for (int i = n - 2; i >= 0; i--)
        right[i] = right[i + 1] * nums[i + 1];

    for (int i = 0; i < n; i++)
        result[i] = left[i] * right[i];

    return result;
}

int main()
{
    int n;
    cin >> n;
    vector<int> nums(n);

    for (int i = 0; i < n; ++i)
        cin >> nums[i];

    vector<int> res = fun(nums);
    for (int val : res)
        cout << val << " ";
    cout << endl;

    return 0;
}
