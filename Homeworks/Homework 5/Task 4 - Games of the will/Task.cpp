#include <iostream>
#include <vector>
#include <stack>

void fillRange(std::vector<int>& range, const std::vector<int>& vec, const int& low, std::stack<int>& stk, const int& index) {
    while (!stk.empty() && (vec[stk.top()] >= vec[index + 1])) {
        if (vec[index + 1] > low) {
            if (range[index + 1] <= range[stk.top()] + 1) {
                range[index + 1] = range[stk.top()] + 1;
            }
        }
        stk.pop();
    }
}

void daysTillFinals(std::vector<int>& vec) {
    int sizeVec = vec.size();
    std::vector<int> range(sizeVec);
    std::stack<int> stk;
    const int firstDay = 0;
    stk.push(firstDay);
    
    int low = vec[0];
    int finalDay = 0;


    for (int i = 0; i < sizeVec - 1; i++) {

        if (vec[i + 1] > vec[i]) range[i + 1] = 1;
        if (low > vec[i + 1]) low = vec[i + 1];   

        fillRange(range, vec, low, stk, i);

        if (finalDay <= range[i+1]) finalDay = range[i+1];
        stk.push(i+1);
    }

    printf("%d\n", finalDay);
}

int main() {
    int size;
    std::cin >> size;

    std::vector<int> vec(size);
    for (int i = 0; i < size; i++) {
        std::cin >> vec[i];
    }
    
    daysTillFinals(vec);
    

    return 0;
}