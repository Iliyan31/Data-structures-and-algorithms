#include <iostream>
#include <utility>
#include <vector>
#include <algorithm>
#include <cmath>

struct Data {
    double efficiency;
    int time;
    int counter;
    double diameter;
};

void sumEfficiency(Data& d) {
    if (d.time == 0) d.time = 1;
    d.efficiency = ((d.diameter * d.diameter) / d.time);
}

bool Compare(const Data& d1, const Data& d2) {
    if (d1.efficiency > d2.efficiency) return true;
    else if (d1.efficiency < d2.efficiency) return false;
    else {
        return (d1.diameter > d2.diameter);
    }
}

int main() {
    int size;
    std::cin >> size;

    std::vector<struct Data> vec;
    Data d;
    for (int i = 0; i < size; i++) {
        std::cin >> d.diameter;
        std::cin >> d.time;
        d.counter = i + 1;
        sumEfficiency(d);
        vec.push_back(d);
    }

    std::sort(vec.begin(), vec.end(), Compare);

    for (int i = 0; i < size; i++) {
        std::cout << vec[i].counter << " ";
    }

    
    return 0;
}