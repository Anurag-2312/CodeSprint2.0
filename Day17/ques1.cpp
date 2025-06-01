#include <bits/stdc++.h>
using namespace std;

string reverse(string s)
{
    stack<char> st;
    for (char c : s)
    {
        st.push(c);
    }

    string reversed = "";
    while (!st.empty())
    {
        reversed += st.top();
        st.pop();
    }
    return reversed;
}

int main()
{
    string input;
    getline(cin, input);
    cout << reverse(input) << endl;
    return 0;
}
