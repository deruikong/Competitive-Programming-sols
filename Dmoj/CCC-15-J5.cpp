//
// Created by RayKo on 2020-03-04.
//

#include <bits/stdc++.h>
#define pii pair<int,int>
#define ll long long int
using namespace std;
map<pii, ll> dp;

ll comb(int a, int b){
    if(dp.find(make_pair(a,b))!=dp.end())return dp[make_pair(a,b)];
    if(b==1)return 1;
    if(a==b)return 1;
    if(a<b) return 0;
    dp[make_pair(a,b)] = comb(a-1, b-1)+comb(a-b, b);
    return dp[make_pair(a,b)];
}

int main() {
    int n, k;
    scanf("%d%d", &n, &k);
    printf("%lld", comb(n, k));
    return 0;
};
