#include <iostream>
using namespace std;
class Node
{
public:
    int data;
    Node *next;
};
class llist
{
private:
    Node *head;

public:
        llist()
    {
        head = new Node();
        head->data = 0;
        head->next = NULL;
    }
    void insert(int x)
    {
        Node *t;
        t = head;
        while (t->next != NULL)
        {
            t = t->next;
        }
        t->next = new Node();
        t->next->data = x;
        t->next->next = NULL;
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