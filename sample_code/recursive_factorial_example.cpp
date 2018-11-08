#include <iostream>


using namespace std;



int Factorial (int n)
{
    if (n==0)//stopping condition
        return 1;
    else//recursive step
        return n*Factorial(n-1);
}

int main ()
{
    int a=0;
    cout << "give an integer input";
    cout << "\n";
    cin >> a;
    cout << a<<"!"<<" is equal to "<<Factorial(a);

}
