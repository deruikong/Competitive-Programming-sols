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
int r, c, rb, cb, re, ce;
bool grid[1002][1003];
bool vis[1002][1003];

void bfs(){
	int fin = INT_MAX, shortest = INT_MAX;
	list<pair<pii, int>> q; q.emplace_back(make_pair(rb, cb), 0);
	vis[rb][cb] = true;
	while(!q.empty()){
		pair<pii, int> cur = q.front();q.pop_front();
		if(grid[cur.first.first][cur.first.second])shortest = min(shortest, cur.second);
		if(cur.first.first == re && cur.first.second == ce)fin = min(fin, cur.second);
		cur.second++;
		REP(i, 0, 3){
			int rr = 0, cc = 0;
			switch(i){
				case 0:rr++;break;
				case 1:rr--;break;
				case 2:cc++;break;
				case 3:cc--;break;
			}
			if(!vis[cur.first.first+rr][cur.first.second+cc]){
				vis[cur.first.first+rr][cur.first.second+cc] = true, q.emplace_back(make_pair(cur.first.first+rr,cur.first.second+cc), cur.second);
			}
		}
	}
	printf("%d", max(0, fin-shortest));
}

int main(){
	scanf("%d%d%d%d%d%d",&r, &c, &rb, &cb, &re, &ce);
	rb++, cb++, re++, ce++;
	memset(grid, 0, sizeof(grid));memset(vis, 1, sizeof(vis));
	REP(i, 1, r){
		char scan[c+5];
		scanf("%s", scan);
		REP(j, 1, c){
			vis[i][j] = 0;
			if(scan[j-1] == 'X')vis[i][j] = 1;
		}
	}
	int N;
	scanf("%d", &N);
	while(N--){
		int rr, cc;
		scanf("%d%d", &rr, &cc);
		grid[++rr][++cc] = 1;
	}
	bfs();
    return 0;
}