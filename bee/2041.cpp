#include <bits/stdc++.h>
using namespace std;

vector<string> items = {"3"};

void makeArray()
{
    string init = "3";
    int ct = 0;
    while (ct <= 40)
    {
        size_t t = 0;
        string ns = "";
        while (t < init.size())
        {
            size_t t2 = t;
            while (init[t] == init[t2])
            {
                if (++t2 >= init.size())
                {
                    break;
                }
            }
            size_t count = t2 - t;
            ns += to_string(count) + init[t];
            t += count;
        }
        init = ns;
        items.push_back(ns);
        ct++;
    }
}

int solve()
{
    string line;
    getline(cin, line);
    if (line.empty())
        return -1;
    stringstream ss(line);
    int temp;
    while (ss >> temp)
        cout << items[temp-1] << endl;
    return 0;
}

int main()
{

    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    makeArray();

    // int t;
    // cin >> t;
    while (true)
        if (solve() == -1)
            break;

    return 0;
}