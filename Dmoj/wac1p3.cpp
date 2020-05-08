#include <bits/stdc++.h>
#define INF 0x3f3f3f3f
#define ll long long
#define ull unsigned long long
#define pii pair<int, int>
#define pll pair<ll, ll>
#define pdd pair<double, double>
using namespace std;

struct tree{
    int par;
    vector<int> child;
};

int N, M, K, vis[100001];
vector<tree> t;
vector<pii> d;

void dfs(int idx, int depth){
    if(t[idx].child.empty()){
        d.emplace_back(depth, idx);
        return;
    }
    for(auto& c: t[idx].child)dfs(c, depth+1);
}

int getdis(int idx){
    int dis = 0;
    while(!vis[idx]){
        vis[idx] = true;
        dis++;
        idx = t[idx].par;
    }
    return dis;
}

int main(){
    memset(vis, false, sizeof(vis));
    scanf("%d%d%d", &N, &M, &K);
    vector<int> ap(K);
    t.push_back(tree{0});
    for (int i = 1; i < N; i++)
    {
        int par;
        scanf("%d", &par);
        t[par-1].child.push_back(i);
        t.push_back(tree{par-1});
    }
    dfs(0, 0);
    sort(d.rbegin(),d.rend());
    for(int i = 0; i < K; i++){
        if(d.size() > i)ap[i] = getdis(d[i].second);
        else ap[i] = 0;
    }
    sort(ap.rbegin(), ap.rend());
    for(int i = 0; i < M; i++){printf("%d", ap[i%K]);i!=M-1?printf(" "):printf("\n");}
    return 0;
}