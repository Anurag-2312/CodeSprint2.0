#include <bits/stdc++.h>
using namespace std;

bool cc(string a, string b)
{
    return a + b > b + a;
}

string fun(vector<int> &nums)
{
    vector<string> s;
    for (int num : nums)
        s.push_back(to_string(num));

    sort(s.begin(), s.end(), cc);

    if (s[0] == "0")
        return "0";

    string result;
    for (string x : s)
        result += x;

    return result;
}

int main()
{
    int n;
    cin >> n;

    vector<int> nums(n);
    for (int i = 0; i < n; i++)
        cin >> nums[i];

    cout << fun(nums) << endl;

    return 0;
}
