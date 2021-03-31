#include <iostream>
using namespace std;
class Node
{
public:
    int data;
    Node *next;
};
class Queue
{
private:
    Node *front;
    Node *rear;

public:
    Queue()
    {
        front = new Node;
        rear = new Node;
        front->next = NULL;
        rear->next = NULL;
    }
    void enque(int x)
    {

        if (rear->next == NULL)
        {
            Node *t;
            t = new Node;
            t->data = x;
            t->next = NULL;
            rear->next = t;
            front->next = t;
        }
        else
        {
            Node *t;
            t = new Node;
            t->data = x;
            t->next = rear->next;
            rear->next = t;
        }
    }
    void deque()
    {
        if (front->next == NULL) //no Node
        {
            cout << "empty!";
        }
        else if (front->next == rear->next) //last Node
        {
            front->next = NULL;
            rear->next = NULL;
        }
        else //generic Case
        {
            Node *t;
            t = rear->next;
            while (t->next != front->next)
            {
                t = t->next;
            }
            front->next = t;
        }
    }
    void peek()
    {
        cout << front->next->data << endl;
    }
};
int main()
{
    Queue Q;
    Q.enque(3);
    Q.enque(4);
    Q.enque(5);
    Q.deque();
    Q.peek();
}
