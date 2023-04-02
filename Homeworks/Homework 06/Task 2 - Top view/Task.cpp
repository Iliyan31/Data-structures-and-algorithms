#include <iostream>
#include <vector>

const int sizeVec = 1000000;
std::vector<int> vec[sizeVec];

int main() {
    int size;
    std::cin >> size;

    int x = 0, y = 0;
    vec[0].push_back(x);
    vec[0].push_back(y);
    for (int i = 0; i < size; i++) {
        int num1, num2;
        std::cin >> num1 >> num2;
        
        if (num1 != -1) {
            vec[num1].push_back(vec[i][0] - 1);
        }
        if (num2!= -1) {
            vec[num2].push_back(vec[i][0] + 1);
        }
    }

    std::vector<int> result;
    std::vector<int> temp;
    int plus = 0;
    int minus = 0;

    for (int i = 1; i < size; i++) {
        if (vec[i][0] < 0 && vec[i][0] < minus) {
            minus--;
            temp.push_back(i);
        }
    }

    for (int i = 0; i < temp.size(); i++) {
        result.push_back(temp[temp.size() - i - 1]);
    }

    result.push_back(0);

    for (int i = 1; i < size; i++) {
        if (vec[i][0] > 0 && vec[i][0] > plus) {
            plus++;
            result.push_back(i);
        }
    }

    for (int i = 0; i < result.size(); i++) {
        std::cout << result[i] << " ";
    }

    return 0;
}