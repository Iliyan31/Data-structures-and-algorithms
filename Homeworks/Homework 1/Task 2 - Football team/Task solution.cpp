#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

bool validationNumber(const size_t& size) {
    return (size >= 1 && size <= pow(10, 6));
}

int missingNumber(std::vector<int>& vec) {
    std::sort(vec.begin(), vec.end());
    int counter = 1;
    bool flag = false;
    bool passed = false;
    for (int i = 0; i < vec.size() - 1; i++) {
        if (vec[i] > 0) {
            flag = true;
            if (vec[i] == 1) passed = true;
            if ((vec[i + 1] - vec[i]) > 1) {
                return vec[i] + 1;
            }
            if (passed == false) return 1;
        }
    }
    if (flag == false) return 1;
    return vec[vec.size() -1] + 1;
}


int main() {
    size_t size;
    std::cin >> size;
    if (!validationNumber(size)) return -1;

    int num;
    std::vector<int> vec;
    for (int i = 0; i < size; i++) {
        std::cin >> num;
        vec.push_back(num);
    }

    std::cout << missingNumber(vec);

    return 0;
}