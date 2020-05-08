#ifdef ray
#include "bits/stdc++.h"
#else
#include <bits/stdc++.h>
#endif
#define INF 0x3f3f3f3f
#define ll long long
#define ull unsigned long long
#define LINF 0x3f3f3f3f3f3f3f3f
#define pii pair<int, int>
#define pll pair<ll, ll>
#define pdd pair<double, double>
#define REP(i,a,b) for (int i = int(a); i <= int(b); i++)
using namespace std;

struct p{
	ll x, y;
};

int N, X, Q;
ll adj[3001][3001];
vector<ll> dist;
vector<bool> vis;

int MD(){
	int idx;
	ll MIN = LLONG_MAX;
	REP(v, 1, N){
		if(!vis[v] && dist[v] <= MIN){
			MIN = dist[v];
			idx = v;
		}
	}
	return idx;
}

void dijk(){;
	REP(i, 1, N){
		int u = MD();
		vis[u] = true;
		REP(v, 1, N){
			if(!vis[v] && dist[v] > (dist[u] + adj[u][v])){
				dist[v] = dist[u] + adj[u][v];
			}
		}
	}
	sort(next(dist.begin()), dist.end());
}
int solve(ll cur){
	int l = 1, r = N;
	while(l < r){
		int m = (l+r)/2;
		// cout << m << " " << r <<  endl;
		if(dist[m] <= cur){
			l = m;
		}
		else r = m - 1;
	}
	return l-1;
}

ll get(p a, p b){return abs(a.x-b.x) * abs(a.x-b.x) + abs(a.y-b.y) * abs(a.y-b.y);}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	cin >> N;
	vector<p> cnt(N+1);
	dist.resize(N+1), vis.resize(N+1);
	dist[0] = LINF;
	REP(i, 1, N){
		p c;
		cin >> c.x >> c.y;
		cnt[i] = c,	vis[i] = false, dist[i] = LINF;
	}
	REP(i, 1, N){
		REP(j, i, N){
			if(j==i)continue;
			adj[i][j] = get(cnt[i], cnt[j]);
			adj[j][i] = adj[i][j];
		}
	}
	// REP(i, 1, N){
	// 	REP(j, 1, N) cout << adj[i][j] <<" ";
	// 	cout << endl;
	// }
	cin >> X >> Q;
	dist[X] = 0;
	dijk();
	int prev = 0, res;
	REP(i, 1, Q){
		ll cur; cin >> cur;
		res = solve(cur);
		prev = res;
		cout << res << endl;
	}
	return 0;
}