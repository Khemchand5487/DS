//Reverse a String using stack in cpp

#include <bits/stdc++.h>

using namespace std;

int main()
{
   stack<char> s;
   
   string str = "Hello World";
   
   for(char i: str)
   {
       s.push(i);
   }
   
   for(int i=0;i<str.size();i++)
   {
       str[i] = s.top();
       s.pop();
   }
   
   cout<<str<<endl;
   
   return 0;
}
