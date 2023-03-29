#include <iostream>
#include <vector>
#include <utility>
#include <queue>
#include <climits>
#include <set>
typedef long long LL;

const LL MAX_SIZE = 5e5 + 1;
std::vector<std::vector<std::pair<LL, LL>>> adjList(MAX_SIZE);
std::vector<std::pair<LL, LL>> distance(MAX_SIZE, { LLONG_MAX, 0 });

void DijkstraAlgorithm(const LL& startVertice) {
    distance[startVertice].first = 0;
    distance[startVertice].second = 1 % LL(1e9 + 7);

    std::priority_queue<std::pair<LL, LL>, std::vector<std::pair<LL, LL>>, std::greater<std::pair<LL, LL>>> priorQue;
    priorQue.push(std::make_pair(0, startVertice));

    while (!priorQue.empty()) {
        LL current = priorQue.top().second;
        LL weight = priorQue.top().first;
        priorQue.pop();
        for (auto it : adjList[current]) {
            LL newVertice = it.first;
            LL weightNewVertice = it.second;

            if (distance[newVertice].first > weight + weightNewVertice) {
                distance[newVertice].first = weight + weightNewVertice;
                distance[newVertice].second = distance[current].second % LL(1e9 + 7);
                priorQue.push({ weight + weightNewVertice, newVertice });
            }
            else if (distance[newVertice].first == weight + weightNewVertice) {
                distance[newVertice].second += distance[current].second % LL(1e9 + 7);
            }
        }
    }
}


int main() {
    LL vertices, edges;
    std::cin >> vertices >> edges;

    LL start, end, weight;
    for (int i = 0; i < edges; i++) {
        std::cin >> start >> end >> weight;
        adjList[start].push_back({ end, weight });
    }

    const LL startVertice = 1;
    DijkstraAlgorithm(startVertice);

    if (distance[vertices].second != 0 ) {
        std::cout << distance[vertices].first << " " << distance[vertices].second % LL(1e9 + 7);
    }
    else {
        std::cout << "-1 0";
    }

    return 0;
}