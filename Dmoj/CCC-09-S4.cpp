// uwu why tf adj matrix :blobree:
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
int N, T, Q, d, adj[5001][5002], p[5002];

int MD(vector<ll> dist, vector<bool> vis){
	ll MIN = LLONG_MAX;
	int idx;
	REP(v, 1, N){
		if(!vis[v] && dist[v] <= MIN){
			MIN = dist[v];
			idx = v;
		}
	}
	return idx;
}

void dijk(){
	vector<ll> dist(N+2, LLONG_MAX-100000);
	vector<bool> vis(N+1, false);
	dist[d] = 0;
	REP(i, 1, N){
		int u = MD(dist, vis);
		vis[u] = true;
		REP(v, 1, N){
			if(!vis[v] && adj[u][v] != INF && dist[v] > (dist[u] + adj[u][v])){
				dist[v] = dist[u]+adj[u][v];
			}
		}
	}
	ll res = LLONG_MAX;
	REP(i, 1, N){
		if(p[i] == -1)continue;
		res = min(res, dist[i] + p[i]);
	}
	cout << res << endl;
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> N >> T;
	memset(adj, INF, sizeof(adj));
	memset(p, -1, sizeof(p));
	REP(i, 1, T){
		int u, v, w;
		cin >> u >> v >> w;
		adj[u][v] = min(adj[u][v], w);
		adj[v][u] = min(adj[v][u], w);
	}
	cin >> Q;
	REP(i, 1, Q){
		int u, pp;
		cin >> u >> pp;
		p[u] = pp;
	}
	cin >> d;
	dijk();
	return 0;
}