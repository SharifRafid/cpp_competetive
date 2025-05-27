#include <bits/stdc++.h>

using namespace std;

#define endl "\n";

int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif

    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    string s;
    cin >> s;

    bool first = true;
    bool last = false;
    for(size_t i=0; i<s.size()-1; i++){
        int a = i;
        int b = i+1;
        if(s[a] == s[b]){
            if(first){
                last = true;   
            }else{
                last = false;   
            }
            i++;
        }
        first = !first;
    }

    if(last == true){
        cout << "Yes" << endl;
    }else{
        cout << "No" << endl;
    }

    return 0;
}