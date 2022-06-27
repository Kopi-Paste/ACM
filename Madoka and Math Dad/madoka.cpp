#include <bits/stdc++.h>

using namespace std;

void solve(int input)
{
    string base;
    bool begin = false;
    bool end = false;
    while (input >= 3)
    {
        base += "21";
        input -= 3;
    }
    end = input == 2;
    begin = input == 1;

    if (begin)
        cout << "1";
    cout << base;
    if (end)
        cout << "2";
    cout << endl;
}

int main()
{
    int tests;
    cin >> tests;
    for (int i = 0; i < tests; i++)
    {
        int input;
        cin >> input;
        solve(input);
    }
    return  0;
}