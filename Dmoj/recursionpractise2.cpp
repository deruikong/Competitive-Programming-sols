//
// Created by RayKo on 2020-03-16.
//

#include <bits/stdc++.h>

#define ll long long int
using namespace std;

int mat(int a){
    if(a<1)return 0;
    if(a<4)return 1;
    if(a==4)return 2;
    return mat(a-1)+mat(a-4);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int N;
    scanf("%d", &N);
    printf("%d", mat(N));
    return 0;
};
