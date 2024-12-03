#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

map<pair<ll, ll>, ll> gcds;
map<pair<ll, ll>, ll> lcms;

ll gcd(ll a, ll b)
{
    ll cache = gcds[{a, b}];
    if (cache)
        return cache;
    cache = gcds[{b, a}];
    if (cache)
        return cache;
    while (b != 0)
    {
        a %= b;
        swap(a, b);
    }
    gcds[{a, b}] = a;
    return a;
}

ll lcm(ll a, ll b)
{
    ll cache = lcms[{a, b}];
    if (cache)
        return cache;
    cache = lcms[{b, a}];
    if (cache)
        return cache;
    cache = a / gcd(a, b) * b;
    lcms[{a, b}] = cache;
    return cache;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    ll a, b, l, r;
    cin >> a >> b >> l >> r;

    ll gcdl = l;
    if (l < a )
    {
        gcdl = a;
    }else {
        while(l%a != 0){
            
        }
    }
    ll ans = 0;
    while (gcdl <= r)
    {
        ll gcdl2 = gcdl;
        while (gcdl <= r)
        {
            if (lcm(gcdl, gcdl2) == b)
            {
                ans++;
            }
            gcdl2 += a;
        }
        gcdl += a;
    }

    cout << ans << endl;

    return 0;
}