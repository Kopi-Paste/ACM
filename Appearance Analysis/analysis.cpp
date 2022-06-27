/* A */

#include <bits/stdc++.h>
using namespace std;

struct Window
{
    vector<string> data;
    Window()
    = default;


    void addString(string x)
    {
        data.push_back(x);
    }

    void print()
    {
        for(auto x : data)
            cout << x << endl;
    }

    int apply(unordered_set<string> & set) const
    {
        string normal = getNormal();
        string turn90 = get90();
        string turn180 = normal;
        string turn270 = turn90;
        reverse(turn180.begin(), turn180.end());
        reverse(turn270.begin(), turn270.end());

        if (set.find(normal) == set.end() && set.find(turn90) == set.end() && set.find(turn180)== set.end() && set.find(turn270) == set.end())
        {
            set.insert(normal);
            set.insert(turn90);
            set.insert(turn180);
            set.insert(turn270);

            return 1;
        }

        return 0;

    }

private:
    string getNormal() const
    {
        string retValue;
        for (auto & x : data)
            retValue += x;
        return retValue;
    }
    string get90() const
    {
        string retValue;
        int length = data[0].size();
        for (int i = length - 1; i >= 0; i--)
        {
            for (auto & x : data)
                retValue += x[i];
        }
        return retValue;
    }
};

int readInput(int height, int length)
{
    static const char delim = '#';
    string delimStr = string(length, delim);

    unordered_set<string> set;
    int retValue = 0;
    string input = string(length, 0);
    vector<Window> allWindows;
    vector<Window> currentWindows;
    bool newWindows = false;
    for (int i = 0; i < height; i++)
    {
        cin >> input;

        if (input == delimStr)
        {
            for (const auto& x : currentWindows)
                allWindows.push_back(x);
            currentWindows.clear();
            newWindows = true;
            continue;
        }


        int iter = -1;

        string constructed;

        for (auto x : input) {
            if (x == delim)
            {
                if (newWindows && constructed != "")
                    currentWindows.emplace_back();
                if (iter >= 0) {
                    currentWindows[iter].addString(constructed);
                    constructed = "";
                }
                iter++;
                continue;
            }
            constructed += x;
        }
        newWindows = false;
    }

    for (const auto& x : allWindows)
    {
        retValue += x.apply(set);
    }

    return retValue;
}


int main()
{
    int height;
    int length;
    cin >> height >> length;
    int results = readInput(height, length);
    cout << results;
    return 0;
}

