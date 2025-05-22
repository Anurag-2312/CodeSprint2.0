#include <bits/stdc++.h>
using namespace std;

int main()
{
    string log;
    cin >> log;
    int count = 0;

    for (int i = 0; i < log.length(); i++)
    {
        if (log[i] == '1' && (i == 0 || log[i - 1] == '0'))
        {
            count++;
        }
    }
    cout << count << endl;
    return 0;
}