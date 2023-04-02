#include <vector>
#include <iostream>
#include <unordered_set>
#include <algorithm>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    int size;
    std::cin >> size;
    int* keys = new int[size];
    int* doors = new int[size];

    std::unordered_multiset<int> s;
    for (int i = 0; i < size; i++) {
        std::cin >> keys[i];
    }
    for (int i = 0; i < size; i++) {
        std::cin >> doors[i];
    }

    int broken = 0;
    for (int i = 0; i < size; i++) {
        s.insert(keys[i]);
        if (s.count(doors[i])) {
            s.erase(s.find(doors[i]));
        }
        else {
            broken++;
        }
    }

    printf("%d", broken);

    delete[] keys;
    delete[] doors;

    return 0;
}