#include <bits/stdc++.h>
using namespace std;

vector<int> fun(vector<int> &arr, int n)
{
    queue<int> q;
    for (int i = 0; i < n; i++)
    {
        q.push(arr[i]);
    }

    vector<int> res;
    while (!q.empty())
    {
        res.push_back(q.front());
        q.pop();

        if (!q.empty())
        {
            int frontCard = q.front();
            q.pop();
            q.push(frontCard);
        }
    }

    return res;
}

int main()
{
    int n;
    cout << "Enter the number of cards: ";
    cin >> n;

    vector<int> arr(n);
    cout << "Enter card values:\n";
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    vector<int> ans = fun(arr, n);

    cout << "Revealed cards in order:\n";
    for (int card : ans)
    {
        cout << card << " ";
    }
    cout << "\n";

    return 0;
}
