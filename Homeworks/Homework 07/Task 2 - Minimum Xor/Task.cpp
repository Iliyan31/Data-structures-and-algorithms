#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <set>
#include <iterator>
#include <queue>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int size;
    std::cin >> size;

    size_t num;
    std::cin >> num;

    std::set<size_t> s;
    std::vector<size_t> vec;

    s.insert(0);
    s.insert(num);
    vec.push_back(num);

    size_t min = num;
    for (int i = 1; i < size; i++) {
        std::cin >> num;
        
        if (!s.count(num)) {
            size_t minXor = 1e10;

            if (*s.rbegin() < num) {
                minXor = (*s.rbegin() ^ num);
            }
            else {
                size_t up = *(s.upper_bound(num));
                size_t low = *(--s.upper_bound(num));

                size_t a = (low ^ num), b = (num ^ up);

                if (a <= b) minXor = a;
                else minXor = b;
            }

            if (minXor < min) {
                min = minXor;
            }
        }
        s.insert(num);
        vec.push_back(min);
    }

    size_t sizeVec = vec.size();
    for (int i = 0; i < sizeVec; i++) {
        std::cout << vec[i] << "\n";
    }

    return 0;
}