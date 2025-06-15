#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin >> n;
    vector<string> arr(n);

    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    for (int i = 0; i < n; i++)
    {
        int count = 0;
        for (int j = 0; j < i; j++)
        {
            if (arr[j] < arr[i])
            {
                count++;
            }
        }
        cout << count << endl;
    }

    return 0;
}
