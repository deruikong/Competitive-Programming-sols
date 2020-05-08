#pragma GCC target ("avx2")
#pragma GCC optimization ("O3")
#pragma GCC optimization ("unroll-loops")
#include "bits/stdc++.h"
#define scan(x) do{while((x=getchar())<'0'); for(x-='0'; '0'<=(_=getchar()); x=(x<<3)+(x<<1)+_-'0');}while(0)
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
char _;
const int MN = 5e2 + 5;
int n, m, q, up[MN][MN], side[MN][MN];
char grid[MN][MN];
int main(){
	scan(n);scan(m);
	for(int i = 0; i < n; i++){
		scanf("%s", grid[i]);
	}
	for(int r = 0; r < n; r++)for(int c = 0; c < m; c++){
		up[r + 1][c + 1] = up[r + 1][c] + up[r][c + 1] - up[r][c];
		side[r + 1][c + 1] = side[r + 1][c] + side[r][c + 1] - side[r][c];
		if(grid[r][c] != '.')continue;
		if(grid[r + 1][c] == '.')side[r + 1][c + 1]++;
		if(grid[r][c + 1] == '.')up[r + 1][c + 1]++;
	}
	scan(q);
	while(q--){
		int r1, c1, r2, c2, alt = 0;
		scan(r1);scan(c1);scan(r2);scan(c2);
		r1--, c1--;
		alt += up[r2][c2 - 1] - up[r2][c1] - up[r1][c2 - 1] + up[r1][c1];
		alt += side[r2 - 1][c2] - side[r2 - 1][c1] - side[r1][c2] + side[r1][c1];
		printf("%d\n", alt);
	}
	return 0;
}