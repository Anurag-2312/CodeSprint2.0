#include <bits/stdc++.h>
using namespace std;

bool fun(vector<int> &v, vector<int> &p)
{
    sort(v.begin(), v.end());
    sort(p.begin(), p.end());

    int n = v.size();
    int i = 0, j = 0;

    while (i < n && j < n)
    {
        if (v[i] > p[j])
        {

            i++;
            j++;
        }
        else
        {

            i++;
        }
    }

    return j == n;
}

int main()
{
    int n;
    cin >> n;

    vector<int> v(n), p(n);
    for (int i = 0; i < n; ++i)
    {
        cin >> v[i];
    }
    for (int i = 0; i < n; ++i)
    {
        cin >> p[i];
    }

    if (fun(v, p))
    {
        cout << "Yes\n";
    }
    else
    {
        cout << "No\n";
    }

    return 0;
}
