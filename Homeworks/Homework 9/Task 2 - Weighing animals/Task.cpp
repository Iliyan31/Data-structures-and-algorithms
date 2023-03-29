#include <iostream>
#include <unordered_map>

size_t weightOfAnimals(const long* arr, const int& size, const long& k) {
    std::unordered_map<long, long> lhs, rhs;
    long result = 0;

    for (int i = 0; i < size; i++) {
        rhs[arr[i]]++;
    }

    if (k == 1) {
        for (auto it : rhs) {
            if (it.second >= 3) {
                long temp = it.second*(it.second-1)*(it.second-2);
                temp/=6;
                result+=temp;     
            }
        }
        return result;
    }

    for (int i = 0; i < size; i++) {
        long num1 = 0, num2 = 0;

        if (arr[i] % k == 0) {
            if (lhs.count(arr[i] / k)) {
                num1 = lhs[arr[i] / k];
            }
            if (rhs.count(arr[i] * k)) {
                num2 = rhs[arr[i] * k];
            }
        }
        rhs[arr[i]]--;
        lhs[arr[i]]++;

        if (num1 > 0 && num2 > 0) {
            result += (num1 * num2);
        }        
    }
    return result;
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    long size, k;
    std::cin >> size >> k;
    long* arr = new long[size];
    for (int i = 0; i < size; i++) {
        std::cin >> arr[i];
    }

    std::cout<<weightOfAnimals(arr, size, k);

    delete[] arr;
    return 0;
}