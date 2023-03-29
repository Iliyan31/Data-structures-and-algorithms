#include <iostream>
#include <vector>

const int vecSize = 10000000;
std::vector<int> tree[vecSize];

void resentsPerPerson(const int& maxSize, std::vector<int>& results) {
    for (int i = maxSize; i > 0; i--) {
        if (tree[i].size() == 0) {
            results[i] = tree[i].size();
        }
        else {
            for (int j = 0; j < tree[i].size(); j++) {
                results[i] += results[tree[i][j]];
            }
            results[i] += tree[i].size();
        }
        
    }
}

int main() {
    int size;
    std::cin >> size;

    int num1, num2;
    std::cin >> num1 >> num2;
    tree[num1].push_back(num2);
    int begin = num1;

    int maxSize = 1;
    for (int i = 1; i < size - 1; i++) {
        std::cin >> num1 >> num2;
        tree[num1].push_back(num2);
        maxSize++;
    }

    std::vector<int> results(size,0);
    results[0] = size-1;

    resentsPerPerson(maxSize, results);
    for (int i = 0; i < results.size(); i++) {
        std::cout << results[i] << " ";
    }
}