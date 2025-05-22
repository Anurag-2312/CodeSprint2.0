#include <bits/stdc++.h>
using namespace std;

int fun(vector<int> &stock, int n)
{
    int profit = 0;
    int mini = stock[0];

    for (int i = 1; i < n; i++)
    {
        int cost = stock[i] - mini;
        if (cost >= 2)
        {
            profit = max(profit, cost);
        }
        mini = min(mini, stock[i]);
    }
    return profit;
}

int main()
{
    int n;
    cout << "enter no of days : \n";
    cin >> n;
    vector<int> stock(n);
    for (int i = 0; i < n; i++)
    {
        cin >> stock[i];
    }

    cout << fun(stock, n) << endl;
    return 0;
}