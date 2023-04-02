#include <iostream>
#include <vector>
#include <queue>

int index = 0;

int minimalElInQueue(std::queue<int> que, const int& ind) {
    int size = que.size();
    int min = 1e9;
    for (int i = 0; i < size; i++) {
        if (que.front() < min) {
            min = que.front();
            index = ind + i +1;
        }
        que.pop();
    }

    return min;
}

long long minimalRangeSum(const std::vector<int>& vec, const int& d) {
    std::queue<int> que;
    long long minSum = 0;
    int min = vec[0];
    que.push(vec[0]);

    for (int i = 1; i < d; i++) {
        if (vec[i] < min) {
            min = vec[i];
        }
        que.push(vec[i]);
    }
    minSum += min;


    for (int i = d; i < vec.size(); i++) {
        que.pop();
        que.push(vec[i]);
        if (vec[i] < min) {
            min = vec[i];
        }
        else {
            if (index <= i - d) {
                min = minimalElInQueue(que, i-d);
            }
        }
        minSum += min;
    }
    return minSum;
}

int main() {

    int size;
    std::cin >> size;

    int d;
    std::cin >> d;

    std::vector<int> vec(size);
    for (int i = 0; i < size; i++) {
        std::cin >> vec[i];
    }

    std::cout << minimalRangeSum(vec, d);

    return 0;
}