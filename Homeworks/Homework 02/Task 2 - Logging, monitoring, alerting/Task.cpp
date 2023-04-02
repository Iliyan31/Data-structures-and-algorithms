#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <utility>

std::string stringTransformPart2(std::string& str) {
    int count = 0;
    int size1 = str.length();
    std::string s1, s2, s3;

    for (int i = 0; i < size1; i++) {
        if (count == 0 && str[i] != '.') {
            s1 += str[i];
            continue;
        }
        if (count == 1 && str[i] != '.') {
            s2 += str[i];
            continue;
        }
        if (count == 2 && str[i] != '.') {
            s3 += str[i];
            continue;
        }
        if (str[i] == '.') count++;
    }
    return str = s3 + '.' + s2 + '.' + s1;
}

std::string stringTransformPart1(std::string& str) {
    std::string s1, s2;
    bool flag = false;
    int size1 = str.length();
    for (int i = 0; i < size1 ; i++) {
        if (str[i] != ' ' && flag == false) {
            s1 += str[i];
            continue;
        }
        if (str[i] != ' ' && flag == true) {
            s2 += str[i];
            continue;
        }
        if (str[i] == ' ') {
            flag = true;
        }
    }
    
    str.clear();

    str = stringTransformPart2(s2) + ' ' + s1;
    return str;
}

int main() {
    
    int size;
    std::cin >> size;
    std::cin.ignore();

    std::pair<std::string, int> p;
    std::vector<std::pair<std::string, int>> vec;
    std::string str;
    int count = 1;


    for (int i = 0; i < size; i++) {
        std::getline(std::cin, str);
        p.first = stringTransformPart1(str);
        p.second = count++;
        vec.push_back(p);
    }

    std::sort(vec.begin(), vec.end());

    for (int i = 0; i < size; i++) {
        std::cout << vec[i].second << std::endl;
    }

    return 0;
}