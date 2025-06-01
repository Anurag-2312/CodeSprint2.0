#include <bits/stdc++.h>
using namespace std;

bool isoperator(char c)
{
    return (c == '+' || c == '-' || c == '*' || c == '/');
}

string postfixtoprefix(string postfix)
{
    stack<string> st;
    for (char ch : postfix)
    {
        if (isoperator(ch))
        {
            string op2 = st.top();
            st.pop();
            string op1 = st.top();
            st.pop();
            string expr = ch + op1 + op2;
            st.push(expr);
        }
        else
        {
            st.push(string(1, ch));
        }
    }
    return st.top();
}

int main()
{
    string postfix;
    cin >> postfix;
    cout << postfixtoprefix(postfix) << endl;
    return 0;
}
