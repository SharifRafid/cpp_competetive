#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main()
{

    string s;

    cin >> s;

    int isEven = 1;

    char done[26];
    int doneLen = 0;

    for (int i = 0; i < s.size(); i++)
    {
        int alreadyDone = 0;
        for (int i2 = 0; i2 < doneLen; i2++)
        {
            if (done[i2] == s[i])
            {
                alreadyDone = 1;
                break;
            }
        }
        if(alreadyDone){
            continue;
        }
        int count = 0;
        for (int i2 = i; i2 < s.size(); i2++)
        {
            if (s[i2] == s[i])
            {
                count++;
            }
        }
        if (count % 2 != 0)
        {
            isEven = 0;
            break;
        }
        done[doneLen] = s[i];
        doneLen ++;
    }

    if (isEven == 1)
    {
        cout << "Yes" << endl;
    }
    else
    {
        cout << "No" << endl;
    }

    return 0;
}