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
    int size;

public:
    llist()
    {
        head = new Node();
        head->next = NULL;
        size = 0;
    }
    void insert(int x)
    {
        if (head->next == NULL)
        {
            Node *t = new Node();
            t->data = x;
            head->next = t;
            t->next = head->next;
            size++;
        }
        else
        {
            Node *t = new Node();
            t->data = x;
            head->next = t;
            size++;
        }
    }
    void del(int x)
    {
        // int temp=size;
        int count = 0;
        Node *t = head->next;
        while (t->data != x)
        {
            t = t->next;
            count++;
            if (count == size)
            {
                cout << x << " not found\n";
                break;
            }
        }
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