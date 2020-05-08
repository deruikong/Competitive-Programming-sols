//
// Created by RayKo on 2020-03-12.
//

#include <bits/stdc++.h>
#define pii pair<int,int>
#define ll long long int
using namespace std;
int grid[25][26];
int N, M, C;


int solve()
{
    for(int i = 1; i < N; i++){
        for(int j = 1; j < M; j++){
            if(grid[i][j] == -1)continue;
            grid[i][j] = max(grid[i][j-1], 0)+max(grid[i-1][j], 0);
        }
    }
    return grid[N-1][M-1];
}

int main() {
    scanf("%d%d%d", &N, &M, &C);
    memset(grid, 0, sizeof(grid[0][0])*25*26);
    for(int i = 0; i < C; i++)
    {
        int r, c;
        scanf("%d%d", &r, &c);
        grid[r-1][c-1] = -1;
    }
    for(int i = 0; i < 25; i++){
        if(grid[0][i] == -1)break;
        grid[0][i] = 1;
    }

    for(int i = 0; i < 25; i++){
        if(grid[i][0] == -1)break;
        grid[i][0] = 1;
    }
    printf("%d", solve());
    return 0;
};
