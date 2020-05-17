#include "bits/stdc++.h"
#define scan(x) do{while((x=getchar())<'0'); for(x-='0'; '0'<=(_=getchar()); x=(x<<3)+(x<<1)+_-'0');}while(0)
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
char _;
const int mn = 1e3 + 1;
struct knapsack{
	int v = 0, w = 0;
};

bool vis[mn];
int dp[mn + 1][mn + 1];
vector<knapsack> val(mn);
map<int, vector<knapsack>> orz;
// disjoint set implementation for joining friends
vector<int> dsu;
void init(int n){dsu.resize(n);for(int i = 0; i < n; i++)dsu[i] = i;}
int find(int u){return (dsu[u] == u) ? u : (dsu[u] = find(dsu[u]));}
void merge(int u, int v){dsu[find(u)] = find(v);}

knapsack sum(int x){
	knapsack ret;
	for(knapsack curr : orz[x]){
		ret.v += curr.v;
		ret.w += curr.w;
	}
	return ret;
}

ll solve_knapsack(int w){
	int sz = orz.size(), idx = 1;
	for(auto pv : orz){
		vector<knapsack> cset = pv.second;
		// cout << pv.first << endl;
		for(auto pp : cset){
			// cout << pp.v << " " << pp.w << endl;
			for(int i = 1; i <= w; i++){
				dp[idx][i] = max(dp[idx][i], dp[idx - 1][i]);
				if(pp.w <= i){
					dp[idx][i] = max(dp[idx][i], dp[idx - 1][i - pp.w] + pp.v);
					// cout << i << endl;
				}
			}
		}
		// for(int i = 1; i <= w; i++){
		// 	cout << dp[idx][i] << " ";
		// }
		idx++;
	}
	return dp[sz][w];
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n, m, w;
	cin >> n >> m >> w;
	init(n);
	for(int i = 0; i < n; ++i){
		cin >> val[i].w;
	}
	for(int i = 0; i < n; ++i){
		cin >> val[i].v;
	}
	for(int i = 0; i < m; ++i){
		int u, v;
		cin >> u >> v;
		--u, --v;
		merge(u, v);
		// cout << u << " " << v << endl;
	}
	for(int i = 0; i < n; i++){
		orz[find(i)].push_back(val[i]);
	}
	for(auto& pp: orz){
		pp.second.push_back(sum(pp.first));
	}
	// for(auto pp : orz){
	// 	for(auto ks : pp.second){
	// 		cout << ks.v << " " << ks.w << endl;
	// 	}
	// 	cout << endl;
	// }
	cout << solve_knapsack(w) << endl;
	return 0;
}