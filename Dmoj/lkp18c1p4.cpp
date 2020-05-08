#ifdef ray
#include "bits/stdc++.h"
#else
#include <bits/stdc++.h>
#endif
#define scan(x) do{while((x=getchar())<'0'); for(x-='0'; '0'<=(_=getchar()); x=(x<<3)+(x<<1)+_-'0');}while(0)
#define LINF 0x3f3f3f3f3f3f3f3f
#define INF 0x3f3f3f3f
#define ll long long
#define ull unsigned long long
#define pii pair<int, int>
#define pll pair<ll, ll>
#define pdd pair<double, double>
#define REP(i,a,b) for (int i = int(a); i <= int(b); i++)
using namespace std;
struct e{
	int i, v;
	ll w;
	bool operator<(const e &b) const{
		return w > b.w;
	}
};

char _;
int N, M, A, B;
ll C;
vector<e> adj[100001];

bool dijk(int lvl){
	vector<ll> dist(N + 1, LINF);dist[A] = 0;
	vector<bool> vis(N + 1, false);
	priority_queue<pair<ll, int>> q; q.emplace(0, A);
	while(!q.empty()){
		int u = q.top().second; q.pop();
		if(vis[u]) continue;
		vis[u] = true;
		for(e p : adj[u]){
			if(p.i > lvl)
				continue;
			if(dist[u] + p.w < dist[p.v]){
				dist[p.v] = dist[u] + p.w;
				q.emplace(-dist[p.v], p.v);
			}
		}
	}
	return dist[B] < C;
}

int main(){
	scan(N);scan(M);
	REP(i, 0, M -1){
		int u, v, w;
		scan(u);scan(v);scan(w);
		adj[u].push_back(e{i, v, w});
		adj[v].push_back(e{i, u, w});
	}
	scan(A);scan(B);scan(C);
	int l = 0, r = M - 1;
	while(l < r){
		int mid = (l + r) / 2;
		if(dijk(mid)){
			r = mid;
		}
		else
			l = mid + 1;
	}
	if(dijk(r))cout << r+1;
	else cout << -1;
	return 0;
}