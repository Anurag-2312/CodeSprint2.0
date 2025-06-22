#include <bits/stdc++.h>
using namespace std;

int fun(int n, int k)
{
    if (n == 1)
        return 0;

    int mid = 1 << (n - 2);
    if (k <= mid)
        return fun(n - 1, k);
    else
        return 1 - fun(n - 1, k - mid);
}

int main()
{
    int n, k;
    cin >> n >> k;
    cout << fun(n, k) << endl;
    return 0;
}
