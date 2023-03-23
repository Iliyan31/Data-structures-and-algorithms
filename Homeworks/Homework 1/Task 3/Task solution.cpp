#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

bool validationWord(const std::string& word) {
    return (word.length() >= 1 && word.length() <= 100);
}

bool validationNumber(const size_t& number) {
    return (number >= 1 && number <= pow(10, 9));
}

int doExist(const std::string& word, size_t& number, const char letter) {
    int size = word.length();

    bool flag = false;
    int countLetters = 0;
    for (int i = 0; i < size; i++) {
        if (word[i] == letter) {
            flag = true;
            countLetters++;
        }
    }
    if (flag == false) return 0;

    int count = 0;
    while (number >= size) {
        count += countLetters;
        number -= size;
    }

    if (number > 0) {
        for (int i = 0; i < number; i++) {
            if (word[i] == letter) count++;
        }
    }
    return count;
}

int main() {
    std::string word;
    std::cin >> word;
    if (!validationWord(word)) return -1;

    size_t number;
    std::cin >> number;
    if (!validationNumber(number)) return -1;

    char letter;
    std::cin >> letter;

    std::cout << doExist(word, number, letter);

    return 0;
}