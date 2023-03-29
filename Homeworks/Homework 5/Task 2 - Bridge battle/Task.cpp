#include <iostream>
#include <vector>
#include <stack>

void battle(const std::vector<int>& vec) {
    int size = vec.size();
    std::stack<int> s;
    std::stack<int> temp;

    for (int i = 0; i < size; i++) {
        if (vec[i] < 0 && s.size() == 0) {
            std::cout << vec[i] << " ";
            continue;
        }
        if (vec[i] >= 0) {
            s.push(vec[i]);
            continue;
        }
        if (vec[i] < 0 && s.size() != 0) {
            int warrior = abs(vec[i]);
            while (s.size()!=0 && warrior > s.top()) {
                s.pop();
            }
            if (vec[i] < 0 && s.size() == 0) {
                std::cout << vec[i] << " ";
                continue;
            }
            if (warrior < s.top()) {
                continue;
            }
            if (warrior == s.top()) {
                s.pop();
                continue;
            }
        }
    }
    if (s.size() != 0) {
        while (s.size()!=0) {
            temp.push(s.top());
            s.pop();
        }
        while (temp.size()!=0) {
            std::cout << temp.top() << " ";
            temp.pop();
        }
    }
}

int main() {
    int size;
    std::cin >> size;
    std::vector<int> vec(size);
    for (int i = 0; i < size; i++) {
        std::cin >> vec[i];
    }
    battle(vec);
    return 0;
}