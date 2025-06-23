#include <bits/stdc++.h>
using namespace std;

int fun(int n, int index = 0)
{
    if (index == n)
        return 1;

    int choices = (index % 2 == 0) ? 5 : 4;
    return choices * fun(n, index + 1);
}

int main()
{
    int n;
    cin >> n;

    int result = fun(n);
    cout << result << endl;

    return 0;
}
