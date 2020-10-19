#include <iostream>
#include <vector>

using namespace std;

int main()
{
    vector<int> B(2 * 10, 0);

    for (int i = 0; i < B.size(); i++)
    {
        cout << B[i] << " ";
    }
}