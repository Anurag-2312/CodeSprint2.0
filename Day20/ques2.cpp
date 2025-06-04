#include <bits/stdc++.h>
using namespace std;

vector<int> fun(const vector<int> &arr)
{
    int n = arr.size();
    vector<int> nge(n, -1);
    vector<int> result(n, -1);
    stack<int> st;

    for (int i = n - 1; i >= 0; i--)
    {
        while (!st.empty() && arr[st.top()] <= arr[i])
        {
            st.pop();
        }
        if (!st.empty())
        {
            nge[i] = st.top();
        }
        st.push(i);
    }

    for (int i = 0; i < n; i++)
    {
        int idx = nge[i];
        if (idx != -1)
        {
            for (int j = idx + 1; j < n; j++)
            {
                if (arr[j] < arr[idx])
                {
                    result[i] = arr[j];
                    break;
                }
            }
        }
    }
    return result;
}

int main()
{
    int n;
    cin >> n;
    vector<int> arr(n);
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    vector<int> ans = fun(arr);
    for (int x : ans)
    {
        cout << x << " ";
    }
    cout << endl;

    return 0;
}
