#include <bits/stdc++.h>

using namespace std;

void solve()
{
    int a;
    cin >> a;
    int cV = -1;
    int ans = 0;
    while (a--)
    {
        int n;
        cin >> n;
        if (cV == -1)
        {
            cV = n;
        }
        else
        {
            if (cV == n)
            {
                ans++;
                cV = -1;
            }
        }
    }
    cout << ans << endl;
    if (ans == 0)
    {
        cout << "Oh No" << endl;
    }
    else
    {
        if (ans % 2 == 0)
        {
            cout << "Yes" << endl;
        }
        else
        {
            cout << "No" << endl;
        }
    }
}

int main()
{
    int t;
    cin >> t;
    while (t--)
        solve();
}