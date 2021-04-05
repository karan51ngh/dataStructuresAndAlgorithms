#include <iostream>
using namespace std;
void TOH_Solver(char, char, char, int);
int main()
{
    char A = 'A';
    char B = 'B';
    char C = 'C';
    int n = 3;
    TOH_Solver(A, B, C, n);
}
void TOH_Solver(char From, char Using, char To, int n)
{
    if (n == 1)
    {
        cout << "Move top disk from " << From << " To " << To << endl;
    }
    else
    {
        TOH_Solver(From, To, Using, n - 1);
        TOH_Solver(From, Using, To, 1);
        TOH_Solver(Using, From, To, n - 1);
    }
}