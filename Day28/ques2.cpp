#include <bits/stdc++.h>
using namespace std;

int fun(vector<int> &arr, int power)
{
    sort(arr.begin(), arr.end());
    int score = 0, maxscore = 0;
    int left = 0, right = arr.size() - 1;

    while (left <= right)
    {
        if (power >= arr[left])
        {
            power -= arr[left++];
            score++;
            maxscore = max(maxscore, score);
        }
        else if (score >= 1)
        {
            power += arr[right--];
            score--;
        }
        else
        {
            break;
        }
    }
    return maxscore;
}
int main()
{
    int n, power;
    cout << "Enter number of tokens: ";
    cin >> n;

    vector<int> arr(n);
    cout << "Enter the token values: ";
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    cout << "Enter initial power: ";
    cin >> power;
    cout << "Output: " << fun(arr, power) << endl;
    return 0;
}
