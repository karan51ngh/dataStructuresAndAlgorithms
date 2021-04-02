#include <iostream>
#include <limits.h>
using namespace std;
class Node
{
public:
    Node *lc;
    int data;
    Node *rc;
    Node(int x)
    {
        lc = NULL;
        data = x;
        rc = NULL;
    }
};
class Tree
{
private:
    Node *root;

public:
    Tree()
    {
        root = new Node(INT_MIN);
    }
    void add(int x)
    {
        if (root->data == INT_MIN)
        {
            root->data = x;
            return;
        }
        Node *t = root;
        while (1)
        {
            if (x == t->data)
                return;

            if (x < t->data)
            {
                if (t->lc != NULL)
                    t = t->lc;

                else
                {
                    Node *temp = new Node(x);
                    t->lc = temp;
                    return;
                }
            }
            if (x > t->data)
            {
                if (t->rc != NULL)
                    t = t->rc;

                else
                {
                    Node *temp = new Node(x);
                    t->rc = temp;
                    return;
                }
            }
        }
    }
    Node *getRoot()
    {
        return root;
    }

    void print_inorder(Node *t)
    {
        if (t == NULL)
        {
            return;
        }
        else
        {
            print_inorder(t->lc);
            cout << t->data << " ";
            print_inorder(t->rc);
        }
    }
    void print_preorder(Node *t)
    {
        if (t == NULL)
        {
            return;
        }
        else
        {

            cout << t->data << " ";
            print_preorder(t->lc);
            print_preorder(t->rc);
        }
    }
    void print_postorder(Node *t)
    {
        if (t == NULL)
        {
            return;
        }
        else
        {
            print_postorder(t->lc);
            print_postorder(t->rc);
            cout << t->data << " ";
        }
    }
};

int main()
{
    Tree t1;
    t1.add(6);
    t1.add(2);
    t1.add(4);
    t1.add(1);
    t1.add(5);
    t1.add(8);
    t1.add(7);
    t1.add(10);
    t1.print_inorder(t1.getRoot());
    cout << endl;
    t1.print_preorder(t1.getRoot());
    cout << endl;
    t1.print_postorder(t1.getRoot());
    cout << endl;
}
