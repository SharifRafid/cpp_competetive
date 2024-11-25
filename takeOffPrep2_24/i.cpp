#include <bits/stdc++.h>

using namespace std;

int main()
{

    int n;
    cin >> n;
    set<long> nms;
    while(n--){
        long x;
        cin >> x;
        if(nms.erase(x) == 0){
            nms.insert(x);
        }
    }
    cout << nms.size() << endl;
    return 0;
}