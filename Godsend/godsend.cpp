using namespace std;
#include <bits/stdc++.h>

int main()
{
    int inputSize;
    cin >> inputSize;
    int input;
    for (int i = 0; i < inputSize; i++)
    {
        cin >> input;
        if (input & 1) {
            cout << "First" << endl;
            return 0;
        }
    }
    cout << "Second" << endl;
    return 0;
}

 