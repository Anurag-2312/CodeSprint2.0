#include <bits/stdc++.h>
using namespace std;

int missing(vector<int> &nums)
{
    int n = nums.size();
    int expectedsum = n * (n + 1) / 2;
    int actualsum = 0;

    for (int num : nums)
        actualsum += num;

    return expectedsum - actualsum;
}

int main()
{
    int n;
    cout << "Enter the number of badges : ";
    cin >> n;

    vector<int> nums(n);
    cout << "Enter the badge numbers: ";
    for (int i = 0; i < n; ++i)
        cin >> nums[i];

    int result = missing(nums);
    cout << "Missing badge number: " << result << endl;

    return 0;
}
