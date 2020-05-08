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
int N, M, B, Q, dist[2002];
map<int, int> adj[2002];

void dijk(){
	vector<bool> vis(N+2, false);
	priority_queue<pii> q;
	q.emplace(0, B);
	dist[B] = 0;
	while(!q.empty()){
		int u = q.top().second;q.pop();
		if(vis[u])continue;
		vis[u] = true;
		for(pii i : adj[u]){
			int v = i.first, w = i.second;
			if(dist[v] > dist[u] + w){
				dist[v] = dist[u]+w;
				q.emplace(-dist[v], v);
			}
		}
	}
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin >> N >> M >> B >> Q;
	memset(dist, INF, sizeof(dist));
	REP(i, 1, M){
		int u, v, w;
		cin >> u >> v >> w;
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
	REP(i, 1, Q){
		int idx;
		cin >> idx;
		if(dist[idx] == INF)cout << -1 << endl;
		else cout << dist[idx] << endl;
	}
	return 0;
}