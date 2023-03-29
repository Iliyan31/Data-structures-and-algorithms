#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

void func(char* str) {
    std::string s1, s2, s3;
    for (int i = 0; str[i] != '\0'; i++) {
        if (str[i] >= '0' && str[i] <= '9') s1 += str[i];
        if (str[i] >= 'a' && str[i] <= 'z') s2 += str[i];
        if (str[i] >= 'A' && str[i] <= 'Z') s3 += str[i];
    }
    std::sort(s1.begin(), s1.end());
    std::sort(s2.begin(), s2.end());
    std::sort(s3.begin(), s3.end());

    std::string s = s1 + s2 + s3;
    std::cout << s;
}
  

int main() {
    int size;
    std::cin >> size;
    char* str = new char[size + 1];
    for (int i = 0; i < size; i++) {
        std::cin >> str[i];
    }
    str[size] = '\0';

    func(str);

    delete[] str;
    return 0;
}