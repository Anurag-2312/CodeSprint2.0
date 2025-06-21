#include <bits/stdc++.h>
using namespace std;

bool check(int n)
{
    if (n <= 0)
        return false;
    if (n == 1)
        return true;
    if (n % 2 != 0)
        return false;
    return check(n / 2);
}

int main()
{
    int n;
    cin >> n;
    cout << (check(n) ? "true" : "false") << endl;
    return 0;
}
