#include<bits/stdc++.h>

using namespace std;

int main(){

    string a, b;
    
    cin >> a >> b;

    int t = 0;
    int cDiff = 0;
    bool is = true;
    while(t < a.length()){
        int v1 = a[t] - 96;
        int v2 = b[t] - 96;
        int nDiff = abs(v1-v2);
        if(nDiff != 0){
            if(cDiff == 0){
                cDiff = nDiff;
            }else{
                int sum = v1 + cDiff;
                if(sum > 26){
                    sum = sum % 26;
                }
                if(sum != v2){
                    is = false;
                }
            }
        }
        t ++;
    }

    if(is){
        cout << "Yes" << endl;
    }else{
        cout << "No" << endl;
    }

    return 0;
}