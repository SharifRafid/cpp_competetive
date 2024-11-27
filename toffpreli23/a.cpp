#include <bits/stdc++.h>

using namespace std;

int main()
{

    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int x, y;
    cin >> x >> y;

    long long int inp[x];
    for(int i=0;i<x;i++) cin >> inp[i];

    int sp = y-1;
    long long int cH = inp[sp];
    cout << cH;
    sp++;
    while(sp < x){
        if(inp[sp] >= cH){
            cout << " " << inp[sp];
            cH = inp[sp];
        }
        sp++;
    }
    cout << endl;
    
    int sp2 = y-1;
    long long int cH2 = inp[sp2];
    cout << cH2;
    sp2 --;
    while(sp2 >= 0){
        if(inp[sp2] <= cH2){
            cout << " " << inp[sp2];
            cH2 = inp[sp2];
        }
        sp2 --;
    }
    cout << endl;

    return 0;
}