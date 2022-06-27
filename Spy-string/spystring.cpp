#include <bits/stdc++.h>
using namespace std;
 
void addAll(unordered_map<string, int> & dict, string & input, int length)
{
    unordered_set<string> fromThis;
    for (int i = 0; i < length; i++)
    {
        for (char j = 'a'; j <= 'z'; j++)
        {
            string added = input;
            added[i] = j;
            fromThis.insert(added);
        }
    }
    for (auto x : fromThis)
    {
        auto index = dict.find(x);
        if (index == dict.end())
            dict[x] = 1;
        else
            dict[x] += 1;
    }
}
 
void solve()
{
    int strings, length;
    cin >> strings >> length;
 
    unordered_map<string, int> dictionary;
 
    string input;
 
 
    for (int i  = 0; i < strings; i++)
    {
        cin >> input;
        addAll(dictionary, input, length);
    }
    for (auto x : dictionary)
    {
        if (x.second == strings)
        {
            cout << x.first << endl;
            return;
        }
        
    }
    cout << -1 << endl;
}
 
int main()
{
    int test;
    cin >> test;
    for (int i = 0; i < test; i++)
        solve();
 
    return 0;
}