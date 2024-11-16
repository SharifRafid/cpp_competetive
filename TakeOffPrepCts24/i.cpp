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
        for (int j = 0; j <= n - m; j++)
        {
            int found = 0;
            if (a[i].substr(j, m).compare(b[0]) == 0)
            {
                found = 1;
                for (int k = 1; k < m; k++)
                {

                    if (i + k >= n)
                    {
                        found = 0;
                        break;
                    }
                    // cout << "--" << endl;
                    // cout << "-" << a[i + k].substr(j, j + m) << "-" << endl;
                    // cout << "-" << b[k] << "-" << endl;
                    int output = a[i + k].substr(j, m).compare(b[k]);
                    // cout << "--" << endl;
                    // cout << output << endl;
                    // cout << "--" << endl;
                    if (output != 0)
                    {
                        found = 0;
                    }
                }
            }
            if (found == 1)
            {
                foundM = 1;
                break;
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