#include <bits/stdc++.h>
#define INF 0x3f3f3f3f
#define ll long long
#define ull unsigned long long
#define pii pair<int, int>
#define pll pair<ll, ll>
#define pdd pair<double, double>
#define REP(i,a,b) for (int i = int(a); i <= int(b); i++)
using namespace std;
vector<pii> adj[200001];
vector<int> ree, reee;

void down(int idx, int par){
    ree[idx] = 0;
    for(pii child: adj[idx]){
        if(child.first==par)continue;
        down(child.first, idx);
        ree[idx] = max(ree[idx], ree[child.first]+child.second);
    }
}
void up(int idx, int par){
    int a = -1, b = -1;
    for(pii child: adj[idx]){
        if(child.first==par)continue;
        if(ree[child.first]+child.second >= a)b=a, a= ree[child.first]+child.second;
        else b = max(b, ree[child.first]+child.second);
    }
    for(pii child: adj[idx]){
        if(child.first == par)continue;
        int l = a;
        if(ree[child.first]+child.second == l)l = b;
        reee[child.first] = child.second + max(reee[idx], l);
        up(child.first, idx);
    }
}
int main(){
    int N, T, tot = 0;
    scanf("%d%d", &N, &T);
    ree.resize(N+1);
    reee.resize(N+1);
    REP(i, 1, N-1){
        int u, v, w;
        scanf("%d%d%d", &u, &v, &w);
        adj[u].emplace_back(v, w), adj[v].emplace_back(u, w);
        tot += 2*w;
    }
    down(1, 0);
    up(1, 0);
    REP(i, 1, N){
        if(adj[i].size() == T)printf("%d %d\n", i, tot-max(ree[i], reee[i]));
    }
}