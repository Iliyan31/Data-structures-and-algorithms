#include <iostream>
#include <vector>

const int MAX_SIZE = 100000;
std::vector<int> adjList[MAX_SIZE];
int visited[MAX_SIZE]{ 0 };

bool dfs(const int& v, bool& flag) {
    visited[v] = 1;
    for (int u : adjList[v]) {
        if (visited[u] == 0) {
            if (dfs(u, flag)) return true;
        }
        else if (visited[u] == 1) {
            flag = true;
            return true;
        }
    }
    visited[v] = 2;
    return false;
}

void func(bool& hasCycle) {
    bool flag = false;
    for (int v = 0; v < MAX_SIZE; v++) {
        if (visited[v] == 0 && dfs(v, flag))
            break;
    }
    if (flag) hasCycle = true;
}

void clearFunction() {
    for (int i = 0; i < MAX_SIZE; i++) {
        adjList[i].clear();
        visited[i] = 0;
    }
}

int main() {

    int numberOfGraphs;
    std::cin >> numberOfGraphs;
    bool* arr = new bool[numberOfGraphs];


    for (int j = 0; j < numberOfGraphs; j++) {
        int size;
        std::cin >> size;

        int from, to;
        bool hasCycle = false;

        for (int i = 0; i < size; i++) {
            std::cin >> from >> to;
            adjList[from].push_back(to);
        }
        func(hasCycle);
        clearFunction();

        if (hasCycle) arr[j] = true;
        else  arr[j] = false;     
    }

    for (int i = 0; i < numberOfGraphs; i++) {
        std::cout << arr[i] << " ";
    }

    delete[] arr;

    return 0;
}