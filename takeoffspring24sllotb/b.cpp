#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define endl "\n";

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int a;
    cin >> a;
    int ans=1;
    int cnt = __builtin_popcount(a);
    cout << cnt << endl;
    printf("%b\n", a);
    ans << cnt;
    printf("%b\n", ans);
    ans = (~ans);
    printf("%b\n", ans);
    cout << ans << endl;

    return 0;
}