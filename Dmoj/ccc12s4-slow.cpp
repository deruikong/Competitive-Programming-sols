#include "bits/stdc++.h"
#define scan(x) do{while((x=getchar())<'0'); for(x-='0'; '0'<=(_=getchar()); x=(x<<3)+(x<<1)+_-'0');}while(0)
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
char _;

set<vector<int>> vis;

void print(vector<int> a){
	for(int i = 0; i < a.size(); i++)cout << a[i] << " ";
	cout << endl;
}

void solve(int n){
	vector<int> arr(n), ans(n);
	for(int i = 0; i < n; i++){
		cin >> arr[i];
		ans[i] = i + 1;
	}
	queue<pair<int, vector<int>>> q; q.emplace(0, arr);
	vis.insert(arr);
	while(!q.empty()){
		vector<int> cur = q.front().second; int w = q.front().first;q.pop();
		// cout << "new" << "\n";
		// print(cur);
		if(cur == ans){
			cout << w << '\n';
			return;
		}
		for(int i = 0; i < n; i++){
			// cout << i << " " << cur[i] << endl;
			if(cur[i] == 0) continue;
			int x = cur[i], pre = ((i == 0)?-1:cur[i - 1]), aft = ((i == n - 1)?-1:cur[i + 1]);
			vector<int> a = cur;
			if(x % 10 < pre % 10 || pre == 0){
				a[i - 1] *= 10; a[i - 1] += x % 10;
				a[i] /= 10;
				// print(cur);
				if(vis.find(a) == vis.end()){
					q.emplace(w + 1, a);
					vis.insert(a);
				}
			}
			a = cur;
			if(x % 10 < aft % 10 || aft == 0){
				a[i + 1] *= 10; a[i + 1] += x % 10;
				a[i] /= 10;
				// print(cur);
				if(vis.find(a) == vis.end()){
					vis.insert(a);
					q.emplace(w + 1, a);
				}
			}
		}
		// cout << endl;
	}
	cout << "IMPOSSIBLE" << '\n';
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n; cin >> n;
	while(n != 0){
		vis.clear();
		solve(n);
		cin >> n;
	}
	return 0;
}