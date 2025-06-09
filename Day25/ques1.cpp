#include <bits/stdc++.h>
using namespace std;

bool fun(vector<int> &arr, int target)
{
    int n = arr.size();
    sort(arr.begin(), arr.end());

    for (int i = 0; i < n - 2; i++)
    {
        int left = i + 1;
        int right = n - 1;

        while (left < right)
        {
            int sum = arr[i] + arr[left] + arr[right];
            if (sum == target)
                return true;
            else if (sum < target)
                left++;
            else
                right--;
        }
    }
    return false;
}

int main()
{
    int n, target;
    cin >> n;

    vector<int> arr(n);
    for (int i = 0; i < n; i++)
        cin >> arr[i];

    cin >> target;

    if (fun(arr, target))
        cout << "true\n";
    else
        cout << "false\n";

    return 0;
}
