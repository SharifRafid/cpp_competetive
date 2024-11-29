#include<bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int i;
    cin >> i;
    cin.ignore();
    int num = 0;
    while(i--){
        char c;
        cin >> c;
        if(isdigit(c)){
            int d = c-'0';
            num += d;
        }
    }
    if(num%3 == 0){
        cout << "YES" << endl;
    }else{
        cout << "NO" << endl;
    }

    return 0;
}