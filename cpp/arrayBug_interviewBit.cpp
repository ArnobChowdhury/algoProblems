#include <iostream>
#include <vector>

using namespace std;

vector<int> rotateArray(vector<int> &A, int B)
{
    vector<int> ret;

    for (int i = 0; i < A.size(); i++)
    {
        ret.push_back(A[((i + B) % A.size())]);
    }
    return ret;
}

int main()
{
    vector<int> A;

    A.push_back(14);
    A.push_back(5);
    A.push_back(14);
    A.push_back(34);
    A.push_back(42);
    A.push_back(63);
    A.push_back(17);
    A.push_back(25);
    A.push_back(39);
    A.push_back(61);
    A.push_back(97);
    A.push_back(55);
    A.push_back(33);
    A.push_back(96);
    A.push_back(62);
    A.push_back(32);
    A.push_back(98);
    A.push_back(77);
    A.push_back(35);

    vector<int> ret = rotateArray(A, 56);

    for (int i = 0; i < ret.size(); i++)
    {
        if (i == 0)
        {
            cout << "[ ";
        }
        if (i == ret.size() - 1)
        {
            cout << ret[i];
            cout << "]" << endl;
        }
        else
        {

            cout << ret[i] << ", ";
        }
    }
    return 0;
}