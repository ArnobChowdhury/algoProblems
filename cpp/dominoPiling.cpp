#include <iostream>
#include <string>

using namespace std;

int main()
{
    int m, n;
    cin >> m >> n;
    int multipliedRes = m * n;
    if (multipliedRes > 1) {
        cout << (m * n)/2 << endl;
    } else {
        cout << 0 << endl;
    }
}