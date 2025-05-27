#include <bits/stdc++.h>

using namespace std;

#define endl "\n";

void solve()
{
    int b, p, f, h, c;
    cin >> b >> p >> f;
    cin >> h >> c;

    int profit = 0;
    if (h > c)
    {
        if (b >= (p*2))
        {
            profit += p * h;
            b -= (p*2);
            if (b >= (f*2))
            {
                profit += f * c;
                b -= (f*2);
            }
            else
            {
                profit += (b/2) * c;
            }
        }
        else
        {
            profit += (b/2) * h;
            b = 0;
        }
    }
    else
    {
        if (b >= (f*2))
        {
            profit += f * c;
            b -= (f*2);
            if (b >= (p*2))
            {
                profit += p * h;
                b -= (p*2);
            }
            else
            {
                profit += (b/2) * h;
                b = 0;
            }
        }
        else
        {
            profit += (b/2) * c;
        }
    }

    cout << profit << endl;
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