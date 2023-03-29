#include <algorithm>
#include <vector>
#include <string>
#include <iostream> 

const int MOD = 1e9 + 123;
long long BASE = 1e9 + 7;

struct Hash {
    std::vector<long long> vec;
    std::vector<long long> temp;


    Hash(const std::string& s) : vec(s.size() + 1, 0) {
        const int n = s.size();
        temp.push_back(1);
        while (temp.size() <= n) {
            temp.push_back(temp.back() * BASE % MOD);
        }
        for (int i = 0; i < n; ++i) {
            vec[i + 1] = (vec[i] + 1 * s[i] * temp[i]) % MOD;
        }
    }

    long long operator()(const int& pos, const int& len, const int& mxPow) const {
        //int num2 = pos + len;
        //if (num2 < vec.size()) {
            long long num = vec[pos + len] - vec[pos];
            if (num < 0) num += MOD;
            if (mxPow != 0) {
               // if (mxPow - (pos + len - 1) < temp.size()) {
                    num = num * temp[mxPow - (pos + len - 1)] % MOD;
                //}
            }
            return num;
        //}
        //return 0;
    }
};

int main() {
    size_t sizeGreaterString = 0;
    std::string primary, secondary;
    std::cin >> primary >> secondary;

    if (primary.size() >= secondary.size()) {
        sizeGreaterString = primary.size();
    }
    else {
        sizeGreaterString = secondary.size();
    }


    Hash str1(primary), str2(secondary);

    int pos = -1, low = 0, high = std::min(primary.size(), secondary.size()) + 1;
    while (high - low > 1) {
        int mid = (low + high) / 2;
        std::vector< long long> hashes;
        for (int i = 0; i + mid <= sizeGreaterString; i++) {
            hashes.push_back(str1(i, mid, sizeGreaterString));
        }
        std::sort(hashes.begin(), hashes.end());
        int p = -1;
        for (int i = 0; i + mid <= sizeGreaterString; i++) {
            if (std::binary_search(hashes.begin(), hashes.end(), str2(i, mid, sizeGreaterString))) {
                p = i;
                break;
            }
        }
        if (p >= 0) {
            low = mid;
            pos = p;
        }
        else {
            high = mid;
        }
    }

    if (pos > 0) {
         std::cout << secondary.substr(pos, low).size();
    }
   

    return 0;
}