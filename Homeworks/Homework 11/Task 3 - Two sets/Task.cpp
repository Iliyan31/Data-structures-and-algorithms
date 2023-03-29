#include <iostream>
#include <queue>
#include <unordered_set>
#include <algorithm>
#include <climits>

const int MAX_SIZE = 3e5 + 1;
std::vector<std::vector<std::pair<int, int>>> adjList(MAX_SIZE);
std::vector<int> distance(MAX_SIZE, INT_MAX);
std::vector<int> vec;

void findShortestPath(const int& startVertice) {
    distance[startVertice] = 0;

    std::priority_queue<std::pair<int, int>, std::vector<std::pair<int, int>>, std::greater<std::pair<int, int>>> priorQue;
    priorQue.push({ 0, startVertice });

    while (!priorQue.empty()) {
        int currentVertice = priorQue.top().second;
        int currentVerticeWeight = priorQue.top().first;
        priorQue.pop();

        for (auto it : adjList[currentVertice]) {
            int nextVertice = it.first;
            int nextVerticeWeight = it.second;

            if (distance[nextVertice] > currentVerticeWeight + nextVerticeWeight) {
                distance[nextVertice] = currentVerticeWeight + nextVerticeWeight;
                priorQue.push({ currentVerticeWeight + nextVerticeWeight, nextVertice });
            }
        }
    }
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    int vertices, edges;
    std::cin >> vertices >> edges;

    int start, end, weight;
    for (int i = 0; i < edges; i++) {
        std::cin >> start >> end >> weight;
        adjList[start].push_back({ end, weight });
        adjList[end].push_back({ start,weight });
    }

    int sizeT, num;
    std::cin >> sizeT;
    for (int i = 0; i < sizeT; i++) {
        std::cin >> num;
        vec.push_back(num);
    }

    for (int i = 0; i < vec.size(); i++) {
        adjList[MAX_SIZE - 1].push_back({ vec[i], 0 });
        adjList[vec[i]].push_back({ MAX_SIZE - 1,0 });
    }

    std::vector<int> result;

    int queriesSize;
    std::cin >> queriesSize;
    findShortestPath(MAX_SIZE - 1);


    for (int i = 0; i < queriesSize; i++) {
        std::cin >> num;
        result.push_back(distance[num]);
    }
    
    for (int i = 0; i < result.size(); i++) {
        std::cout << result[i] << "\n";
    }

    return 0;
}