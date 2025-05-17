#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cout << "enter no of shots : ";
    cin >> n;

    vector<int> scores(n);
    int goodshots = 0, missedshots = 0;

    cout << "Enter the scores:\n";
    for (int i = 0; i < n; i++)
    {
        cin >> scores[i];
        if (scores[i] >= 7)
        {
            goodshots++;
        }
        else
        {
            missedshots++;
        }
    }

    cout << goodshots << " " << missedshots << endl;

    return 0;
}
