#include <bits/stdc++.h>
using namespace std;

vector<bool> fun(int n)
{
    vector<bool> isprime(n + 1, true);
    isprime[0] = isprime[1] = false;
    for (int i = 2; i * i <= n; i++)
    {
        if (isprime[i])
        {
            for (int j = i * i; j <= n; j += i)
                isprime[j] = false;
        }
    }
    return isprime;
}

int main()
{
    int n;
    cin >> n;

    vector<bool> isprime = fun(n);
    vector<int> arr;

    for (int i = 2; i <= n; i++)
    {
        if (isprime[i])
            arr.push_back(i);
    }

    vector<bool> indexprime = fun(arr.size());

    for (int i = 0; i < arr.size(); i++)
    {
        if (indexprime[i + 1])
        {
            cout << arr[i] << " ";
        }
    }

    return 0;
}
