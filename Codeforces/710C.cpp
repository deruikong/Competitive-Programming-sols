#include "bits/stdc++.h"
#define scan(x) do{while((x=getchar())<'0'); for(x-='0'; '0'<=(_=getchar()); x=(x<<3)+(x<<1)+_-'0');}while(0)
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
char _;

int gn(int& l){
	int ret = l;
	l += 2;
	return ret;
}

void solve(int n){
	int grid[n + 3][n + 3], even = 2, odd = 1;
	memset(grid, 0, sizeof(grid));
	// cout << n/2 << endl;
	for(int i = 0; i < n / 2; i++){
		// cout << i << " " << n/2 - i << endl;
		for(int j = 0; j < n/2 - i; j++){
			// cout << i << " " << j << endl;
			int i2 = n - i - 1, j2 = n - j - 1;
			grid[i][j] = gn(even);
			grid[i2][j] = gn(even);
			grid[i][j2] = gn(even);
			grid[i2][j2] = gn(even);
		}
	}
	for(int i = 0; i < n; i++){
		for(int j = 0; j < n; j++){
			if(!grid[i][j])grid[i][j] = gn(odd);
			printf("%d ", grid[i][j]);
		}
		printf("\n");
	}
}

int main(){
	int n;
	scan(n);
	solve(n);
	return 0;
}