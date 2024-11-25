#include <bits/stdc++.h>

using namespace std;

int main()
{

    int n;
    cin >> n;
    int ar[n];
    bool is = true;
    while (n--)
    {
        int x;
        cin >> x;
        if (x % 2 == 0)
        {
            if (x % 3 == 0 || x % 5 == 0)
            {
            }
            else
            {
                is = false;
            }
        }
    }
    if (is)
    {
        cout << "APPROVED" << endl;
    }
    else
    {
        cout << "DENIED" << endl;
    }

    return 0;
}