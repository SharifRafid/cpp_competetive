#include <bits/stdc++.h>
using namespace std;

void solve(const int &t)
{
    string s;
    cin >> s;
    int left = 0;
    int count = 0;
    for(auto c:s){
        if(c == '<'){
            left ++;
        }else if(c == '>'){
            if(left > 0){
                left --;
                count ++;
            }
        }
    }
    cout << count << endl;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int t;
    cin >> t;
    while (t--)
    {
        solve(t);
    }
    return 0;
}