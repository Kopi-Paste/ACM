#include <bits/stdc++.h>

using namespace std;

void minusOneCase(int nums, int max)
{
    if (max <= 3)
    {
        cout << "-1" << endl;
        return;
    }

    cout << max << " " << max - 1 << endl;
    cout << max - 2 << " " << 1 << endl;
    cout << 2 << " " << 0 << endl;

    int size = nums / 2;

    for (int i = 3; i < size; i++)
    {
        cout << i << " " << max - i << endl;
    }

}


void solve()
{
    int nums;
    int target;

    int loneNum = 0;

    cin >> nums >> target;

    int max = nums - 1;


    if (target == max)
    {
        minusOneCase(nums, max);
        return;
    }

    loneNum = max - target;

    cout << 0 << " " << loneNum << endl;
    if (target != 0)
        cout << max << " " << target << endl;
    int size = nums / 2;

    for (int i = 1; i < size; i++)
    {
        if (i == loneNum || i == target)
            continue;
        cout << i << " " << max - i << endl;
    }

}

int main()
{
    int tests;
    cin >> tests;
    for (int i = 0; i < tests; i++)
    {
        solve();
    }

    return 0;
}