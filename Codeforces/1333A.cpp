#include "bits/stdc++.h"
#define scan(x) do{while((x=getchar())<'0'); for(x-='0'; '0'<=(_=getchar()); x=(x<<3)+(x<<1)+_-'0');}while(0)
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
char _;

void solve(){
	int n, m, c[2] = {0, 0};
	bool color = 1, mat[101][101];
	scan(n);scan(m);
	for(int i = 0; i < n; i++){
		for(int j = 0; j < m; j++){
			c[color]++;
			mat[i][j] = color;
			color ^= 1;
		}
	}
	//cout << c[0] << " " << c[1] << endl;
	if(c[0] == c[1])mat[0][1] = 1;
	//cout << mat[0][1] << endl;
	for(int i = 0; i < n; i++){
		for(int j = 0; j < m; j++){
			if(mat[i][j]) printf("B");
			else printf("W");
		}
		printf("\n");
	}
}

int main(){
	int q;
	scan(q);
	while(q--){
		solve();
	}
	return 0;
}