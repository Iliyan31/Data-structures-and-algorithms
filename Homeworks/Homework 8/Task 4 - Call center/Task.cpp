#include <iostream>
#include <queue>
#include <vector>
#include <set>

std::vector<std::pair<int, int>> vec;
std::vector<std::vector<int>> operators;

void bestOperators(const int& operatorsSize) {
    int sizeVec = vec.size();

    for (int i = operatorsSize; i < sizeVec; i++) {

        int index = (i % operatorsSize);

        bool flag = false;
        for (int j = index; j < operatorsSize; j++) {
            if (operators[j][0] <= vec[i].first) {
                operators[j][0] = vec[i].first + vec[i].second;
                operators[j][1]++;
                flag = true;
                break;
            }
        }

        if (flag == false) {
            for (int j = 0; j < index; j++) {
                if (operators[j][0] <= vec[i].first) {
                    operators[j][0] = vec[i].first + vec[i].second;
                    operators[j][1]++;
                    break;
                }
            }
        }
    }

    std::priority_queue<std::pair<int,int>> que;
    for (int i = 0; i < operatorsSize; i++) {
        que.push(std::make_pair(operators[i][1], i));
    }

    std::priority_queue<int, std::vector<int>, std::greater<int>> q;
    q.push(que.top().second);
    int temp = que.top().first;
    que.pop();

    while (!que.empty()) {
        if (que.top().first == temp) {
            q.push(que.top().second);
        }
        que.pop();
    }
    
    while (!q.empty()) {
        std::cout << q.top() << " ";
        q.pop();
    }

}

int main() {
    int clientsSize, operatorsSize;
    std::cin >> clientsSize >> operatorsSize;
    
    int num1, num2;
    for (int i = 0; i < clientsSize; i++) {
        std::cin >> num1 >> num2;
        vec.push_back(std::make_pair(num1, num2));
        if (i < operatorsSize) {
            std::vector<int> v;
            v.push_back(num1 + num2);
            v.push_back(1);
            operators.push_back(v);
        }
    }

    bestOperators(operatorsSize);

    return 0;
}