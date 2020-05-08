//
// Created by RayKo on 2020-03-22.
//

#include <bits/stdc++.h>

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

int gcd(int a, int b) { return a == 0 ? b : (b % a, a); }

int fpow(int base, int exp) {
    int result = 1;
    for (;;) {
        if (exp & 1)result *= base;
        exp >>= 1;
        if (!exp)break;
        base *= base;
    }
    return result;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int a, b;
    for(int i = 0; i < 10; i++)
    {
        cin >> a >> b;
        cout << a*2-1 << endl;
    }
    return 0;
};
