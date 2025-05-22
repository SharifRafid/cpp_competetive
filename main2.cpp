// Problem E Backup

#include <bits/stdc++.h>

using namespace std;

#define endl "\n"
typedef long long ll;

void file()
{
#ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif
}

void solve(ll t)
{
    int n;
    cin >> n;
    int rem = 0;//2
    int ans = 0;//8
    while(n>=3){
        ans += n;
        n+=rem;
        rem = n%3;
        n /= 3;
    }
    ans += n; // Not Empty
    n += rem; // Empty
    cout << n << " "<< ans << endl;
    if(n==2) ans++;
    cout << ans << endl;
}

int main()
{
    file();
    // ll t;
    // cin >> t;
    // for(ll i=1;i<=t;i++) 
    solve(0);

    return 0;
}
