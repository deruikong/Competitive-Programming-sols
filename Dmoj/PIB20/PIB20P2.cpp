//
// Created by RayKo on 2020-03-14.
//

#include <bits/stdc++.h>

#define ll unsigned long long int
using namespace std;
ll N;

bool good(ll v){
    return v/2-v/7 <= N;
}

int main() {
    scanf("%lld", &N);
    ll lo = 0, hi = 10*N, best;
    for(int i = 0;i<100;i++){
        ll mid = (hi+lo)/2;
        if(good(mid))lo = mid;
        else hi = mid-1;
    }
    for(ll i = lo; i<lo+100000;i++){
        if(good(i))best = i;
    }
    printf("%lld", best);
    return 0;
};
