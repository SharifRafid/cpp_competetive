#include <bits/stdc++.h>
using namespace std;

void solve(int &t)
{
    map<char, pair<int, bool>> m;
    while (t--)
    {
        char c;
        int x;
        string y;
        cin >> c >> x >> y;
        if (y == "correct")
        {
            if (!m[c].second)
            {
                m[c].first += x;
                m[c].second = true;
            }
        }
        else
        {
            m[c].first += 20;
        }
    }
    int ans = 0;
    int s = 0;
    for (auto i : m)
    {
        if (i.second.second)
        {
            ans += i.second.first;
            s ++;
        }
    }
    cout << s << " " << ans << endl;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    while (true)
    {
        int t;
        cin >> t;
        if (t == 0)
            break;
        solve(t);
    }
    return 0;
}