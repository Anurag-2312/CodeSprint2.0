#include <bits/stdc++.h>
using namespace std;

vector<int> zigZagReorder(vector<int> &appointments)
{
    vector<int> result;
    int left = 0, right = appointments.size() - 1;

    while (left <= right)
    {
        if (left == right)
        {
            result.push_back(appointments[left]);
        }
        else
        {
            result.push_back(appointments[left]);
            result.push_back(appointments[right]);
        }
        left++;
        right--;
    }
    return result;
}

int main()
{
    int n;
    cout << "Enter number of appointments: ";
    cin >> n;

    vector<int> appointments(n);
    cout << "Enter appointment IDs: ";
    for (int i = 0; i < n; ++i)
    {
        cin >> appointments[i];
    }

    vector<int> reordered = zigZagReorder(appointments);

    cout << "Zig-Zag Reordered Appointments: ";
    for (int id : reordered)
    {
        cout << id << " ";
    }
    cout << endl;

    return 0;
}
