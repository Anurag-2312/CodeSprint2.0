#include <iostream>
#include <stack>
#include <string>
using namespace std;

bool isvalid(string s)
{
    stack<char> st;
    for (char c : s)
    {
        if (c == '(' || c == '{' || c == '[')
        {
            st.push(c);
        }
        else
        {
            if (st.empty())
                return false;
            char ch = st.top();
            st.pop();
            if ((c == ')' && ch != '(') ||
                (c == '}' && ch != '{') ||
                (c == ']' && ch != '['))
            {
                return false;
            }
        }
    }
    return st.empty();
}

int main()
{
    string s;
    cout << "Enter bracket string: ";
    cin >> s;

    if (isvalid(s))
        cout << "true" << endl;
    else
        cout << "false" << endl;

    return 0;
}
