#include <iostream>
#include <queue>
#include <vector>
#include <iomanip>

std::priority_queue<double, std::vector<double>, std::greater<double>> big;
std::priority_queue<double> low;
std::vector<double> vec;

void trensferInBig(const int* arr, const int& index, const double& mid) {
    if (arr[index] < mid) {
        big.push(low.top());
        low.pop();
        low.push(arr[index]);
    }
    else {
        big.push(arr[index]);
    }
}

void trensferInLow(const int* arr, const int& index, const double& mid) {
    if (arr[index] > mid) {
        low.push(big.top());
        big.pop();
        big.push(arr[index]);
    }
    else {
        low.push(arr[index]);
    }
}

void findMidIfEqual(const int* arr, const int& index, double& mid) {
    if (arr[index] < mid) {
        low.push(arr[index]);
        mid = low.top();
    }
    else {
        big.push(arr[index]);
        mid = big.top();
    }
}

void findMedians(const int* arr, const int& size) {
    if (arr == nullptr) return;

    low.push(arr[0]);
    vec.push_back(arr[0]);

    double mid = vec[0];
    for (int i = 1; i < size; i++) {
        if (low.size() > big.size()) {
            trensferInBig(arr,i,mid);
            mid = (big.top() + low.top()) / 2;
        }
        else if (low.size() < big.size()) {
            trensferInLow(arr, i, mid);
            mid = (big.top() + low.top()) / 2;
        }
        else {
            findMidIfEqual(arr, i, mid);
        }
        vec.push_back(mid);
    }

    int sizeVec = vec.size();
    for (int i = 0; i < sizeVec; i++) {
        std::cout << std::fixed <<std::setprecision(1) << vec[i]  << "\n";
    }
}

int main() {

    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int size;
    std::cin >> size;
    
    int* arr = new int[size];
    for (int i = 0; i < size; i++) {
        std::cin >> arr[i];
    }

    findMedians(arr, size);

    delete[] arr;
    return 0;
}