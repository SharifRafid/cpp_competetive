#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int a;
    cin >> a;

    vector<long long> s;
    while (a--)
    {
        long long x;
        cin >> x;
        s.push_back(x);
    }
    sort(s.begin(), s.end());
    reverse(s.begin(), s.end());
    for (auto sv : s)
    {
        if (sv != s[0])
        {
            cout << sv << endl;
            return 0;
        }
    }
    cout << -1 << endl;

    return 0;
}