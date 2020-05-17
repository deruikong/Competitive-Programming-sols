#include "bits/stdc++.h"
#define scan(x) do{while((x=getchar())<'0'); for(x-='0'; '0'<=(_=getchar()); x=(x<<3)+(x<<1)+_-'0');}while(0)
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
char _;
set<vector<int>> vis;

void solve(int n){
	vector<int> arr(n), fin(n);
	for(int i = 0; i < n; i++){
		cin >> arr[i];
		fin[i] = i + 1;
	}
	list<pair<int, vector<int>>> q; q.emplace_back(0, arr);
	vis.insert(arr);
	while(!q.empty()){
		int stps = q.front().first;
		vector<int> curr = q.front().second; q.pop_front();
		if(curr == fin){
			cout << stps << endl;
			return;
		}
		for(int i = 0; i < n; i++){
			if(i != 0 && curr[i] % 10 < curr[i - 1] % 10){
				vector<int> tmp = curr;
				tmp[i - 1] *= 10;
				tmp[i - 1] += tmp[i] % 10;
				tmp[i] /= 10;
				if(vis.find(tmp) == vis.end()){
					vis.insert(tmp);
					q.emplace_back(stps + 1, tmp);
				}
			}
			if(i != n - 1 && curr[i] % 10 < curr[i + 1] % 10){
				vector<int> tmp = curr;
				tmp[i + 1] *= 10;
				tmp[i + 1] += tmp[i] % 10;
				tmp[i] /= 10;
				if(vis.find(tmp) == vis.end()){
					vis.insert(tmp);
					q.emplace_back(stps + 1, tmp);
				}
			}
		}
	}
	cout << "IMPOSSIBLE" << endl;
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