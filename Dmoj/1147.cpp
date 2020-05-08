//
// Created by RayKo on 2020-03-19.
//

#include <bits/stdc++.h>

#define ll long long int
using namespace std;
int N;
int a[100][101];
int b[100][101];

int tr(int r, int c){
    if(r == N-1)b[r][c]=a[r][c];
    if(b[r][c] == -1)b[r][c] = a[r][c]+max(tr(r+1, c),tr(r+1, c+1));
    return b[r][c];
}

int main() {
    scanf("%d",&N);
    for(int i = 0; i < N; i++){
        memset(b[i], -1, N*sizeof(a[0][0]));
        for(int j = 0; j <= i; j++)scanf("%d", &a[i][j]);
    }
    printf("%d", tr(0,0));
    return 0;
};
