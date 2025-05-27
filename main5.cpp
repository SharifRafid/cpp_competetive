#include <bits/stdc++.h>

using namespace std;

#define endl "\n";

void solve()
{
    long long n, x, y, d;
    cin >> n >> x >> y >> d;
    vector<int> anss;
    if (abs(x - y) % d == 0)
    {
        anss.push_back(abs(x - y) / d);
    }
    if (abs(n - y) % d == 0)
    {
        long long div = abs(x - n) / d;
        if (abs(x - n) % d != 0)
        {
            div++;
        }
        anss.push_back(((div) + (abs(n - y) / d)));
    }
    if (abs(1 - y) % d == 0)
    {
        long long div = x / d;
        if (x % d != 0)
        {
            div++;
        }
        anss.push_back(((div) + (abs(1 - y) / d)));
    }
    if(anss.size() == 0){
        cout << -1 << endl;
    }else{
        sort(anss.begin(), anss.end());
        cout << anss[0] << endl;
    }

}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif

    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int t;
    cin >> t;
    while (t--)
        solve();

    return 0;
}