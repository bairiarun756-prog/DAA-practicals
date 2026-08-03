#include <iostream>
#include <vector>
#include <algorithm> 

void heapify(std::vector<int>& arr, int n, int i) {
    int largest = i;         
    int leftChild = 2 * i + 1;  
    int rightChild = 2 * i + 2; 
    
    if (leftChild < n && arr[leftChild] > arr[largest]) {
        largest = leftChild;
    }

    
    if (rightChild < n && arr[rightChild] > arr[largest]) {
        largest = rightChild;
    }

    
    if (largest != i) {
        std::swap(arr[i], arr[largest]);

        heapify(arr, n, largest);
    }
}

void heapSort(std::vector<int>& arr) {
    int n = arr.size();


    for (int i = n / 2 - 1; i >= 0; i--) {
        heapify(arr, n, i);
    }

    for (int i = n - 1; i > 0; i--) {
        std::swap(arr[0], arr[i]);

        heapify(arr, i, 0);
    }
}

void printArray(const std::vector<int>& arr) {
    for (int num : arr) {
        std::cout << num << " ";
    }
    std::cout << "\n";
}

int main() {
    std::vector<int> data = {12, 11, 13, 5, 6, 7};
    
    std::cout << "Original array: ";
    printArray(data);

    heapSort(data);

    std::cout << "Sorted array:   ";
    printArray(data);

    return 0;
}
