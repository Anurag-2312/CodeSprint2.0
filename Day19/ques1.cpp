#include <bits/stdc++.h>
using namespace std;

class minstack
{
private:
    stack<pair<int, int>> st;

public:
    void push(int val)
    {
        if (st.empty())
        {
            st.push({val, val});
        }
        else
        {
            st.push({val, min(st.top().second, val)});
        }
    }
    void pop()
    {
        st.pop();
    }
    string getmin()
    {
        if (st.empty())
        {
            cout << "empty" << endl;
        }
        else
        {
            return to_string(st.top().second);
        }
    }
};

int main()
{
    int n;
    cin >> n;
    cin.ignore();

    minstack ms;
    vector<string> ans;

    for (int i = 0; i < n; ++i)
    {
        string input;
        getline(cin, input);

        if (input.substr(0, 4) == "PUSH")
        {
            int val = stoi(input.substr(5));
            ms.push(val);
        }
        else if (input == "POP")
        {
            ms.pop();
        }
        else if (input == "MIN")
        {
            ans.push_back(ms.getmin());
        }
    }
    for (auto &res : ans)
    {
        cout << res << '\n';
    }

    return 0;
}