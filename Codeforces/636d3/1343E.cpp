#include "bits/stdc++.h"
#define scan(x) do{while((x=getchar())<'0'); for(x-='0'; '0'<=(_=getchar()); x=(x<<3)+(x<<1)+_-'0');}while(0)
#define ll long long
#define pii pair<int, int> 
using namespace std;
char _;
const int MN = 2e5 + 1;
int n, m, a, b, c;
vector<vector<int>> adj(MN);


vector<int> bfs(int start){
	list<pii> q;
	vector<int> res(n + 1, 0x3f3f3f);
	q.emplace_back(start, 0);
	while(!q.empty()){
		int u = q.front().first, w = q.front().second; q.pop_front();
		res[u] = min(res[u], w);
		for(int v : adj[u]){
			if(res[v] == 0x3f3f3f){
				q.emplace_back(v, w + 1);
			}
		}
	}
	return res;
}

int main(){
	int t;
	scan(t);
	while(t--){
		adj.clear();
		scan(n);scan(m);scan(a);scan(b);scan(c);
		adj.resize(n + 1);
		vector<ll> pref(m + 1);
		pref[0] = 0;
		for(int i = 1; i <= m; i++){
			scan(pref[i]);
			//cout << pref[i] << endl;
		}
		sort(next(pref.begin()), pref.end());
		for(int i = 1; i <= m; i++){
			pref[i] += pref[i - 1];
			//cout << pref[i] << endl;
		}
		for(int i = 1; i <= m; i++){
			int u, v;
			scan(u);scan(v);
			adj[u].push_back(v);
			adj[v].push_back(u);
		}
		vector<int> dist_a = bfs(a), dist_b = bfs(b), dist_c = bfs(c);
		ll res = 1e18;
		for(int i = 1; i <= n; i++){
			int alt = dist_a[i] + dist_b[i] + dist_c[i];
			//cout << i << " " << alt << endl;
			if(alt > m)
			 	continue;
			res = min(res, pref[alt] + pref[dist_b[i]]);
			//cout << i << " : " << dist_a[i] << " " << dist_b[i] << " " << dist_c[i] << endl;
		}
		printf("%lld\n", res);
		cout << endl;
	}
	return 0;
}