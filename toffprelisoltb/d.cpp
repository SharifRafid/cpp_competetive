#include<bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    long long n,x,m,y;
    cin >> n >> x >> m >> y;
    int pa = ((n / y) * 3);
    if(n % y != 0){
        pa += ((n % y)/x);
    }
    int tot = n/x;
    if(n%x!=0){
        tot += (((n%x)/y)*m);
        if(((n%x)%y) != 0){
            
        }
    }

    if(pa > tot){
        cout << pa << endl;
    }else{
        cout << tot << endl;
    }
    return 0;
}