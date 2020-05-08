//
// Created by RayKo on 2020-03-14.
//

#include <bits/stdc++.h>

#define ll long long int
using namespace std;
int n, k, ar[101];

struct pair_hash {
    template<class T1, class T2>
    std::size_t operator()(const std::pair<T1, T2> &p) const {
        auto h1 = std::hash<T1>{}(p.first);
        auto h2 = std::hash<T2>{}(p.second);
        return h1 ^ h2;
    }
};

bool subs(set<int> used){

    return false;
}

int main() {
    scanf("%d%d", &n, &k);
    for(int i = 0; i < n; i++)scanf("%d", &ar[i]);
    if(subs({}))printf("YES");
    else printf("NO");
    return 0;
};
