//
// Created by RayKo on 2020-03-15.
//

#include <bits/stdc++.h>
#define INF 0x3f3f3f3f
#define ll long long int
using namespace std;

int apple(int N, int B, int S){
    int tot = 0;
    if(B==1){
        return 1;
    }
    for(int i = S; i <= N; i++){
        if(N-i < i) break;
        tot += apple(N-i, B-1, i);
    }
    return tot;
}

int main() {
    int t, N, K;
    scanf("%d", &t);
    for(int i = 0; i< t; i++){scanf("%d%d", &N, &K);printf("%d\n", apple(N, K, 0));}
    return 0;
};
