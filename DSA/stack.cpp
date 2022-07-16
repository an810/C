#include<iostream>
#include<stack>

using namespace std;

bool isPair(char open, char close)
{
    if (open == '(' && close == ')')
        return true;
    else if (open == '{' && close == '}')
        return true;
    else if (open == '[' && close == ']')
        return true;
    else
        return false;
}

bool solve(char* x, int n)
{
    stack <char> S;
    for (int i=0; i<n; i++)
    {
        if (x[i] == '(' || x[i] == '[' || x[i] == '{')
            S.push(x[i]);
        else if (x[i] == ')' || x[i] == ']' || x[i] == '}')
        {
            if (S.empty()) return false;
            else 
            {
                char c = S.top();
                S.pop();
                if (!isPair(x[i], c)) return false;
            }
        }
    }
    if (S.empty()) return true;
    else return false;
}

int main()
{
    char c[] = "{{{[()]}}}";
    bool OK = solve(c,8);
    if (OK) printf("Is balance");
    else printf("Not balance");
}