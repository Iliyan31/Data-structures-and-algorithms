#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>

std::priority_queue<std::pair<int, int>, std::vector<std::pair<int, int>>, std::greater<std::pair<int, int>>> que;
std::vector<std::vector<int>> tasks;
std::vector<int> output;

void findMax(int& time, const int& count) {
    if (que.empty()) {
        if (time < tasks[count][0]) time = tasks[count][0];
    }
}

void fillPQueue(const int& time, int& count) {
    int taskSize = tasks.size();
    while (count < taskSize && time >= tasks[count][0]) {
        que.push(std::make_pair(tasks[count][1], tasks[count][2]));
        count++;
    }
}

void sumTime(int& time) {
    std::pair<int, int> temp = que.top();
    que.pop();
    time += temp.first;
    output.push_back(temp.second);
}


void func() {
    int taskSize = tasks.size();
    int time = 0, count = 0;

    std::sort(tasks.begin(), tasks.end());
    while (count < taskSize || !que.empty()) {
        findMax(time, count);
        fillPQueue(time, count);
        sumTime(time);
    }
    
    int outputSize = output.size();
    for (int i = 0; i < outputSize; i++) {
        std::cout << output[i] << " ";
    }
}

int main() {

    int size;
    std::cin >> size;

    for (int i = 0; i < size; i++) {
        std::vector<int> v;
        for (int j = 0; j < 2; j++) {
            int temp;
            std::cin >> temp;
            v.push_back(temp);
        }
        v.push_back(i);
        tasks.push_back(v);
    }

    func();

    return 0;
}