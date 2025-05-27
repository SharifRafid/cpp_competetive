#include <bits/stdc++.h>

using namespace std;

#define endl "\n";

void solve()
{
    int l1, r1, l2, r2;
    cin >> l1 >> r1 >> l2 >> r2;

    for(int a=l1; a<=r1; a++){
        for(int b=l2; b <= r2; b++){
            if(a !=b){
                cout << a << " " << b << endl;
                return;
            }
        }
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