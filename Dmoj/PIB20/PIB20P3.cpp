//
// Created by RayKo on 2020-03-14.
//

#include <bits/stdc++.h>
#define maxn 1000005
#define ll long long int
#define pii pair<int,int>
using namespace std;
int N;

vector<pii> ds;

int main() {
    scanf("%d", &N);
    int prev, i = 0;
    while(N-->0){
        int cur;
        scanf("%d", &cur);
        if(cur == 1){
            if(!ds.empty()) for(int j = prev; j < i; j++)ds[j].second = ds.back().first;
            ds.emplace_back(1, -1);
            prev = i;
            i++;
        }
        else if(cur == 2){
            ds.emplace_back(ds.back().first^1, -1);
            i++;
        }
        else{
            if(ds.back().second == -1)
            {
                for(int j = prev; j < i; j++){
                    ds[j].second = ds.back().first;
                }
            }
            prev = i+1;
            int idx;
            scanf("%d", &idx);
            idx--;
            printf("%d\n", ds[idx].first==ds[idx].second);
        }
    }
    return 0;
};
