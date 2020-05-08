//
// Created by RayKo on 2020-03-15.
//

#include <bits/stdc++.h>

#define ll long long int
using namespace std;
int N, W;

ll fmin(const vector<int> &tmp){
    ll tot = 0;
    vector<int> cur = tmp;
    cur.push_back(W);
    sort(cur.begin(), cur.end());
    for(int i = 0; i < N; i++){
        tot += abs(cur[i]-cur[i+1]);
    }
    return tot;
}

ll fmax(const vector<int> &tmp, bool side){
    ll tot = 0;
    int l = 0, r = N-1;
    tot += side?abs(tmp[r]-W):abs(tmp[l]-W);
    while(l < r){
        tot+=max(abs(tmp[l]-tmp[r]), side?abs(tmp[l]-W):abs(tmp[r]-W));
        side?r--:l++;
        side^=1;
    }
    return tot;
}

int main() {
    scanf("%d%d", &N, &W);
    vector<int> ar(N);
    for(int i = 0; i < N; i++)scanf("%d", &ar[i]);
    sort(ar.begin(), ar.end());
    printf("%lld %lld",fmin(ar), max(fmax(ar, 0),fmax(ar, 1)));
    return 0;
}

