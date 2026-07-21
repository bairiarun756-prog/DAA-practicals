#include <iostream>
using namespace std;

int main()
{
    int n, key;

    cout << "Enter the number of elements: ";
    cin >> n;

    int A[n];

    cout << "Enter the array elements: ";
    for (int i = 0; i < n; i++)
    {
        cin >> A[i];
    }

    cout << "Enter the element to search: ";
    cin >> key;

    for (int i = 0; i < n; i++)
    {
        if (A[i] == key)
        {
            cout << "Element found at position " << i + 1 << endl;
            return 0;
        }
    }

    cout << "Element not found" << endl;

    return 0;
}