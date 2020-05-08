//
// Created by RayKo on 2020-03-14.
//

#include <bits/stdc++.h>

#define ll long long int
using namespace std;

int main() {
    int N, tot = 0;
    scanf("%d", &N);
    for(int i = 0; i < N; i++){
        int cur;
        scanf("%d", &cur);
        if(cur > 0)tot++;
    }
    printf("%d", tot);
    return 0;
};
