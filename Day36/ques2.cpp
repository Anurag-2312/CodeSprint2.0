#include <bits/stdc++.h>
using namespace std;

int nCr(int n, int r)
{
    if (r == 0 || r == n)
        return 1;
    return nCr(n - 1, r - 1) + nCr(n - 1, r);
}

int main()
{
    int n, r;
    cin >> n >> r;
    cout << nCr(n, r) << endl;
    return 0;
}
