#include <iostream>

using namespace std;

int fastExpo(int a, long long n, int mod)
{
    if (n == 0)
        return 1;
    if (n % 2 == 0)
        return fastExpo((1ll * a * a) % mod, n / 2, mod);

    return (1ll * a * fastExpo(a, n - 1, mod)) % mod;
}

int fastexpoIterative(int a, long long n, int mod)
{
    int ans = 1;
    while (n >= 1)
    {
        if (n % 2 == 0)
        {
            a = (1LL * a * a) % mod;
            n /= 2;
        }
        else
        {
            ans = (1LL * ans * a) % mod;
            n--;
        }
    }

    return ans;
}

int main()
{
    // int m = fastExpo(2, 10, 1000000007);
    int m = fastExpo(10, 10, 7);
    int i = fastexpoIterative(7, 10, 1000000007);
    cout << "recursive " << m << endl;
    cout << "iterative " << i << endl;
    return 0;
}