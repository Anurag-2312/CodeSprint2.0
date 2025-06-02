#include <bits/stdc++.h>
using namespace std;

int fun(vector<string> &arr)
{
    stack<int> st;
    for (string &s : arr)
    {
        if (s == "+" || s == "-" || s == "*" || s == "/")
        {
            int b = st.top();
            st.pop();
            int a = st.top();
            st.pop();
            if (s == "+")
                st.push(a + b);
            else if (s == "-")
                st.push(a - b);
            else if (s == "*")
                st.push(a * b);
            else
                st.push(a / b);
        }
        else
        {
            st.push(stoi(s));
        }
    }
    return st.top();
}

int main()
{
    int n;
    cout << "Enter number of elements: ";
    cin >> n;

    vector<string> arr(n);
    cout << "Enter postfix exp : ";
    for (int i = 0; i < n; ++i)
    {
        cin >> arr[i];
    }

    int result = fun(arr);
    cout << "Output: " << result << endl;

    return 0;
}
