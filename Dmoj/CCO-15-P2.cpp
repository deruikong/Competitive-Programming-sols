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
int n, m;
vector<pii> adj[20];

void dijk(){
	int des = n-1;
	vector<bool> vis(n+1, false);
	vector<int> dist(n+1, -INF);
	priority_queue<pii> q;
	dist[0] = 0;
	q.emplace(0, 0);
	while(!q.empty()){
		int u = q.top().second; q.pop();
		if(vis[u])continue;
		vis[u] = true;
		for(auto pp : adj[u]){
			int v = pp.first, w = pp.second;
			if(dist[u] + w > dist[v]){
				dist[v] = dist[u] + w;
				// cout << v << " : " << dist[v] << endl;
				q.emplace(dist[v], v);
			}
		}
	}
	cout << dist[n-1];
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> n >> m;
	REP(i, 1, m){
		int u, v, w;
		cin >> u >> v >> w;
		adj[u].emplace_back(v, w);
	}
	dijk();
	return 0;
}