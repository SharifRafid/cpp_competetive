#include <bits/stdc++.h>
using namespace std;

void solve()
{
    int a;
    cin >> a;
    if(a%2 == 0 && a > 3){
        cout << "YES" << endl;
    }else{
        cout << "NO" << endl;
    }
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    solve();
    return 0;
}