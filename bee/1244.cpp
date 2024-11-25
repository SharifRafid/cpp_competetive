#include <bits/stdc++.h>

using namespace std;

bool customComparator(const string &s1, const string &s2)
{
    return s1.length() > s2.length();
}

void solve()
{
    string line;
    getline(cin, line);
    stringstream stream(line);
    string temp;
    vector<string> items;
    while (stream >> temp)
    {
        items.push_back(temp);
    }
    stable_sort(items.begin(), items.end(), customComparator);
    for (size_t i = 0; i < items.size(); ++i)
    {
        if (i != 0)
            cout << " ";
        cout << items[i];
    }
    cout << endl;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int t;
    cin >> t;
    cin.ignore();
    while (t--)
        solve();

    return 0;
}