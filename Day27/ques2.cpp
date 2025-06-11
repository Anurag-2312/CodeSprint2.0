#include <bits/stdc++.h>
using namespace std;

vector<int> fun(vector<int> &nums)
{
    int n = nums.size();
    set<int> s;
    int duplicate = -1, total = 0;

    for (int num : nums)
    {
        if (s.find(num) != s.end())
        {
            duplicate = num;
        }
        s.insert(num);
        total += num;
    }

    int exp_sum = n * (n + 1) / 2;
    int missing = exp_sum - (total - duplicate);

    return {duplicate, missing};
}

int main()
{
    int n;
    cout << "Enter number of codes: ";
    cin >> n;

    vector<int> nums(n);
    cout << "Enter the codes: ";
    for (int i = 0; i < n; ++i)
        cin >> nums[i];

    vector<int> result = fun(nums);

    cout << "Duplicate code: " << result[0] << endl;
    cout << "Missing code: " << result[1] << endl;

    return 0;
}
