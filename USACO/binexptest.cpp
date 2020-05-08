//
// Created by RayKo on 2020-02-25.
//

#include <bits/stdc++.h>
using namespace std;

long long binpow(vector<long long a, long long b) {
    if (b == 0)
        return 1;
    long long res = binpow(a, b / 2);
    if (b % 2)
        return res * res * a;
    else
        return res * res;
}

int main() {
    cout << binpow(2,8);
    return 0;
};
