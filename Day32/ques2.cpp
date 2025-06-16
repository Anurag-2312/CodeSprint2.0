#include <bits/stdc++.h>
using namespace std;

int search(vector<int> &nums, int target)
{
    int low = 0, high = nums.size() - 1;

    while (low <= high)
    {
        int mid = low + (high - low) / 2;

        if (nums[mid] == target)
            return mid;
        else if (nums[mid] < target)
            low = mid + 1;
        else
            high = mid - 1;
    }

    return low;
}

int main()
{
    int n, target;
    cout << "Enter the number of books: ";
    cin >> n;

    vector<int> nums(n);
    cout << "Enter the sorted book numbers: ";
    for (int i = 0; i < n; ++i)
        cin >> nums[i];

    cout << "Enter the new book number to insert: ";
    cin >> target;

    int result = search(nums, target);
    cout << "Correct position for the new book: " << result << endl;

    return 0;
}
