#include <bits/stdc++.h>
using namespace std;

vector<int> fun(vector<int> &nums)
{
    int n = nums.size();
    vector<int> result(n);
    int left = 0, right = n - 1, pos = n - 1;

    while (left <= right)
    {
        int leftsq = nums[left] * nums[left];
        int rightsq = nums[right] * nums[right];

        if (leftsq > rightsq)
        {
            result[pos--] = leftsq;
            left++;
        }
        else
        {
            result[pos--] = rightsq;
            right--;
        }
    }

    return result;
}

int main()
{
    int n;
    cin >> n;

    vector<int> nums(n);
    for (int i = 0; i < n; ++i)
    {
        cin >> nums[i];
    }

    vector<int> result = fun(nums);

    for (int num : result)
    {
        cout << num << " ";
    }
    cout << endl;

    return 0;
}
