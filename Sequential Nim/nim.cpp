using namespace std;
#include <bits/stdc++.h>


void solve()
{
    bool firstWins = true;
    int piles;
    cin >> piles;

    deque<bool> bigger;
    int pile;

    for (int i  = 0; i < piles; i++)
    {
        cin >> pile;
        bigger.push_front(pile == 1);
    }

    bigger.pop_front();

    for (auto x : bigger)
    {
        if (x)
            firstWins = !firstWins;
        else
            firstWins = true;
    }

    cout << (firstWins ? "First" : "Second") << endl;
}

int main()
{
    int tests;
    cin >> tests;

    for (int i = 0; i < tests; ++i)
        solve();

    return 0;
}