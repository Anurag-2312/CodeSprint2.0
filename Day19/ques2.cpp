#include <bits/stdc++.h>
using namespace std;

class stackfrequency
{
private:
    stack<string> st;
    unordered_map<string, int> freq;

public:
    void push(const string &val)
    {
        st.push(val);
        freq[val]++;
    }

    void pop()
    {
        if (!st.empty())
        {
            string top = st.top();
            st.pop();
            freq[top]--;
            if (freq[top] == 0)
            {
                freq.erase(top);
            }
        }
    }

    string count()
    {
        if (st.empty())
            return "EMPTY";
        return to_string(freq[st.top()]);
    }
};

int main()
{
    int n;
    cin >> n;
    cin.ignore();

    stackfrequency sf;
    vector<string> results;

    for (int i = 0; i < n; ++i)
    {
        string command;
        getline(cin, command);

        if (command.substr(0, 4) == "PUSH")
        {
            string val = command.substr(5);
            sf.push(val);
        }
        else if (command == "POP")
        {
            sf.pop();
        }
        else if (command == "COUNT")
        {
            results.push_back(sf.count());
        }
    }

    for (string res : results)
    {
        cout << res << endl;
    }

    return 0;
}
