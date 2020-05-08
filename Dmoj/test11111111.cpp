#include <bits/stdc++.h>
#define INF 0x3f3f3f3f
#define ll long long
#define ull unsigned long long
#define pii pair<int, int>
#define pll pair<long, long>
using namespace std;

int grid[101][102];/* code */

pii ret(int r, int c, int a){
	switch(a){
		case 0: return make_pair(r-2, c+1);
		case 1: return make_pair(r-1, c+2);
		case 2: return make_pair(r+1, c+2);
		case 3: return make_pair(r+2, c+1);
		case 4: return make_pair(r+2, c-1);
		case 5: return make_pair(r+1, c-2);
		case 6: return make_pair(r-1, c-2);
		case 7: return make_pair(r-2, c-1);
		default:break;
	}
}

void init(int r, int c, int kr, int kc){
	list<pair<int, pii>> q;
	q.emplace_back(0, make_pair(kr, kc));
	while(!q.empty()){
		pair<int, pii> curr = q.front();
		curr.first++;
		q.pop_front();
		for (int i = 0; i < 8; ++i)
		{
			pii x = ret(curr.second.first, curr.second.second, i);
			if(x.first < 1 || x.second < 1 || x.first > r || x.second > c || grid[x.first][x.second] != INF)continue;
			q.emplace_back(curr.first, x);
			grid[x.first][x.second] = curr.first;
		}
	}
	// for(int i = 1; i < r; i++){
	// 	for(int j = 1; j < c; j++)printf("%d ", grid[i][j]);
	// 	printf("\n");
	// }
}

int main(){
	int N;scanf("%d", &N);
	for (int i = 0; i < N; ++i)
	{
		int r, c, pr, pc, kr, kc;
		scanf("%d%d%d%d%d%d", &r, &c, &pr, &pc, &kr, &kc);
		memset(grid, INF, sizeof(grid[0][0])*101*102);
		init(r, c, kr, kc);
		int state = -1;
		for (int i = pr+1; i <= r; i++)if(grid[i][pc] == i-pr){state = 1; printf("Win in %d knight move(s)\n", grid[i][pc]); break;}

		if(state == -1)
		{
			for (int i = pr+1; i <= r; i++)if(grid[i+1][pc] == i-pr){state = 0;printf("Stalemate in %d knight move(s)\n", grid[i+1][pc]);break;}
		}
		if(state == -1)printf("Loss in %d knight move(s)\n", r-pr-1);
	}
	return 0;
}