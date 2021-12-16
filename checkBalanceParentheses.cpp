//Check whether the expression has balanced parentheses (Brackets) or not.

#include <bits/stdc++.h>

using namespace std;

bool checkPair(char a, char b)
{
    switch(a)
    {
        case '(':
            if(b == ')') return true;
            break;
        case '{':
            if(b == '}') return true;
            break;
        case '[':
            if(b == ']') return true;
            break;
    }
    return false;
}

bool checkBalancedParentheses(string str)
{
    int n = str.size();
    stack<char> s;
    
    for(int i=0;i<n;i++)
    {
        if(str[i] == '(' or str[i] == '[' or str[i] == '{')
            s.push(str[i]);
        else if(str[i] == ')' or str[i] == ']' or str[i] == '}')
        {
            if(s.empty() || !checkPair(s.top(), str[i]))
                return false;
            else
                s.pop();
        }
    }
    
    return s.empty();
}

int main()
{

   string str = "(([{{()}}]))";
   
   cout<<(checkBalancedParentheses(str) ? "Balanced": "Unbalanced")<<endl;
   
   return 0;
}
