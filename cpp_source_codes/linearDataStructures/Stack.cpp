#include <iostream>
using namespace std;
class Node
{
public:
    int data;
    Node *next;
};
class Stack
{
private:
    Node *top;

public:
    Stack()
    {
        top = new Node;
        top->next = NULL;
    }
    void push(int x)
    {
        Node *t = new Node;
        t->data = x;
        t->next = top->next;
        top->next = t;
    }
    void pop()
    {
        if (top->next == NULL)
        {
            cout << "stack underflow";
        }
        else
        {
            // cout << top->next->data;
            top->next = top->next->next;
        }
    }
    void peek()
    {
        cout << top->next->data << endl;
    }
};
int main()
{
    Stack S;
    S.push(3);
    S.push(4);
    S.push(5);
    // S.pop();
    S.peek();
}