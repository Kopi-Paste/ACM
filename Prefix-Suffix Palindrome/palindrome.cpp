#include <bits/stdc++.h>

using namespace std;

string findLongest(const string & a, const string & b)
{
    static const unsigned long long int modulus1 = 92821;
    static const unsigned long long int modulus2 = 402653189;
    static const unsigned long long int base = 29;

    unsigned long long int hash11 = 0;
    unsigned long long int hash12 = 0;
    unsigned long long int hash21 = 0;
    unsigned long long int hash22 = 0;

    string retValue;
    size_t size = a.size();
    size_t i;

    size_t max = 0;

    unsigned long long int base1 = 1;
    unsigned long long int base2 = 1;

    bool fromStart = true;

    for (i = 0; i < size; i++)
    {
        hash11 += (a[i] * base1) % modulus1;
        hash12 += (a[i] * base2) % modulus2;


        hash11 %= modulus1;
        hash12 %= modulus2;


        hash21 *= base;
        hash21 %= modulus1;


        hash22 *= base;
        hash22 %= modulus2;


        hash21 += b[size - 1 - i] % modulus1;
        hash22 += b[size - 1 - i] % modulus2;


        hash21 %= modulus1;
        hash22 %= modulus2;


        if (hash11 == hash21 && hash12 == hash22 && (i + 1) > max)
        {
            max = i + 1;
            fromStart = true;
        }
        base1 *= base;
        base1 %= modulus1;
        base2 *= base;
        base2 %= modulus2;
    }

    hash11 = 0;
    hash12 = 0;
    hash21 = 0;
    hash22 = 0;

    base1 = 1;
    base2 = 1;

    for (i = 0; i < size; i++)
    {
        hash11 += (b[i] * base1) % modulus1;
        hash12 += (b[i] * base2) % modulus2;


        hash11 %= modulus1;
        hash12 %= modulus2;


        hash21 *= base;
        hash21 %= modulus1;


        hash22 *= base;
        hash22 %= modulus2;


        hash21 += a[size - 1 - i] % modulus1;
        hash22 += a[size - 1 - i] % modulus2;


        hash21 %= modulus1;
        hash22 %= modulus2;


        if (hash11 == hash21 && hash12 == hash22 && (i + 1) > max)
        {
            max = i + 1;
            fromStart = false;
        }
        base1 *= base;
        base1 %= modulus1;
        base2 *= base;
        base2 %= modulus2;
    }

    retValue = fromStart ? a.substr(0, max) : b.substr(0, max);
    return retValue;
}

void solve()
{
	string input;
	cin >> input;
    string inputRev = input;
    size_t size = input.size();
    reverse(inputRev.begin(), inputRev.end());
    size_t firstHalf = (size - 1) / 2;
    string base;
    size_t i;
    for (i = 0; i < firstHalf; i++)
    {
        if (input[i] == inputRev[i])
            base.push_back(input[i]);
        else
            break;
    }
    string baseRev = base;
    reverse(baseRev.begin(), baseRev.end());
    //cout << input.substr(i, size - i * 2) << endl;
    //cout << inputRev.substr(i, size - i * 2) << endl;
    cout << base << findLongest(input.substr(i, size - i * 2), inputRev.substr(i, size - i * 2)) << baseRev << endl;
}

int main()
{
	int tests;
	cin >> tests;
	for (int i = 0; i < tests; i++)
		solve();
	return 0;
}