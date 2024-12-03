#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    ll n, x, m, y;
    cin >> n >> x >> m >> y;

    ll maxAm = 0;

    maxAm = n/x;

    maxAm = max(maxAm, (n/y)*m);

    for(ll p=0,pc=0,pt=0; p<=n/y; p++,pc+=m,pt+=y){
        maxAm = max(maxAm, (pc+((n-pt)/x)));
    }

    cout << maxAm << endl;

    return 0;
}