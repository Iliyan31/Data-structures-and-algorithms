#include <iostream>

long long closestCube(const long long& prices) {
    long long i = 1;
    while ((++i) * i * i <= prices);
    --i;
    return i*i*i;
}

long long pricesBought(long long& prices) {
    long long count = 0;
    while (prices>0) {
        long long num = closestCube(prices);
        prices -= num;  
        count++;    
    }
    return count;
}

int main() {
    long long prices;
    std::cin >> prices;
    std::cout << pricesBought(prices);

    return 0;
}