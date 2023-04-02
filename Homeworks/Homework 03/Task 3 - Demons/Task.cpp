#include <iostream>
#include <vector>
#include <algorithm>
#include <utility>


int fun(std::vector<std::pair<unsigned int, unsigned int>>& vec) {
    if (vec.size() == 0) return 0;
    std::sort(vec.begin(), vec.end());


    std::vector<unsigned int> tail(vec.size(),-1);

    int length = 1; 
    tail[0] = vec[0].second;
 
    for (int i = 1; i < vec.size(); i++) {
        auto b = tail.begin(), e = tail.begin() + length;
        auto item = std::lower_bound(b, e, vec[i].second);
 
        if (item == tail.begin() + length) tail[length++] = vec[i].second;
        else *item = vec[i].second;
    }
 
    return length;
}

int main() {

    int size;
    std::cin >> size;

    std::pair<unsigned int, unsigned int> p;
    std::vector<std::pair<unsigned int, unsigned int>> vec;

    for (int i = 0; i < size; i++) {
        std::cin >> p.first >> p.second;
        vec.push_back(p);
    }
    std::cout << fun(vec);

    return 0;
}