//Stack implementation using arrays in cpp

#include <iostream>

using namespace std;

class Stack
{
    int n;
    int top;
    int stack[4];
    
    public:
        Stack()
        {
            n = 4;
            top = -1;
        }
        bool isEmpty()
        {
            return top<0;
        }
        
        void push(int x)
        {
            top = top+1;
            if(top == n)
            {
                top--;
                cout<<"Stack is full!"<<endl;
                return;
            }
            
            stack[top] = x;
            
        }
        
        void pop()
        {
            if(isEmpty()){
                cout<<"Stack is empty!"<<endl;
                return;
            }
            
            top--;
        }
        
        int peek()
        {
            if(isEmpty())
            {
                cout<<"Stack is empty, returning -1!"<<endl;
                return -1;
            }
            return stack[top];
        }
};

int main()
{
   class Stack s;
   
   s.push(1);
   s.push(2);
   s.push(3);
   s.push(4);
   s.push(5);
   
   while(!s.isEmpty())
   {
       cout<<s.peek()<<endl;
       s.pop();
   }
   
   return 0;
}
