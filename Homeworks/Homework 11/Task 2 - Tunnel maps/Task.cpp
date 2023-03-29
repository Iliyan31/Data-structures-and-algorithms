#include <iostream>
#include <vector>
#include <queue>    
#include <climits>
#include <algorithm>

typedef long long LL;

struct Road {
    LL end;
    LL kilos;
    LL time;
    Road() = default;
    Road(const LL& end, const LL& kilos, const LL& time) : end(end), kilos(kilos), time(time) {}
};

const LL MAX_SIZE = 3e5 + 1;
std::vector<std::vector<Road>> adjList(MAX_SIZE);
std::vector<LL> kilograms;
std::vector<LL> distance(MAX_SIZE, INT_MAX);


void findShortestPath(const LL& kilos) {
    distance[1] = 0;

    std::priority_queue<std::pair<LL, LL>, std::vector<std::pair<LL, LL>>, std::greater<std::pair<LL, LL>>> priorQue;
    priorQue.push({ 0,1 });
    while (!priorQue.empty()) {
        LL currentVertice = priorQue.top().second;
        priorQue.pop();
        for (auto it : adjList[currentVertice]) {
            LL nextVertice = it.end;
            LL nextVerticeBattery = it.time;
            LL nextVerticeKilos = it.kilos;

            if (distance[nextVertice] > distance[currentVertice] + nextVerticeBattery && nextVerticeKilos <= kilos) {
                distance[nextVertice] = distance[currentVertice] + nextVerticeBattery;
                priorQue.push({ distance[currentVertice] + nextVerticeBattery , nextVertice });
            }
        }
    }
}
void SearchBinary(const LL& battery, const LL& crossroads, LL left, LL right, LL& min) {
    LL answer = 2e10;
    while (left <= right) {
        LL middle = left + (right-left) / 2;
        findShortestPath(middle);

        if (distance[crossroads] > battery) {
            left = middle + 1;
        }
        else {
            answer = middle;
            right = middle - 1;
        }

        distance.clear();
        distance.assign(MAX_SIZE, INT_MAX);
    }
    if (answer != 2e10) {
        min = answer;
    }
}

void displayResult(const LL& min) {
    if (min != 1e9) std::cout << min;
    else std::cout << "-1";
}


int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);


    LL crossroads, tunnels, battery;
    std::cin >> crossroads >> tunnels >> battery;

    LL start, end, kilos, time;
    for (int i = 0; i < tunnels; i++) {
        std::cin >> start >> end >> kilos >> time;
        kilograms.push_back(kilos);
        Road r(end, kilos, time);
        adjList[start].push_back(r);
    }
    LL min = 1e9;

    SearchBinary(battery,crossroads, 0, 1e6+1, min);
    displayResult(min);

    return 0;
}