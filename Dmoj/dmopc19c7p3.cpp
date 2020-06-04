#include "bits/stdc++.h"
#define scan(x) do{while((x=getchar())<'0'); for(x-='0'; '0'<=(_=getchar()); x=(x<<3)+(x<<1)+_-'0');}while(0)
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
char _;
const int mn = 1e6 + 2;

vector<int> adj[mn];
ll N, K, sum, weights[mn];
bool vis[mn];
vector<int> nodes;
set<int> arr;
void dfs(int v){
	vis[v] = 1;
	if(sum >= K)return;
	sum += weights[v];
	// cout << v << " " << weights[v] << endl;
	nodes.push_back(v);
	for(int u : adj[v]){
		if(!vis[u]){
			dfs(u);
		}
	}
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> N >> K;
	// cout << K << endl;
	for(int i = 1; i <= N; i++){
		arr.insert(i);
	}
	for(int i = 1; i <= N; i++){
		cin >> weights[i];
		if(weights[i] > 2 * K)arr.erase(i);
		else if(weights[i] <= 2 * K && weights[i] >= K){
			cout << 1 << i + 1 << endl;
			return 0;
		}
		// cout << i << " " << weights[i] << endl;
	}
	for(int i = 0; i < N - 1; i++){
		int u, v;
		cin >> u >> v;
		if(weights[u] > 2 * K || weights[v] > 2 * K) continue;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}
	if(arr.empty()){
		cout << -1 << endl;
		return 0;
	}
	for(int v : arr){
		if(!vis[v]){
			nodes.clear();
			sum = 0;
			dfs(v);
			if(sum < K) continue;
			else{
				cout << nodes.size() << endl;
				for(int u : nodes) cout << u << " ";
				cout << '\n';
				return 0;
			}
		}
	}
	// cout << sum << " " << K << endl;
	cout << -1 << endl;
	return 0;
}