//
// Created by RayKo on 2020-03-14.
//

#include <bits/stdc++.h>
#define maxn 1001
#define ll long long int
using namespace std;
int N;
int grid[maxn][maxn];
int arr[maxn];

int getmid(vector<int> arr){
    sort(arr.begin(), arr.end());
    if(arr.size()&1)return arr[arr.size()/2];
    return arr[arr.size()/2-1];
}

int main() {
    scanf("%d", &N);
    for(int i = 0; i < N; i++)for(int j = 0; j < N-1; j++)scanf("%d", &grid[i][j]);
    vector<int> mid;
    vector<vector<int>> n(N, vector<int>(N));
    for(int i = 0; i < N; i++)for(int j = 0; j < N; j++)!j?n[j][i]=0:n[j][i]=n[j-1][i]+grid[i][j-1];

    for(vector<int> x: n)mid.push_back(getmid(x));
    printf("YES\n");
    while(N-->0)printf("%d ", (-getmid(mid)));
    return 0;
};
