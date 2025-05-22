// P backup

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

void solve(int t)
{
    int n;
    cin >> n;
    if(n<0) return;
    if(n<=3) {
        cout << n << endl;
        return;
    }
    string s = "";
    while(n>0){
        s.append(to_string(n%3));
        n /= 3;
    }
    reverse(s.begin(), s.end());
    cout << s << endl;
    solve(0);   
}

int main()
{
    file();
    // int t;
    // cin >> t;
    // for (int i = 1; i <= t; i++)
    solve(0);
    return 0;
}
