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
    int inorder_succesor(Node *x) //provided it exists
    {
        Node *t = x->rc;
        while (t->lc != NULL)
        {
            t = t->lc;
        }
        return t->data;
    }
    void del_caseA(Node *A, int x) //working
    {
        if (x == 1)
        {
            delete A->rc;
            A->rc = NULL;
            return;
        }
        if (x == -1)
        {
            delete A->lc;
            A->lc = NULL;
            return;
        }
    };
    void del_caseB(Node *A, int x) //working
    {
        if (x == 1)
        {
            if (A->rc->rc != NULL)
                A->rc = A->rc->rc;
            else
                A->rc = A->rc->lc;
            return;
        }
        if (x == -1)
        {
            if (A->lc->rc != NULL)
                A->lc = A->lc->rc;
            else
                A->lc = A->lc->lc;
            return;
        }
    }
    void del_caseC(Node *itr, int x)
    {
        if (x == 1)
        {
            int t = inorder_succesor(itr->rc);
            itr->rc->data = t;
            del(t, itr->rc);
        }
        if (x == -1)
        {
            int t = inorder_succesor(itr->lc);
            itr->lc->data = t;
            del(t, itr->lc);
        }
    }
    void del(int x, Node *X)
    {
        Node *itr = new Node(INT_MIN);
        if (x != X->data)
        {
            itr = X;
            while (1)
            {
                if (x > itr->data)
                {
                    if (x != itr->rc->data)
                    {
                        itr = itr->rc;
                        continue;
                    }
                    if (x = itr->rc->data)
                    {
                        if (itr->rc->rc == NULL && itr->rc->lc == NULL) //case A
                        {
                            del_caseA(itr, 1);
                            return;
                        }
                        if (itr->rc->rc == NULL || itr->rc->lc == NULL) //case B
                        {
                            del_caseB(itr, 1);
                            return;
                        }
                        if (itr->rc->rc != NULL && itr->rc->lc != NULL) //case C
                        {
                            del_caseC(itr, 1);
                            return;
                        }
                    }
                }

                if (x < itr->data)
                {

                    if (x != itr->lc->data)
                    {
                        itr = itr->lc;
                        continue;
                    }
                    if (x = itr->lc->data)
                    {
                        if (itr->lc->rc == NULL && itr->lc->lc == NULL) //case A
                        {
                            del_caseA(itr, -1);
                            return;
                        }
                        if (itr->lc->rc == NULL || itr->lc->lc == NULL) //case B
                        {
                            del_caseB(itr, -1);
                            return;
                        }
                        if (itr->lc->rc != NULL && itr->lc->lc != NULL) //case C
                        {
                            del_caseC(itr, -1);
                            return;
                        }
                    }
                }
            }
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
    t1.add(11);
    t1.add(0);
    t1.add(9);
    t1.print_inorder(t1.getRoot());
    cout << endl;
    t1.del(8, t1.getRoot());
    t1.print_inorder(t1.getRoot());
    cout << endl;
}
