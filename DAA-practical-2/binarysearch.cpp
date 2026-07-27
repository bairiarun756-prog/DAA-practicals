#include <iostream>
using namespace std;

int main()
{
    int n, key;

    cout << "Enter the number of elements: ";
    cin >> n;

    int A[n];

    cout << "Enter the sorted array elements: ";
    for (int i = 0; i < n; i++)
    {
        cin >> A[i];
    }

    cout << "Enter the element to search: ";
    cin >> key;

    int low = 0;
    int high = n - 1;
    int mid;

    while (low <= high)
    {
        mid = (low + high) / 2;

        if (A[mid] == key)
        {
            cout << "Element found at position " << mid + 1 << endl;
            return 0;
        }
        else if (A[mid] < key)
        {
            low = mid + 1;
        }
        else
        {
            high = mid - 1;
        }
    }

    cout << "Element not found" << endl;

    return 0;
}