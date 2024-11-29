#include<bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t = 8;
    bool is = true;
    while(t--){
        int a;
        cin >> a;
        if(a < 60){
            is = false;
        }
    }
    if(is){
        cout << "Eligible" << endl;
    }else{
        cout << "Not Eligible" << endl;
    }

    return 0;
}