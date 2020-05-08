//
// Created by RayKo on 2020-03-16.
//

#include <bits/stdc++.h>

#define ll long long int
using namespace std;
int N, K;
vector<int> ar;

bool addup(int a, int b, int idx){
    if(b==0)return K==a;
    if(idx == N)return false;
    return max(addup(a+ar[idx],b-1, idx+1),addup(a,b, idx+1));
}

int main() {
    scanf("%d%d", &N, &K);
    for(int i = 0; i<N; i++){int cur; scanf("%d", &cur), ar.push_back(cur);}
    sort(ar.begin(), ar.end());
    addup(0, 4, 0)?printf("YES"):printf("NO");
    return 0;
};
