#include <bits/stdc++.h>
using namespace std;

string mapping[10] = {
    "", "", "abc", "def", "ghi", "jkl",
    "mno", "pqrs", "tuv", "wxyz"};

void generateCombinations(string digits, int index, string current, vector<string> &result)
{
    if (index == digits.length())
    {
        result.push_back(current);
        return;
    }

    string letters = mapping[digits[index] - '0'];
    for (char ch : letters)
    {
        generateCombinations(digits, index + 1, current + ch, result);
    }
}

int main()
{
    string digits;
    cout << "Enter digits : ";
    cin >> digits;

    vector<string> result;
    if (!digits.empty())
    {
        generateCombinations(digits, 0, "", result);
    }

    cout << "Possible combinations are:\n";
    for (string x : result)
    {
        cout << x << " ";
    }
    cout << endl;

    return 0;
}
