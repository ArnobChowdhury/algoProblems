#include <iostream>
#include <string>

using namespace std;

int main()
{
    int numberOfProblems = 0;
    cin >> numberOfProblems;

    int teamMembers = 3;

    int numberOfProblemsToSolve = 0;

    while (numberOfProblems > 0) {
        int result = 0;
        for (int i = 0; i < teamMembers; i++) {
            int currentResult;
            cin >> currentResult;
            result = result + currentResult;
        }

        if (result >= 2) {
            numberOfProblemsToSolve++; 
        }
        numberOfProblems--;
    }
    cout << numberOfProblemsToSolve << endl;
}