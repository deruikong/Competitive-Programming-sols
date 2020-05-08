//
// Created by RayKo on 2020-03-16.
//

#include <bits/stdc++.h>
#define ll long long int
#define pii pair<int,int>
#define INF 0x3f3f3f3f
using namespace std;
// normal knapsack
// int N, K;
// vector<vector<int>> ar(21, vector<int>(1001, 0));

// int main() {
//     scanf("%d%d", &N, &K);
//     for(int i = 1; i<=N; i++){
//         int w, v;
//         scanf("%d%d", &v, &w);
//         for(int j = w; j < 1001; j++){
//             ar[i][j] = max(ar[i-1][j], ar[i-1][j-w]+v);
//         }
//     }
//     cout <<ar[N][K] << endl;
//     return 0;
// };

//unbounded knapsack;
int N, K;

int main(){
    int T;
    scanf("%d", &T);
    while(T--){
        scanf("%d%d", &N, &K);
        vector<int> a(K+1, (int)1e9);
        a[0] = 0;
        for(int j = 1; j <= K; j++){
            int c;
            scanf("%d", &c);
            if(c == -1)continue;
            for(int i = j; i <= K; i++){
                a[i] = min(a[i], a[i-j]+c);
            }
        }
        if(a[K] == 1e9)printf("-1\n");
        else printf("%d\n", a[K]);
    }
    return 0;
}