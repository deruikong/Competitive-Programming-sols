//
// Created by RayKo on 2020-03-14.
//
//too hard
//:blobsad:
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

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    return 0;
};
