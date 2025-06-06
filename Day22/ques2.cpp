#include <bits/stdc++.h>
using namespace std;

int fun(vector<int> &students, vector<int> &sandwiches)
{
    queue<int> q;
    for (int s : students)
        q.push(s);

    int index = 0, count = 0;
    int n = students.size();

    while (!q.empty())
    {
        if (q.front() == sandwiches[index])
        {
            q.pop();
            index++;
            count = 0;
        }
        else
        {
            q.push(q.front());
            q.pop();
            count++;
        }
        if (count == q.size())
            break;
    }

    return q.size();
}

int main()
{
    int n;
    cin >> n;
    vector<int> students(n), sandwiches(n);

    for (int i = 0; i < n; i++)
        cin >> students[i];
    for (int i = 0; i < n; i++)
        cin >> sandwiches[i];

    cout << fun(students, sandwiches) << endl;
    return 0;
}
