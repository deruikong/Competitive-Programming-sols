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
using namespace std;

struct p{
	int a;
	int b;
	bool operator<(p const& x) const{
		return tie(a, b) < tie(x.a, x.b)|| tie(b,a) < tie(x.a, x.b);
	}
};

int a[20][21], N, M, T, minD = INF;
map<p, int> dis;
vector<p> pos;

void bfs(int i){
	bool vis[N][M+1];
	memset(vis, false, sizeof(vis[0][0])*N*(M+1));
	list<pair<int, p>> q;
	pair<int, p> c = make_pair(0, pos[i]);
	q.push_back(c);
	vis[pos[i].a][pos[i].b] = true;
	i = a[pos[i].a][pos[i].b];
	while(!q.empty()){
		pair<int,p> curr = q.front();
		p cpos = curr.second;
		int v = a[cpos.a][cpos.b];
		q.pop_front();
		if(v > 0 && v != i && dis.find(p{min(i, v), max(i, v)}) == dis.end()){
			dis[p{min(i, v), max(i, v)}] = curr.first;
			continue;
		}
		curr.first++;
		if(cpos.a - 1 >= 0 && a[cpos.a-1][cpos.b] != -1 && !vis[cpos.a-1][cpos.b])
			vis[cpos.a-1][cpos.b] = true, q.push_back(make_pair(curr.first, p{cpos.a-1, cpos.b}));
		if(cpos.a + 1 < N  && a[cpos.a+1][cpos.b] != -1 && !vis[cpos.a+1][cpos.b])
			vis[cpos.a+1][cpos.b] = true, q.push_back(make_pair(curr.first, p{cpos.a+1, cpos.b}));
		if(cpos.b - 1 >= 0 && a[cpos.a][cpos.b-1] != -1 && !vis[cpos.a][cpos.b-1])
			vis[cpos.a][cpos.b-1] = true, q.push_back(make_pair(curr.first, p{cpos.a, cpos.b-1}));
		if(cpos.b + 1 < M  && a[cpos.a][cpos.b+1] != -1 && !vis[cpos.a][cpos.b+1])
			vis[cpos.a][cpos.b+1] = true, q.push_back(make_pair(curr.first, p{cpos.a, cpos.b+1}));
	}
}

int main(){
	scanf("%d%d%d", &N, &M, &T);
	vector<int> perms(T, 0);
	iota(perms.begin(), perms.end(), 2);
	int tmp = 2;
	for (int i = 0; i < N; ++i)
	{
		char cur[M+5];
		scanf("%s", &cur);
		for (int j = 0; j < M; ++j)
		{
			if(cur[j]=='H')a[i][j] = tmp++, pos.push_back(p{i, j});
			else if(cur[j] == 'G') a[i][j] = 1, pos.push_back(p{i, j});
			else if(cur[j] == 'X') a[i][j] = -1;
			else a[i][j] = 0;
		}
	}
	for (int i = 0; i < T+1; ++i)
	{
	    bfs(i);
	}
	do{
		int cur = 0, prev = 1;
		for (int i = 0; i < T; i++)
		{
			if(dis.find(p{min(prev, perms[i]), max(prev, perms[i])}) == dis.end()){cur = 0;break;}
			cur += dis[p{min(prev, perms[i]), max(prev, perms[i])}];
			prev = perms[i];
		}
		if(cur != 0)minD = min(minD, cur);
	}while(next_permutation(perms.begin(), perms.end()));
	printf("%d\n", minD);

	return 0;
}