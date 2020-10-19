#include <iostream>
#include <vector>

using namespace std;

int Solution(vector<int> &A, int B)
{
    int max = 0;
    int leftLoopCounter = B - 1;
    for (int i = 1; i <= B + 1; i++)
    {
        int rightCurrentIndex = A.size() - 1;
        int loopMax = 0;
        for (int j = leftLoopCounter; j >= 0; j--)
        {
            loopMax += A[j];
        }
        leftLoopCounter--;
        if (i > 1)
        {
            // int diff = i;
            for (int y = i - 1; y > 0; y--)
            {
                loopMax += A[rightCurrentIndex];
                rightCurrentIndex--;
            }
        }
        if (loopMax > max)
        {
            max = loopMax;
        }
    }
    return max;
}

int main()
{
    vector<int> A;
    // A.push_back(5);
    // A.push_back(-2);
    // A.push_back(3);
    A.push_back(1);
    A.push_back(2);

    int result = Solution(A, 1);
    cout << result << endl;

    return 0;
}