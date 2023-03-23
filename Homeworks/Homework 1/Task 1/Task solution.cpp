#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

bool validationWord(const std::string& word) {
    return (word.length() >= 1 && word.length() <= pow(10, 6));
}

bool validationLetters(const std::string& word) {
    for (int i = 0; i < word.length(); i++){
        if (word[i] < 'a' || word[i] > 'z') return false;
    }
    return true;
}

std::vector<int> reverse(const std::vector<int>& vec) {
    std::vector<int> vec3;
    for (int i = vec.size() - 1; i >= 0; i--) {
        vec3.push_back(vec[i]);
    }
    return vec3;
}

void func(const std::string& str, const char letter) {
    std::vector<int> vec;
    std::vector<int> vec2;

    int countLetter = 0;

    int count = 0;
    int sizeStr = str.length();
    for (int i = 0; i < sizeStr; i++) {
        if (str[i] != letter) {
            count++;
            vec.push_back(count);
        }
        else {
            countLetter++;
            count = 0;
            vec.push_back(count);
        }
    }
    
    count = 0;
    for (int i = sizeStr - 1; i >=0 ; i--) {
        if (str[i] != letter) {
            count++;
            vec2.push_back(count);
        }
        else {
            count = 0;
            vec2.push_back(count);
        }
    }
    std::vector<int> vec3 = reverse(vec2);

    int counter = 0;
    if (countLetter == 0) {
        for (int i = 0; i < vec.size(); i++) {
            std::cout << vec[i] << " ";
        }
    }
    else {
        for (int i = 0; i < vec.size(); i++) {
            if (vec[i] == 0) counter++;
            if (counter == 0) {
                std::cout << vec3[i] << " ";
            }
            else if (counter >= 1 && counter < countLetter) {
                if (vec[i] >= vec3[i]) std::cout << vec3[i] << " ";
                if (vec[i] < vec3[i]) std::cout << vec[i] << " ";
            }
            else {
                std::cout << vec[i] << " ";
            }
        }
    }
}


int main() {
    std::string word;
    std::cin >> word;
    if (!validationWord(word)) return -1;
    if (!validationLetters(word)) return -1;

    char letter;
    std::cin >> letter;

    func(word, letter);
    return 0;
}