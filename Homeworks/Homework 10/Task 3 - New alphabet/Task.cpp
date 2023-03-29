#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>
#include <stack>

std::unordered_map<char, bool> visited;
std::unordered_map<char, std::vector<char>> adjList;
std::vector<std::string> vec;


std::stack<char> stk;
void DFS(const char& v) {
    visited[v] = 1;
    for (auto it : adjList[v]) {
        if (!visited[it]) DFS(it);
    }
    stk.push(v);
}


void topSort() {
    for (auto it : adjList) {
        char cur = it.first;
        if (!visited[cur]) DFS(cur);
    }
}

void func(const int& size, char& first) {
    bool flag = false;
    for (int i = 0; i < size - 1; i++) {

        int minSize = std::min(vec[i].length(), vec[i + 1].length());
        for (int j = 0; j < minSize; j++) {
            if (!flag) {
                first = vec[i][j];
                flag = true;
            }
            if (vec[i][j] != vec[i + 1][j]) {
                adjList[vec[i][j]].push_back(vec[i + 1][j]);
                break;
            }
        }
    }
}

void printOrder() {
    while (!stk.empty()) {
        std::cout << stk.top() << " ";
        stk.pop();
    }
}

int main() {
    int size;
    std::cin >> size;

    //for (int i = 0; i < 27; i++) {
    //    std::vector<char> v;
    //    adjList[i] = v;
    //}

    for (int i = 0; i < size; i++) {
        std::string str;
        std::cin.ignore();
        std::cin >> str;
        for (int j = 0; j < str.size(); j++) {
            adjList[str[j]] = std::vector<char>();
        }
        vec.push_back(str);
    }

    if (size == 1) {
        for (int i = 0; i < vec[0].size(); i++) {
            if (vec[0][i] != '\0') {
                std::cout << vec[0][i] << " ";
            }
        }
        return 0;
    }

    char first;
    func(size, first);
    //if (adjList.size() == 0) {
    //    return -1;
    //}
    topSort();
    printOrder();

    return 0;
}