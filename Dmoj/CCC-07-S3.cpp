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
vector<int> adj[10001];
void bfs(int u, int v){
    vector<bool> vis(10000, 0);vis[u] = true;
    list<pii> q; q.emplace_back(u, -1);
    while(!q.empty()){
        pii cur = q.front();q.pop_front();
        if(cur.first == v && cur.second != -1){
            printf("Yes %d\n", cur.second);
            return;
        }
        cur.second++;
        for(int x:adj[cur.first]){
            if(!vis[x])vis[x] = true, q.emplace_back(x, cur.second);
        }
    }
    printf("No\n");
}

int main(){
    int N,a;
    scanf("%d", &N);
    REP(i, 1, N){
        int u, v;
        scanf("%d%d", &u, &v);
        adj[u].push_back(v);
    }
    int u, v;
    scanf("%d%d", &u, &v);
    while(u != v){
        bfs(u, v);
        scanf("%d%d", &u, &v);
    }
    return 0;
}