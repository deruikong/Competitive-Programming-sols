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
int N, M, sr, sc, dr, dc, mat[1003][1003];

void bfs(){
	list<pii> q;
	mat[sr][sc] = 0;
	q.emplace_back(sr, sc);
	while(!q.empty()){
		int r = q.front().first, c = q.front().second; q.pop_front();
		REP(i, 0, 3){
			int rr = r, cc = c;
			switch(i){
				case 0: rr--;break;
				case 1: rr++;break;
				case 2: cc--;break;
				case 3: cc++;break;
			}
			// cout << rr << " " << cc << endl;
			if(!mat[rr][cc]){
				mat[rr][cc] = mat[r][c] + 1;
				q.emplace_back(rr, cc);
			}
		}
	}
	cout << ((!mat[dr][dc])?-1:(mat[dr][dc]-1)) << endl;
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	memset(mat, 1, sizeof(mat));
	cin >> N >> M;
	REP(i, 1, N){
		string c;
		cin >> c;
		REP(j, 1, M){
			char a = c[j-1];
			mat[i][j] = 0;
			switch(a){
				case 'X': mat[i][j] = -1;break;
				case 'e': dr = i, dc = j;break;
				case 's': sr = i, sc = j;break;
			}
		}
	}
	bfs();
	return 0;
}