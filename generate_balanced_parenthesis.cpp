#include<iostream>
#include<vector>
using namespace std;

void _printParenthesis(int pos, int n, int open, int close);

// Wrapper over _printParenthesis()
void printParenthesis(int n)
{
    if(n > 0)
        _printParenthesis(0, n, 0, 0);
    return;
}

void _printParenthesis(int pos, int n, int open, int close)
{
    static char str[100];

    if(close == n)
    {
       cout<<str<<endl;
        return;
    }
    else
    {
        // if more opening brackets are there, put closing brackets and increment close
        if(open > close)
        {
            str[pos] = ')';
            _printParenthesis(pos+1, n, open, close+1);
        }

        // if less opening brackets are there then n, then put opening brackets and increment open
        if(open < n)
        {
            str[pos] = '(';
            _printParenthesis(pos+1, n, open+1, close);
        }
    }
}

int main() {
    int n;
    cin>>n;
    printParenthesis(n);

    return 0;
}