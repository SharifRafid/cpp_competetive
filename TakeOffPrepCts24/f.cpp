#include <iostream>

using namespace std;

int main()
{

    long long a, b, x;

    cin >> a;
    cin >> b;
    cin >> x;

    int c = 0;

    if (a == b)
    {
        if (a % x == 0 || x == 1 || x == 0)
        {
            cout << 2 << endl;
        }
        else
        {
            cout << 0 << endl;
        }
        return 0;
    }

    if (x == 1)
    {
        cout << (b-a+1) << endl;
        return 0;
    }

    if (a > x)
    {
        while (a % x != 0)
        {
            a++;
        }
    }
    else
    {
        a = x;
    }
    while (b % x != 0)
    {
        b--;
    }

    cout << ((b - a + 2) / x) << endl;

    return 0;
}