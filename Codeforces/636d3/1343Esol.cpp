#include <bits/stdc++.h>

using namespace std;

const int INF = 1e9;

vector<vector<int>> g;
int n;

void bfs(int s, vector<int> &d) {
	d[s] = 0;
	queue<int> q;
	q.push(s);
	while (!q.empty()) {
		int v = q.front();
		q.pop();
		for (auto to : g[v]) {
			if (d[to] == INF) {
				d[to] = d[v] + 1;
				q.push(to);
			}
		}
	}
	// for(int i = 0; i < n; i++){
	// 	cout << d[i] << " ";
	// }
	// cout << endl;
}

int main() {
#ifdef _DEBUG
	freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);
#endif
	
	int t;
	cin >> t;
	while (t--) {
		int m, a, b, c;
		cin >> n >> m >> a >> b >> c;
		--a, --b, --c;
		
		vector<int> p(m);
		for (auto &it : p) cin >> it;
		sort(p.begin(), p.end());
		vector<long long> pref(m + 1);
		for (int i = 0; i < m; ++i) {
			pref[i + 1] = pref[i] + p[i];
			cout << pref[i + 1] << endl;
		}
		
		g = vector<vector<int>>(n);
		for (int i = 0; i < m; ++i) {
			int x, y;
			cin >> x >> y;
			--x, --y;
			g[x].push_back(y);
			g[y].push_back(x);
		}
		
		vector<int> da(n, INF), db(n, INF), dc(n, INF);
		bfs(a, da);
		bfs(b, db);
		bfs(c, dc);
		
		long long ans = 1e18;
		for (int i = 0; i < n; ++i) {
			cout << i + 1 << " " << da[i] + db[i] + dc[i] << endl;
			if (da[i] + db[i] + dc[i] > m) continue;
			ans = min(ans, pref[db[i]] + pref[da[i] + db[i] + dc[i]]);
			//cout << i + 1 << " : " << da[i] << " " << db[i] << " " << dc[i] << endl;
		}
		cout << ans << endl;
		cout << endl;
	}
	
	return 0;
}