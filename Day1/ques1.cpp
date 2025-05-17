#include <bits/stdc++.h>
using namespace std;

bool fun(int budget, vector<int> &arr)
{
    for (int price : arr)
    {
        if (price == budget)
        {
            return true;
        }
    }
    return false;
}

int main()
{
    int budget, n;
    cout << "Enter your budget: ";
    cin >> budget;

    cout << "Enter number of ice cream prices: ";
    cin >> n;

    vector<int> arr(n);
    cout << "Enter the prices:\n";
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    if (fun(budget, arr))
    {
        cout << "true\n";
    }
    else
    {
        cout << "false\n";
    }

    return 0;
}
