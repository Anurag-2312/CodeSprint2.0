#include <bits/stdc++.h>
using namespace std;

int fun(vector<int> &height)
{
    int n = height.size();
    if (n == 0)
        return 0;

    vector<int> leftmax(n), rightmax(n);
    leftmax[0] = height[0];
    for (int i = 1; i < n; i++)
    {
        leftmax[i] = max(leftmax[i - 1], height[i]);
    }

    rightmax[n - 1] = height[n - 1];
    for (int i = n - 2; i >= 0; i--)
    {
        rightmax[i] = max(rightmax[i + 1], height[i]);
    }

    int trapped = 0;
    for (int i = 0; i < n; i++)
    {
        trapped += min(leftmax[i], rightmax[i]) - height[i];
    }

    return trapped;
}

int main()
{
    int n;
    cin >> n;
    vector<int> height(n);
    for (int i = 0; i < n; i++)
    {
        cin >> height[i];
    }

    cout << fun(height) << endl;
    return 0;
}
