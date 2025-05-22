// Q Bakcup
#include <bits/stdc++.h>

using namespace std;

#define endl "\n"
typedef long long ll;

void file()
{
#ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif
}

void solve(int t)
{
    string s;
    cin >> s;
    string ans;
    for(char c:s){
        if(ans.length()==0){
            ans.push_back(c);
        }else{
            if(c == ']'){
                if(ans[ans.length()-1] == '['){
                    ans.pop_back();
                    continue;
                }
            }else if(c == ')'){
                if(ans[ans.length()-1] == '('){
                    ans.pop_back();
                    continue;
                }
            }else{
                ans.push_back(c);
            }
        }
    }
    if(ans.empty()){
        cout << "Yes" << endl;
    }else{
        cout << "No" << endl;
    }
}

int main()
{
    file();
    int t;
    cin >> t;
    cin.ignore();
    for (int i = 1; i <= t; i++)
        solve(i);
    return 0;
}
