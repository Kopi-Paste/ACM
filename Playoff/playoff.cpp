#include <bits/stdc++.h>

using namespace std;

void solve(int ex)
{
    int res = pow(2, ex) - 1;
    cout << res << endl;
}

int main()
{
    int test;
    cin >> test;
    for (int i = 0; i < test; i++) {

        int input;
        cin >> input;
        solve(input);
    }

    return 0;
}