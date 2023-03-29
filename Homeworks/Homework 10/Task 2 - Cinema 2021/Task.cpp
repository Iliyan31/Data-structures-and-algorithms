#include <iostream>
#include <vector>
#include <queue>
#include <stack>
#include <utility>

const int MAX_SIZE = 1000;
std::vector<std::vector<int>> adjList;
//bool visited[MAX_SIZE]{ 0 };

int main() {
    int N, M, time, K;
    std::cin >> N >> M >> time >> K;
    for (int i = 0; i < N; i++) {
        std::vector<int> v;
        for (int j = 0; j < M; j++) {
            v.push_back(0);
        }
        adjList.push_back(v);
    }

    std::pair<int, int> p;
    std::queue<std::pair<int, int>> que;

    int num1, num2, sum = 0;
    for (int i = 0; i < K; i++) {
        std::cin >> num1 >> num2;
        num1 -= 1;
        num2 -= 1;
        adjList[num1][num2] = 1;
        p.first = num1;
        p.second = num2;
        que.push(p);
        sum++;
    }

    std::stack<std::pair<int, int>> stk;
    for (int i = 0; i < time; i++) {
        while (!que.empty()) { 
            num1 = que.front().first;
            num2 = que.front().second;
            que.pop();
            if (num1 - 1 >= 0 && adjList[num1 - 1][num2] == 0 ) {
                adjList[num1 - 1][num2] = 1;
                sum++;
                p.first = num1 - 1;
                p.second = num2;
                stk.push(p);
            }
            if (num1 + 1 < N && adjList[num1 + 1][num2] == 0 ) {
                adjList[num1 + 1][num2] = 1;
                sum++;
                p.first = num1 + 1;
                p.second = num2;
                stk.push(p);
            }
            if (num2 - 1 >= 0 && adjList[num1][num2 - 1] == 0 ) {
                adjList[num1][num2 - 1] = 1;
                sum++;
                p.first = num1;
                p.second = num2 - 1;
                stk.push(p);
            }
            if (num2 + 1 < M && adjList[num1][num2 + 1] == 0 ) {
                adjList[num1][num2 + 1] = 1;
                sum++;
                p.first = num1;
                p.second = num2 + 1;
                stk.push(p);
            }
        }

        while (!stk.empty()) {
            que.push(stk.top());
            stk.pop();
        }
    }

    std::cout << N * M - sum;

    return 0;
}