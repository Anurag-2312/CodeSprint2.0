#include <bits/stdc++.h>
using namespace std;

int main()
{
    string s;
    cin >> s;

    set<pair<int, int>> st;
    int x = 0, y = 0;
    st.insert({x, y});
    int count = 0;

    for (char ch : s)
    {
        if (ch == 'L')
            x--;
        else if (ch == 'R')
            x++;
        else if (ch == 'U')
            y++;
        else if (ch == 'D')
            y--;

        // pair<int, int> pos = {x, y};
        if (st.count({x, y}))
            count++;
        else
            st.insert({x, y});
    }

    cout << count << endl;
    return 0;
}
