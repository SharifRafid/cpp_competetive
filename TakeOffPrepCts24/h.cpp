#include <iostream>
#include <string>

using namespace std;

int main()
{

    int n, m;

    cin >> n;
    cin >> m;

    string a[n];

    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }

    string b[m];

    for (int i = 0; i < m; i++)
    {
        cin >> b[i];
    }

    int foundM = 0;
    for (int i = 0; i < n; i++)
    {
        if (a[i].substr(0, m) == b[0])
        {
            foundM = 1;
            for (int k = 1; k < m; k++)
            {
                if(i+k >= n){
                    foundM = 0;
                    break;
                }
                int output = a[i + k].substr(0, m) == b[k];
                if (output)
                {
                    foundM = 0;
                }
            }
        }
        if (foundM == 1)
        {
            break;
        }
    }

    if (foundM == 1)
    {
        cout << "Yes" << endl;
    }
    else
    {
        cout << "No" << endl;
    }

    return 0;
}