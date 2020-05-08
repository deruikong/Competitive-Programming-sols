//
// Created by RayKo on 2020-03-09.
//

#include <bits/stdc++.h>

#define ll long long int
using namespace std;

int dp[2000001] = {0};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int a;
    cin >> a;
    for(int i = 0; i<a; i++){
        int cur;
        cin >> cur;
        dp[cur]++;
    }
    ll res = 0;
    for(int i = 1; i < 2000001; i++){
        ll b = 0;
        for(int j = i; j < 2000001; j += i) b+=dp[j];
        if(b > 1){
            res = max(res, b*i);
        }
    }
    cout << res;
    return 0;
};
