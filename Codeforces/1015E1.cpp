#include "bits/stdc++.h"
#define scan(x) do{while((x=getchar())<'0'); for(x-='0'; '0'<=(_=getchar()); x=(x<<3)+(x<<1)+_-'0');}while(0)
#define endl '\n'
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
char _;
const int mn = 105;
int n, m;
vector<string> grid(mn), fin(mn);
vector<pair<int, pii>> tot;


int getmax(int r, int c, int a, int b){
	int cnt = 0;
	while(grid[r][c] != '.' && ++cnt){
		r += a;
		c += b;
	}
	// cout << endl;
	return cnt;
}

int getstar(int i, int j){
	int l, r, u, d;
	l = getmax(i, j - 1, 0, -1);
	r = getmax(i, j + 1, 0, 1);
	u = getmax(i - 1, j, -1, 0);
	d = getmax(i + 1, j, 1, 0);
	return min(min(l, r), min(u, d));
}

void fill_in(int sz, int r, int c){
	fin[r][c] = '*';
	for(int i = 1; i <= sz; i++){
		fin[r][c - i] = '*';
		fin[r][c + i] = '*';
		fin[r - i][c] = '*';
		fin[r + i][c] = '*';
	}
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> n >> m;
	grid[0].insert(0, m + 2, '.'), grid[n + 1] = grid[0];
	for(int i = 1; i <= n; i++){
		cin >> grid[i];
		grid[i].insert(0, 1, '.');
		grid[i] += '.';
		fin[i].insert(0, m + 2, '.');
		// cout << grid[i] << endl;
	}

	for(int i = 1; i <= n; i++){
		for(int j = 1; j <= m; j++){
			if(grid[i][j] == '*'){
				int sz = getstar(i, j);
				if(sz){
					fill_in(sz, i, j);
					tot.emplace_back(sz, make_pair(i, j));
				}
			}
		}
	}

	for(int i = 1; i <= n; i++){
		for(int j = 1; j <= m; j++){
			if(grid[i][j] != fin[i][j]){
				cout << -1 << endl;
				return 0;
			}
		}
	}
	// for(int k = 1; k <= n; k++){
	// 	cout << fin[k] << endl;
	// }
	cout << tot.size() << endl;
	for(auto pp : tot){
		cout << pp.second.first << " " << pp.second.second << " " << pp.first << endl;
	}
	return 0;
}