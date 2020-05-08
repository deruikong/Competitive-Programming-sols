//
// Created by RayKo on 2020-03-16.
//

#include <bits/stdc++.h>
#pragma unmanaged
#define ll long long int
using namespace std;

struct pair_hash {
    template<class T1, class T2>
    std::size_t operator()(const std::pair<T1, T2> &p) const {
        auto h1 = std::hash<T1>{}(p.first);
        auto h2 = std::hash<T2>{}(p.second);
        return h1 ^ h2;
    }
};

int ipow(int base, int exp) {
    int result = 1;
    for (;;) {
        if (exp & 1)result *= base;
        exp >>= 1;
        if (!exp)break;
        base *= base;
    }
    return result;
}

int gcd(int a, int b) {
    return a == 0 ? b : (b % a, a);
}

int setbits(unsigned long long int a){return __builtin_popcountll(a);}


int main() {
    cout << setbits(1234567890);
    return 0;
};
