#include <iostream>

using namespace std;

class Node
{
    public:
        int data;
        Node *next;
        
        Node(int x)
        {
            this->data = x;
            this->next = NULL;
        }
};


class Stack
{
    Node *top;
    
    public:
        Stack()
        {
            this->top = NULL;
        }
        bool isEmpty()
        {
            return top==NULL;
        }
        
        void push(int x)
        {
            Node *nn = new Node(x);
            nn->next = top;
            top = nn;
        }
        
        void pop()
        {
            if(isEmpty()){
                cout<<"Stack is empty!"<<endl;
                return;
            }
            
            Node *temp = top;
            top = top->next;
            
            delete temp;
            
        }
        
        int peek()
        {
            if(isEmpty())
            {
                cout<<"Stack is empty, returning -1!"<<endl;
                return -1;
            }
            return top->data;
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
