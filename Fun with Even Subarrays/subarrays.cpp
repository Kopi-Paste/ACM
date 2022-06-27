#include <bits/stdc++.h>

using namespace std;


vector<int> populateArray(int length)
{
    int input;
    vector<int> retValue;
    retValue.reserve(length);
    for (int i = length - 1; i >= 0; i--)
    {
        cin >> input;
        retValue[i] = input;
    }

    return retValue;
}

void solve()
{
    int length;
    cin >> length;
    vector<int> input = populateArray(length);

    int result = 0;
    int target = *(input.begin());

    for (int i = 0; i < length; i++)
    {
        if (input[i] != target)
        {
            result += 1;
            i *= 2;
            i -= 1;
        }
    }

    cout << result << endl;
}

int main()
{
    int test;
    cin >> test;
    for (int i = 0; i < test; i++)
        solve();

    return 0;
}