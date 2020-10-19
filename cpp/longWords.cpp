#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main()
{
    int n; 
    int count = 1; 
    std::cin >> n;
    while(count <= n)
    {
        string word;
        std::cin >> word;
        int lengthOfTheWord = word.length();
        string result;
        if (lengthOfTheWord > 10)
        {
            result = word.at(0) + std::to_string(lengthOfTheWord - 2)   + word.at(lengthOfTheWord - 1) ;
        } else {
            result = word;
        }
        if (count == n) {
            count = count + 1;
            cout << result << endl;
        } else {
            count = count + 1;
            cout << result + '\n';
        }
    }
}