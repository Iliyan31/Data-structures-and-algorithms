#include <iostream>
#include <vector>
#include <algorithm>

struct Queries {
    int Si;
    int Pi;
    int counter;
};

int func2(const Queries& q, const std::vector<long long>& temp, const int& index) {          
    
    int tempNum = 0;
    int sizeT = temp.size();
    if (temp[index] < q.Si) {
        tempNum = -1;
        return index - tempNum;
    }
    
    for (int i = index; i >= 0; i--) {
        if (temp[index] - temp[i] > q.Si) {
            tempNum = i + 1;
            break;
        }
    }
    
    return index - tempNum;
}

void func(std::vector<int>& vec, std::vector<Queries>& queries) {
    std::sort(vec.begin(), vec.end());

    std::vector<long long> temp;
    temp.push_back(vec[0]);

    for (int i = 1; i < vec.size(); i++) {
        temp.push_back(vec[i] + temp[i - 1]);
    }

    int sizeQ = queries.size();
    for (int i = 0; i < sizeQ; i++) {
        auto num = std::upper_bound(vec.begin(), vec.end(), queries[i].Pi);
        int index = num - vec.begin() - 1;
        queries[i].counter = func2(queries[i],temp,index);
    }
}

int main() {

    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int size1, size2;
    scanf("%d", &size1);
    scanf("%d", &size2);

    std::vector<int> vec;
    std::vector<Queries> queries;

    int num;
    for (int i = 0; i < size1; i++) {
        scanf("%d", &num);
        vec.push_back(num);
    }

    Queries q;
    for (int i = 0; i < size2; i++) {
        scanf("%d", &q.Si);
        scanf("%d", &q.Pi);
        queries.push_back(q);
    }

    func(vec, queries);

    for (int i = 0; i < size2; i++) {
        printf("%d\n", queries[i].counter);
    }

    return 0;
}