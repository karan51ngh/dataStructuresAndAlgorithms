#include <iostream>
using namespace std;
class Node
{
public:
    int data;
    Node *next;
    Node *previous;
};
class llist
{
private:
    Node *head;
    Node *tail;

public:
    llist()
    {
        head = new Node();
        tail = new Node();
        head->next = NULL;
        head->previous = NULL;
        tail->next = NULL;
        tail->previous = NULL;
    }
    // void insert(int x) //traversing
    // {
    //     Node *t;
    //     t = head;
    //     while (t->next != NULL)
    //     {
    //         t = t->next;
    //     }
    //     t->next = new Node();
    //     t->next->data = x;
    //     t->next->next = NULL;
    // }
    void insertH(int x)
    {
        if (head->next == NULL)
        {
            Node *t = new Node();
            t->data = x;
            t->next = NULL;
            t->previous = NULL;
            head->next = t;
            tail->next = t;
        }
        else
        {
            Node *t = new Node();
            t->data = x;
            t->next = head->next;
            head->next = t;
            tail->next = t;
        }
    }
    void insertT(int x)
    {
    }
    void print()
    {
        Node *t = head;
        do
        {
            t = t->next;
            cout << t->data << " ";

        } while (t->next != NULL);
        cout << endl;
    }
};
int main()
{
    llist L;
    L.insert(2);
    L.insert(4);
    L.print();
}