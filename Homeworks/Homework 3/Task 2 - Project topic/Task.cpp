
#include <iostream>
#include <vector>
#include <algorithm>

struct Team {
    unsigned int members;
    unsigned int position;
    unsigned int task;
};

unsigned int getClosest(unsigned int num1, unsigned int num2, unsigned int target) {
    if (target - num1 > num2 - target) return num2;
    if (target - num1 == num2 - target) return num1;
    return num1;
}

unsigned int findClosest(std::vector<unsigned int> tasks, unsigned int number) {

    int size = tasks.size();
    if (number <= tasks[0]) return tasks[0];
    if (number >= tasks[size - 1]) return tasks[size - 1];


    unsigned int i = 0, j = size, mid = 0;

    while (i < j) {
        mid = (i + j) / 2;
        if (tasks[mid] == number) return tasks[mid];
        if (number < tasks[mid]) {
            if (mid > 0 && number > tasks[mid - 1]) {
                return getClosest(tasks[mid - 1], tasks[mid], number);
            }
            j = mid;
        }

        else {
            if (mid < size - 1 && number < tasks[mid + 1]) {
                return getClosest(tasks[mid], tasks[mid + 1], number);
            }    
            i = mid + 1;
        }
    }
    return tasks[mid];
}



void func(std::vector<Team>& vec, std::vector<unsigned int> tasks) {

    std::sort(tasks.begin(), tasks.end());

    int size = vec.size();
    for (int i = 0; i < size; i++) {
        vec[i].task = findClosest(tasks, vec[i].members);
    }

    for (int i = 0; i < vec.size(); i++) {
        std::cout << vec[i].task << std::endl;
    }
}

int main() {

    int size1, size2;
    std::cin >> size1 >> size2;

    std::vector<Team> vec;
    std::vector<unsigned int> tasks;

    unsigned int task;
    for (int i = 0; i < size1; i++) {
        std::cin >> task;
        tasks.push_back(task);
    }

    Team t;
    for (int i = 0; i < size2; i++) {
        std::cin >> t.members;
        t.position = i + 1;
        vec.push_back(t);
    }

    func(vec, tasks);

    return 0;
}