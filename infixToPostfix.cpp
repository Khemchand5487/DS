// C++ program to convert infix expression to postfix

#include <bits/stdc++.h>

using namespace std;

//check character is an operand or not
bool isOperand(char c)
{
    return ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z') || (c >= '0' && c <= '9'));
}

//check character is an operator or not
bool isOperator(char s)
{
    switch(s)
    {
        case '+': return true;
        case '-': return true;
        case '*': return true;
        case '/': return true;
        case '^': return true;
        default : return false;
    }
    return false;
}

//check character is an opening bracket or not
bool isOpeningBrackets(char s)
{
    switch(s)
    {
        case '(': return true;
        case '{': return true;
        case '[': return true;
        default : return false;
    }
    return false;
}

//check character is an closing bracket or not
bool isClosingBrackets(char s)
{
    switch(s)
    {
        case ')': return true;
        case '}': return true;
        case ']': return true;
        default : return false;
    }
    return false;
}

bool HasHigherprec(char c1, char c2)
{
    unordered_map<char, int> m;
    m['+'] = 1;
    m['-'] = 1;
    m['*'] = 2;
    m['/'] = 2;
    m['^'] = 3;
    
    return m[c1]>=m[c2];
}

string postToInfix(string exps)
{
    stack<char> s;
    string res = "";
    int n = exps.length();
    
    for(int i=0;i<n;i++)
    {
        if(isOperand(exps[i]))  res+=exps[i];
        else if(isOpeningBrackets(exps[i])) s.push(exps[i]);
        else if(isClosingBrackets(exps[i]))
        {
            while(!s.empty() && !isOpeningBrackets(s.top()))
            {
                res+= s.top();
                s.pop();
            }
            s.pop();
        }
        else if(isOperator(exps[i]))
        {
            while(!s.empty() && !isOpeningBrackets(exps[i]) && HasHigherprec(s.top(), exps[i]))
            {
                res+=s.top();
                s.pop();
            }
            s.push(exps[i]);
        }
    }
    
    while(!s.empty())
    {
        res+= s.top();
        s.pop();
    }
    return res;
}

int main()
{
    string s="a+b*(c^d-e)^(f+g*h)-i";
    cout<<postToInfix(s)<<endl;
   
   return 0;
}
