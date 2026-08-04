#include <iostream>
using namespace std;

long long factorialRecursive(int n)
{
    if (n == 0 || n == 1)
        return 1;
    else
        return n * factorialRecursive(n - 1);
}

int main()
{
    int n;
    cout << "Enter a number: ";
    cin >> n;

    cout << "Factorial = " << factorialRecursive(n);

    return 0;
}