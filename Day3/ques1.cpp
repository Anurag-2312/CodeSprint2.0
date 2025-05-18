#include <bits/stdc++.h>
using namespace std;

int fun(vector<vector<int>> &mat, int n, int m)
{
    int overstocked = 0;
    for (int i = 0; i < n; i++)
    {
        int count = 0;
        for (int j = 0; j < m; j++)
        {
            if (mat[i][j] >= 100)
            {
                count++;
            }
        }
        if (count >= 3)
        {
            overstocked++;
        }
    }
    return overstocked;
}

int main()
{
    int n, m;
    cout << "enter no warehouse and no of units product type :";
    cin >> n >> m;

    vector<vector<int>> mat(n, vector<int>(m));
    cout << "enter the value :";
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> mat[i][j];
        }
    }
    int ans = fun(mat, n, m);
    cout << ans << endl;
    return 0;
}