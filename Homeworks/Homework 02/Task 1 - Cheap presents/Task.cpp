#include <vector>
#include <iostream>

void ownSwap(int& a, int& b) {
    int temp = a;
    a = b;
    b = temp;
}

int partition(int* arr, int low, int high) {
    int pivot = arr[high];
    int j = low;
    for (int i = low; i < high; i++) {
        if (arr[i] <= pivot) {
            ownSwap(arr[i],arr[j]);
            j++;
        }
    }
    ownSwap(arr[j],arr[high]);
    return j;
}

void ownSort(int* arr, int low, int high) {
    if (low < high) {
        int pi = partition(arr, low, high);
        ownSort(arr, low, pi - 1);
        ownSort(arr, pi + 1, high);
    }
}

long presents(int* arr, const int& size, const int& people) {
    ownSort(arr, 0, size-1);
    long sum = 0;
    for (int i = 0; i < people; i++) {
        sum += arr[i];
    }

    return sum;
}

int main() {
    int size;
    std::cin >> size;

    int* arr = new int[size];
    for (int i = 0; i < size; i++) {
        std::cin >> arr[i];
    }

    int people;
    std::cin >> people;
  
    std::cout << presents(arr, size, people);

    delete[] arr;
    return 0;
}
