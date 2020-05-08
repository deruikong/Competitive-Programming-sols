//
// Created by RayKo on 2020-03-16.
//

#include <bits/stdc++.h>
int N;
#define ll long long int
using namespace std;
vector<vector<int>> output(1000, vector<int>(1000));
void pascal(int i, int j){
    if(i==j || j==0)output[i][j] = 1;
    else output[i][j] = (output[i-1][j-1]+output[i-1][j]);
}

int main() {
    scanf("%d", &N);
    for(int i = 0; i<N;i++){
        for(int j = 0; j <= i; j++)pascal(i, j);
    }
    for(int i = 0; i<N;i++){
        for(int j = 0; j<=i;j++){
            printf("%d", output[i][j]);
            if(i!=j-1)printf(" ");
        }
        if(i!=N-1)printf("\n");
    }
    return 0;
};
