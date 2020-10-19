#include <bits/stdc++.h>

using namespace std;

int Solution(vector<int> &A, vector<int> &B)
{
    int currentX = A[0];
    int currentY = B[0];

    int moves = 0;
    int currentGoalXPos = 1;
    int currentGoalYPos = 1;
    while (currentGoalXPos < A.size() && currentGoalYPos < B.size())
    {
        bool moveMade = false;
        if (currentX < A[currentGoalXPos])
        {
            moveMade = true;
            currentX += 1;
        }
        else if (currentX > A[currentGoalXPos])
        {
            currentX -= 1;
            moveMade = true;
        }
        if (currentY < B[currentGoalYPos])
        {
            currentY += 1;
            moveMade = true;
        }
        else if (currentY > B[currentGoalYPos])
        {
            currentY -= 1;
            moveMade = true;
        }
        if (moveMade)
        {
            moves++;
        }

        if (currentX == A[currentGoalXPos] && currentY == B[currentGoalYPos])
        {
            currentGoalXPos++;
            currentGoalYPos++;
        }
    }
    return moves;
}

int main()
{
    vector<int> A;
    vector<int> B;
    A.push_back(-7);
    A.push_back(-13);
    // A.push_back(1);

    B.push_back(1);
    B.push_back(-5);
    // B.push_back(2);

    int mysolution = Solution(A, B);
    std::cout << mysolution << endl;
}