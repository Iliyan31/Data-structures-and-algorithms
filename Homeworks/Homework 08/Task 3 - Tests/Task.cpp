
#include <iostream>
#include <set>
#include <vector>
#include <algorithm>
#include <utility>

std::vector<std::pair<size_t, size_t>> vec;
std::set<std::pair<int, int>> st;

void createVector(const int& size) {
    std::pair<size_t, size_t> p;
    for (int i = 0; i < size; i++) {
        int num1, num2;
        std::cin >> num1 >> num2;
        p.first = num1;
        p.second = num2;
        vec.push_back(p);
    }
}

void fillSet(const int& size, int& temp, const size_t& time) {
    while (temp < size && vec[temp].first <= time) {
        st.insert(std::make_pair(vec[temp].second, temp));
        temp++;
    }
}

void findSum(long long& sum, size_t& time) {
    int temp = st.begin()->second;
    st.erase(st.begin());
    time += vec[temp].second;
    sum += time - vec[temp].first;
}

void evaluateSum(const int& size, int& temp, size_t& time) {
    long long sum = 0;
    while (temp < size || st.size()) {
        fillSet(size, temp, time);
        if (st.empty()) {
            time = vec[temp].first;
        }
        else {
            findSum(sum, time);
        }
    }
    std::cout << (sum / size);
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int size;
    std::cin >> size;
    createVector(size);

    std::sort(vec.begin(), vec.end());
  
    size_t time = vec[0].first;
    int temp = 0;

    evaluateSum(size, temp, time);
    return 0;
}