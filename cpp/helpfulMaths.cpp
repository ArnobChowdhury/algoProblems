#include <iostream>
#include <stdio.h>
#include <string.h>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

// int main()
// {
//     char sum[100];
//     cin >> sum;

//     vector<string> arr;

//     char *token = strtok(sum, "+");

//     while (token != NULL)
//     {
//         arr.push_back(token);
//         token = strtok(NULL, "+");
//     }
//     sort(arr.begin(), arr.end());
//     string res;
//     for (int i = 0; i < arr.size(); i++)
//     {
//         if (i == arr.size() - 1)
//         {
//             res = res + arr[i];
//         }
//         else
//         {
//             res = res + arr[i] + '+';
//         }
//     }
//     cout << res << endl;
//     return 0;
// }

// int main()
// {
//     int a[100], i = 0, j;
//     std::string name = 'Cherno';
//     while (cin >> a[i++])
//     {
//         cin.ignore(1);
//         for(int i = 0; i < 3; i++) {
//             cout << a[i] << endl;
//         }
//     }
//     return 0;
// }

void Increment(int &value)
{
    value++;
}

int main()
{
    // std::string name3 = "Cherno";
    // const char *name = "Cherno";
    // char name2[6] = {'A', 'r', 'n', 'o', 'b', 0};
    // std::cout << name2 << endl;

    // int a = 5;
    // Increment(a);
    // int &ref = a;
    // ref = 2;
    // std::cout << a << std::endl;

    int a = 5;
    int b = a;

    cout << b << endl;

    a = 8;
    cout << b << endl;
}