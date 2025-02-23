#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define endl "\n";

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n, x;

    cin >> n >> x;

    int bc = 0;

    int cr, pr;
    for (int i = 0; i < n; i++)
    {
        cin >> cr;
        if (i == 0)
        {
            pr = cr;
        }
        else
        {
            if (cr < pr)
            {
                int diff = pr - cr;
                if (diff > x)
                {
                    int ab = diff - x;
                    int tbgc = (x + (ab * 2));
                    x = 0;
                    bc += tbgc;
                    pr = cr+diff;
                }
                else
                {
                    x -= diff;
                    bc += diff;
                    pr = cr+diff;
                }
            }else{
                pr = cr;
            }
        }
    }

    cout << bc << endl;

    return 0;
}