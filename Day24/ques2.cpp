#include <bits/stdc++.h>
using namespace std;

void reverse(queue<int> &q)
{
    stack<int> st;

    while (!q.empty())
    {
        st.push(q.front());
        q.pop();
    }

    while (!st.empty())
    {
        q.push(st.top());
        st.pop();
    }
}

int main()
{
    int n;
    cin >> n;
    queue<int> q;

    for (int i = 0; i < n; ++i)
    {
        int x;
        cin >> x;
        q.push(x);
    }

    reverse(q);

    while (!q.empty())
    {
        cout << q.front() << " ";
        q.pop();
    }

    cout << endl;
    return 0;
}
