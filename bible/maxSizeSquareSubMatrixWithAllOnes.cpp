#include <bits/stdc++.h>

using namespace std;

const int n = 6;

int maxSizeOfSquareSubMatrixWithAllOnes(int matrix[][n])
{
    int maxSize = 0;
    int dp[n][n];

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (i == 0 || j == 0 || matrix[i][j] == 0)
            {
                dp[i][j] = matrix[i][j];
            }
            else
            {
                int dpVal = min(min(dp[i - 1][j], dp[i - 1][j - 1]), dp[i][j - 1]) + 1;
                maxSize = max(maxSize, dpVal);
                dp[i][j] = dpVal;
            }
        }
    }

    return maxSize;
}

int main()
{
    int matrix[n][n] = {{1, 0, 1, 0, 1, 1},
                        {0, 1, 1, 1, 1, 1},
                        {1, 0, 1, 1, 1, 0},
                        {1, 0, 1, 1, 1, 0},
                        {0, 1, 0, 0, 1, 1}};

    int res = maxSizeOfSquareSubMatrixWithAllOnes(matrix);

    cout << res << endl;
}