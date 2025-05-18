#include <bits/stdc++.h>
using namespace std;

int fun(vector<int> &temps, int n)
{
    int count = 1;
    int maxi = 1;
    for (int i = 1; i < n; i++)
    {
        if (temps[i] > temps[i - 1])
        {
            count++;
            maxi = max(maxi, count);
        }
        else
        {
            count = 1;
        }
    }
    return maxi;
}
int main()
{
    int n;
    cout << "enter size of array :";
    cin >> n;
    vector<int> temps(n);
    for (int i = 0; i < n; i++)
    {
        cin >> temps[i];
    }
    int ans = fun(temps, n);
    cout << "max length is :" << ans << endl;
    return 0;
}