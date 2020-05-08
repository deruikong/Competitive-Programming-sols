#ifdef ray
#include "bits/stdc++.h"
#else
#include <bits/stdc++.h>
#endif
#define INF 0x3f3f3f3f
#define ll long long
#define ull unsigned long long
#define pii pair<int, int>
#define pll pair<ll, ll>
#define pdd pair<double, double>
#define REP(i,a,b) for (int i = int(a); i <= int(b); i++)
using namespace std;
int N, M;
vector<int> adj[1000001];
bool vis[1000001];

bool dfs(int u, int v){
    if(u == v)return true;
    vis[u] = true;
    bool ret = false;
    for(int i: adj[u])
        if(!vis[i])ret = max(ret, dfs(i, v));
    return ret;
}

int main(){
    scanf("%d%d", &N, &M);
    REP(i, 1, M){
        int u, v;
        scanf("%d%d", &u, &v);
        adj[u].push_back(v);
    }
    int u, v;
    scanf("%d%d", &u, &v);
    if(memset(vis, false, sizeof(vis)) && dfs(u, v))printf("yes");
    else if(memset(vis, false, sizeof(vis)) && dfs(v, u))printf("no");
    else printf("unknown");
    return 0;
}