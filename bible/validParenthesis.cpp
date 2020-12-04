#include <bits/stdc++.h>

using namespace std;

int typeOf(char c)
{
    if (c == '{' || c == '}')
        return 0;
    if (c == '(' || c == ')')
        return 1;
    return 2;
}

bool validParenthesis(string a)
{
    stack<char> s;
    for (int i = 0; i < a.size(); i++)
    {
        if (a[i] == '(' || a[i] == '{' || a[i] == '[')
            s.push(a[i]);
        else
        {
            if (!s.empty() && typeOf(s.top()) == typeOf(a[i]))
                s.pop();
        }
    }
    return s.empty();
}

int main()
{
    bool res = validParenthesis("[{}({[]})]");
    std::cout << res << endl;
    return 0;
}