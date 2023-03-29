#include <iostream>
#include <string>
#include <algorithm>
#include <vector>

void printAllWithOne(const std::string& str) {
    int arr[150];
    for (int i = 0; i < 150; i++) {
        arr[i] = 0;
    }
    int arr2[150];
    int sizeStr = str.length();
    for (int i = 0; i < sizeStr; i++) {
        int current = str[i];
        arr[current]++;
        arr2[current] = i;
    }

    std::vector<int> vec;
    for (int i = 0; i < 150; i++) {
        if (arr[i] == 1) {
            vec.push_back(arr2[i]);
        }
    }

    std::sort(vec.begin(), vec.end());
    for (int i = 0; i < vec.size(); i++) {
        std::cout << vec[i] << " ";
    }
}

int main() {
    std::string str;
    std::cin >> str;
    printAllWithOne(str);
    return 0;
}