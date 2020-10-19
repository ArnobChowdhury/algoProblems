#include <iostream>
#include <vector>
#include <string>

using namespace std;

vector<int> spiralOrder(const vector<vector<int>> &A)
{
    string direction = "right";

    vector<int> res;
    int topRow = 0;
    int bottomRow = A.size() - 1;
    int leftCol = 0;
    int rightCol = A[0].size() - 1;

    while (topRow <= bottomRow && leftCol <= rightCol)
    {
        if (direction == "right")
        {
            for (int i = leftCol; i <= rightCol; i++)
            {
                int n = A[topRow][i];
                res.push_back(n);
            }
            direction = "down";
            topRow++;
        }
        else if (direction == "down")
        {
            for (int i = topRow; i <= bottomRow; i++)
            {
                int n = A[i][rightCol];
                res.push_back(n);
            }
            direction = "left";
            rightCol--;
        }
        else if (direction == "left")
        {
            for (int i = rightCol; i >= leftCol; i--)
            {
                int n = A[bottomRow][i];
                res.push_back(n);
            }
            direction = "up";
            bottomRow--;
        }
        else if (direction == "up")
        {
            for (int i = bottomRow; i >= topRow; i--)
            {
                int n = A[i][leftCol];
                res.push_back(n);
            }
            direction = "right";
            leftCol++;
        }
    }
    return res;
}

int main()
{
    vector<vector<int>> A;

    vector<int> A1;
    A1.push_back(1);
    A1.push_back(2);
    A1.push_back(3);
    A.push_back(A1);

    vector<int> A2;
    A2.push_back(4);
    A2.push_back(5);
    A2.push_back(6);
    A.push_back(A2);

    vector<int> A3;
    A3.push_back(7);
    A3.push_back(8);
    A3.push_back(9);
    A.push_back(A3);

    vector<int> res = spiralOrder(A);

    for (int i = 0; i < res.size(); i++)
    {
        cout << res[i] << " ";
    }

    return 0;
}
