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
map<int, int> adj[1002];

void dijk(){
	vector<int> dist(N+1, INF);
	priority_queue<pii, vector<pii>, greater<pii>> q;
	dist[1] = 0;
	q.emplace(0, 1);
	while(!q.empty()){
		int u = q.top().second;q.pop();
		for(pii v: adj[u]){
			if(dist[v.first] > dist[u]+v.second){
		 		dist[v.first] = dist[u]+v.second;
		 		q.emplace(dist[v.first], v.first);
			}
		}
	}
	REP(i, 1, N){
		if(dist[i] == INF)dist[i] = -1;
		printf("%d\n", dist[i]);
	}
}

int main(){
	scanf("%d%d", &N, &M);
	REP(i, 1, M){
		int u, v, w;
		scanf("%d%d%d", &u, &v, &w);
		if(adj[u].find(v) != adj[u].end()){
			adj[u][v] = min(adj[u][v], w);
			adj[v][u] = min(adj[v][u], w);
		}
		else{
			adj[u][v] = w;
			adj[v][u] = w;
		}
	}
	dijk();
    return 0;
}