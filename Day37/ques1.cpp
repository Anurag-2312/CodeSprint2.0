#include <bits/stdc++.h>
using namespace std;

vector<string> below_20 = {"", "One", "Two", "Three", "Four", "Five", "Six", "Seven", "Eight", "Nine",
                           "Ten", "Eleven", "Twelve", "Thirteen", "Fourteen", "Fifteen",
                           "Sixteen", "Seventeen", "Eighteen", "Nineteen"};

vector<string> tens = {"", "", "Twenty", "Thirty", "Forty", "Fifty", "Sixty", "Seventy", "Eighty", "Ninety"};

vector<string> thousands = {"", "Thousand", "Million", "Billion"};

string fun(int num)
{
    if (num == 0)
        return "";
    else if (num < 20)
        return below_20[num] + " ";
    else if (num < 100)
        return tens[num / 10] + " " + fun(num % 10);
    else
        return below_20[num / 100] + " Hundred " + fun(num % 100);
}

string numtoword(int num)
{
    if (num == 0)
        return "Zero";

    string result = "";
    int i = 0;

    while (num > 0)
    {
        if (num % 1000 != 0)
        {
            string segment = fun(num % 1000);
            if (!thousands[i].empty())
                segment += thousands[i] + " ";
            result = segment + result;
        }
        num /= 1000;
        i++;
    }

    if (!result.empty() && result.back() == ' ')
        result.pop_back();

    return result;
}

int main()
{
    int num;
    cin >> num;
    string words = numtoword(num);
    cout << words << endl;
    return 0;
}
