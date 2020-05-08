#include <bits/stdc++.h>
#define INF 0x3f3f3f3f
#define ll long long
#define ull unsigned long long
#define pii pair<int, int>
#define pll pair<ll, ll>
#define pdd pair<double, double>
#define REP(i,a,b) for (int i = int(a); i <= int(b); i++)
using namespace std;
vector<int> adj[500001];
vector<int> ree, reee;

void down(int idx, int par){
    ree[idx] = 0;
    for(int child: adj[idx]){
        if(child==par)continue;
        down(child, idx);
        ree[idx] = max(ree[idx], ree[child]+1);
    }
}
void up(int idx, int par){
    int a = -1, b = -1;
    for(int child: adj[idx]){
        if(child==par)continue;
        if(ree[child] >= a)b=a, a= ree[child];
        else b = max(b, ree[child]);
    }
    for(int child: adj[idx]){
        if(child == par)continue;
        int l = a;
        if(ree[child] == l)l = b;
        reee[child] = 1 + max(reee[idx], l+1);
        up(child, idx);
    }
}
int main(){
    int N;
    scanf("%d", &N);
    ree.resize(N+1);
    reee.resize(N+1);
    REP(i, 1, N-1){
        int u, v;
        scanf("%d%d", &u, &v);
        adj[u].push_back(v), adj[v].push_back(u);
    }
    down(1, 0);
    up(1, 0);
    REP(i, 1, N)printf("%d\n", 1+max(ree[i], reee[i]));
}