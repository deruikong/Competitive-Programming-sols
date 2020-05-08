//
// Created by RayKo on 2020-03-20.
//

#include <bits/stdc++.h>
#define pii pair<int,int>
#define ll long long int
using namespace std;
int M, N, tot;
char grid[100][105];
int dp[100][101];

struct node{
    int a, b, d;
};


int dpbad(){
    for(int i = M-1; i >= 0; i--){
        if(grid[i][0] == '*')break;
        dp[i][0] = max(grid[i][0]-'0', 0)+((i==M-1)?0:dp[i+1][0]);
    }
    for(int i = 1; i < N; i++){
        for(int j = 0; j < M; j++){
            if(dp[j][i-1] >= 0){
                int cur = dp[j][i-1];
                for(int r = j; r < M; r++){
                    if(grid[r][i] != '*'){
                        cur += max(grid[r][i]-'0', 0);
                        dp[r][i] = max(cur, dp[r][i]);
                    }
                    else break;
                }
            }
        }
        for(int j = M-1; j >= 0; j--){
            if(dp[j][i-1] >= 0){
                int cur = dp[j][i-1];
                for(int r = j; r >= 0; r--){
                    if(grid[r][i] != '*'){
                        cur += max(grid[r][i]-'0', 0);
                        dp[r][i] = max(cur, dp[r][i]);
                    }
                    else break;
                }
            }
        }
    }
    return dp[M-1][N-1];
}


int main() {
    while(true) {
        scanf("%d%d", &M, &N);
        if(M==0 && N== 0)break;
        memset(dp, -1, sizeof(dp[0][0])*100*101);
        for (int i = 0; i < M; i++)scanf("%s", grid[i]);
        printf("%d\n", dpbad());
    }
    return 0;
};
