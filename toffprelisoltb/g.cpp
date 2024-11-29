#include<bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    long long a,b;
    cin >> a >> b;
    long long ar[a];
    for(int i=0;i<a;i++){
        long long j;
        cin >> j;
        ar[i] = j;
    }
    long long sum = 0;
    for(int i=0;i<a;i++){
        sum = 0;
        for(int j=i;j<i+b;j++){
            if(j==a){
                break;
            }
            sum += ar[j];
            
        }
        if(i!=0){
            cout << " ";
        }
        cout << max(ar[i],sum);
    }
    cout << endl;
    return 0;
}