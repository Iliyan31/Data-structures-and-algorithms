#include <iostream>
#include <vector>

void func(const size_t* arr, const int& size, const size_t& k) {
    std::vector<int> v(size,-1);

    for (int i = 1; i < size; i++) {
        for (int j = i - 1; j >= 0; j--) {
            if ((arr[i] - arr[j]) > 0 && (arr[i] - arr[j]) <= k) {
                v[i] = j;
                break;
            }
        }
    }

    int sizeVec = v.size();
    for (int i = 0; i < sizeVec; i++) {
        std::cout << v[i] << " ";
    }
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    size_t N, k;
    std::cin >> N >> k;

    size_t* arr = new size_t[N];
    for (int i = 0; i < N; i++) {
        std::cin >> arr[i];
    }

    func(arr, N, k);

    delete[] arr;

    return 0;
}