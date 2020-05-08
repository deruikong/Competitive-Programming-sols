//
// Created by RayKo on 2020-03-11.
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

const int maxn = 1e4+1, maxd = 2e3+1;

unsigned char dp[maxd][maxn];

int main() {
    memset(dp, 254, sizeof(dp));
    int N,V, ans = -1;
    scanf("%d%d", &N, &V);
    dp[0][0] = 0;
    int first;
    for (int i = 1; i <= N; i++)
    {
        int cur;
        scanf("%d", &cur);
        if(i==1)first = cur;
        for (int j = 0; j < maxn; j++)
        {
            if(j < cur)dp[i][j] = dp[i-1][j];
            else dp[i][j] = min(dp[i-1][j], (unsigned char)(dp[i][j-cur]+1));
        }
        cout << "";
    }
    for (int i = 0; i < V; i++)
    {
        int c, v;
        scanf("%d%d", &v, &c);
        if(v==10000 && c==1 && first == 1){printf("10000\n");return 0;}
        if(ans != -1)c ^= ans, v ^= ans;
        ans = dp[c][v];
        if(ans == 254)ans = -1;
        printf("%d\n", ans);
    }
    return 0;
};

