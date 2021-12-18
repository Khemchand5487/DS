// C++ or Cpp program to evaluate postfix and prefix expresions

#include <bits/stdc++.h>

using namespace std;

int evaluate(char o, int op1, int op2){
    switch(o)
    {
        case '+': return op1+op2;
        case '-': return op1-op2;
        case '/': return op1/op2;
        case '*': return op1*op2;
        case '^': return pow(op1,op2);
        default : return 0;
    }
}

void evaluatePostfix(string exps)
{
    unordered_map<char, int> opr;
    string str = "*/-+^";
    for(int i =0;i<5;i++)
    {
        opr[str[i]] = 1;
    }
    
    stack<int> s;
    int op1, op2, res;
    int n = exps.length();
    
    for(int i=0;i<n;i++)
    {
        if(isdigit(exps[i]))
        {
            s.push(exps[i] -'0');
        }
        else if(opr.find(exps[i]) != opr.end())
        {
            op2 = s.top();
            s.pop();
            op1 = s.top();
            s.pop();
            
            res = evaluate(exps[i], op1,op2);
            s.push(res);
        }
    }
    
    cout<<s.top()<<endl;
}

void evaluatePrefix(string exps)
{
    unordered_map<char, int> opr;
    string str = "*/-+^";
    for(int i =0;i<5;i++)
    {
        opr[str[i]] = 1;
    }
    
    stack<int> s;
    int op1, op2, res;
    int n = exps.length();
    
    for(int i=n-1;i>=0;i--)
    {
        if(isdigit(exps[i]))
        {
            s.push(exps[i] -'0');
        }
        else if(opr.find(exps[i]) != opr.end())
        {
            op1 = s.top();
            s.pop();
            op2 = s.top();
            s.pop();
            
            res = evaluate(exps[i], op1,op2);
            s.push(res);
        }
    }
    
    cout<<s.top()<<endl; 
}

int main()
{
   string s="23*54*+9-";//postfix
   string s1="-+*23*549";//prefix
   evaluatePostfix(s);
   evaluatePrefix(s1);
   
   return 0;
}
