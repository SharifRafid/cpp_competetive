#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    ll n,x,m,y;
    cin >> n >> x >> m >> y;

    ll max = 0;
    if(n >= y){
        ll i, cy=m;
        for(i=y; i<=n; i+=y){
            ll rem = n-i, cx=0;
            if(rem >= x){
                cx = rem/x;
            }
            cx+=cy; // CX using as a sum
            if(cx > max){
                max = cx;
            }
            cy+=m;
        }
    }else if(n >= x){
        max = n/x;
    }

    cout << max << endl;
    
    return 0;
}