#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n, target;
    cin >> n;
    vector<int> arr(n);
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    cin >> target;

    sort(arr.begin(), arr.end());
    int c_sum = INT_MAX;
    int mini = INT_MAX;

    for (int i = 0; i < n - 2; i++)
    {
        int left = i + 1, right = n - 1;
        while (left < right)
        {
            int sum = arr[i] + arr[left] + arr[right];
            int diff = abs(sum - target);

            if (diff < mini || (diff == mini && sum > c_sum))
            {
                mini = diff;
                c_sum = sum;
            }

            if (sum < target)
            {
                left++;
            }
            else
            {
                right--;
            }
        }
    }

    cout << c_sum << endl;
    return 0;
}
