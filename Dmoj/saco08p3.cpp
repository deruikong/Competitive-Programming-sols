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
const int MOD = 1e6;
int N, M;
bool cookie[702];
set<pii> adj[703];

ll madd(ll a, ll b){return (a+b)%MOD;}

void dijk(int st){
	vector<vector<ll>> cnt(N + 1, {0, 0});
	vector<vector<int>> dist(N + 1, {INF, INF});
	vector<vector<bool>> vis(N+1, {false, false});
	priority_queue<pair<int, pii>> pq;
	pq.emplace(0, make_pair(1, cookie[1]?1:0));
	dist[1][cookie[1]] = 0;
	cnt[1][cookie[1]] = 1;
	while(!pq.empty()){
		int u = pq.top().second.first, t = -pq.top().first;
		bool o = pq.top().second.second;
		pq.pop();
		if(t > dist[u][o]) continue;
		// cout << u << " " << o << endl << cnt[u][o] << endl;
		// vis[u][o] = true;
		for(pii c : adj[u]){
			int v = c.first, w = c.second;
			bool x = o|cookie[v];
			// if(v == st)cout << dist[u][o] << endl;
			// if(u == st)cout <<  << endl;
			if(dist[v][x] > dist[u][o] + w){
				dist[v][x] = dist[u][o] + w;
				cnt[v][x] = cnt[u][o];
				pq.emplace(-dist[v][x], make_pair(v, x));
			}
			else if(dist[v][x] == dist[u][o] + w){
				cnt[v][x] = madd(cnt[v][x], cnt[u][o]);
			}
		}
	}
	// REP(i, 1, N){
	// 	cout << i << ":" << cnt[i][1] << "," << dist[i][1] << "  ";
	// }
	// cout << endl;
	cout << dist[st][1] << " " << cnt[st][1] << endl;
}

int main(){
	scanf("%d", &N);
	memset(cookie, false, sizeof(cookie));
	REP(u, 1, N){
		REP(v, 1, N){
			int w;
			scanf("%d", &w);
			if(u == v)continue;
			adj[u].insert(make_pair(v, w));
			adj[v].insert(make_pair(u, w));
		}
	}
	scanf("%d", &M);
	REP(i, 1, M){
		int idx;
		scanf("%d", &idx);
		cookie[idx] = true;
	}
	dijk(N);
	return 0;
} 