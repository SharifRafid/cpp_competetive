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

    int n,k;
    cin >> n >> k;

    vector<int> a(n);
    for(int i=0; i<n; i++){
        cin >> a[i];
    }
    // sort(a.rbegin(), a.rend());
    int count = 0; 
    for(int i=0; i<n; i++){
        if(a[i] >= a[k-1] && a[i] > 0){
            count ++;
        }
    }

    cout << count << endl;



    return 0;
}