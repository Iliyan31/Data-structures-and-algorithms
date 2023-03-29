#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <set>
#include <iterator>
#include <string>
using namespace std;

std::set<std::string> s;

void fillSetWithMasks(const std::string& str, int index) {
    if (str[index] == '0') {
        fillSetWithMasks(str, index + 1);
    }
    if (str[index] == '1') {
        std::string st = str;
        st[index] = '0';
        s.insert(st);
        fillSetWithMasks(str, index + 1);
        fillSetWithMasks(st, index + 1);
    }
    if (index > 31) return;
}

void getBinary(std::string& str, const long long& num) {
    long long n = num;
    for (int i = 0; n > 0; i++) {
        str += (n % 2) + '0';
        n /= 2;
    }
    for (int i = str.length(); str.length() < 32; i++) {
        str += '0';
    }
    std::reverse(str.begin(), str.end());

}

long long uniqueMasks(const std::vector<long long>& vec) {
   
    int sizeVec = vec.size();
    for (int i = 0; i < sizeVec; i++) {
        std::string str;
        getBinary(str, vec[i]);
        s.insert(str);
        fillSetWithMasks(str,0);
    }

    return s.size();
}

int main() {
    int size;
    std::cin >> size;

    std::vector<long long> vec(size);
    for (int i = 0; i < size; i++) {
        std::cin >> vec[i];
    }

    std::cout << uniqueMasks(vec);
    return 0;
}