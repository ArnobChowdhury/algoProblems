#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin >> n;
    char phoneNumber[n];
    int counter = 0;
    // while (counter < n)
    // {
    //     int inp;
    //     cin >> inp;
    //     pattern[counter] = inp;
    //     counter++;
    // }
    cin >> phoneNumber;
    int pattern[n];
    for (int i = 0; i < n; i++)
    {
        pattern[i] = phoneNumber[i] - '0';
    }

    int keypad[4][3] = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}, {100, 0, 100}};

    int matrix[n][2];

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < 4; j++)
        {
            bool shouldBreak = false;
            for (int y = 0; y < 3; y++)
            {
                if (pattern[i] == keypad[j][y])
                {
                    matrix[i][0] = j;
                    matrix[i][1] = y;
                    shouldBreak = true;
                    break;
                }
            }
            if (shouldBreak)
            {
                break;
            }
        }
    }

    int start;
    for (int i = 0; i < 4; i++)
    {
        for (int j = 0; j < 3; j++)
        {

            if (pattern[0] == keypad[i][j])
            {
                start = i;
            }
        }
    }

    int checkList[2];
    int countTill;
    if (start == 1 || start == 2)
    {
        checkList[0] = 1;
        checkList[1] = -1;
        countTill = 2;
    }
    else if (start == 0)
    {
        checkList[0] = 1;
        countTill = 1;
    }
    else if (start == 3)
    {
        checkList[0] = -1;
        countTill = 1;
    }

    bool hasMatch = false;

    for (int c = 0; c < countTill; c++)
    {
        bool shouldBreak = false;
        for (int i = 0; i < n; i++)
        {
            int changedAddress = matrix[i][0] + checkList[0];
            if (changedAddress >= 0 && changedAddress < 3)
            {
                hasMatch = true;
            }
            else if (changedAddress == 3)
            {
                if (matrix[i][1] == 1)
                {
                    hasMatch = true;
                }
                else
                {

                    hasMatch = false;
                    shouldBreak = true;
                    break;
                }
            }
            else
            {
                hasMatch = false;
                shouldBreak = true;
                break;
            }
        }
        if (shouldBreak)
            break;
    }

    if (hasMatch)
    {
        cout << "NO" << endl;
    }
    else
    {
        cout << "YES" << endl;
    }

    return 0;
}