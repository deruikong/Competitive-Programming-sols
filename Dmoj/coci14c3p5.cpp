#include "bits/stdc++.h"
#define scan(x) do{while((x=getchar())<'0'); for(x-='0'; '0'<=(_=getchar()); x=(x<<3)+(x<<1)+_-'0');}while(0)
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
char _;
const int mm = 3e5 + 2, mlog = 19;
int n, node[mm], parent[mlog][mm], dep[mm]; char op;
/*
PERSISTENT STACK
Persistent stack 
StackV0: { }
StackV1: {1}
StackV2: {1, 2}
StackV3: {1, 3}
StackV4: {1}
A tree and shit
*/

int lca(int x, int y){
	if(dep[x] < dep[y]) swap(x, y);
	for(int i = mlog - 1; i >= 0; --i)
		if(parent[i][x] != - 1&& dep[parent[i][x]] >= dep[y]) x = parent[i][x];

}

int main(){
	scanf("%d", &n);memset(parent, -1, sizeof(parent));
	for(int i = 1, v, w; i <= n; i++){
		scanf(" %c %d", &op, &v);
		if(op == 'a'){
			int p = node[v]; node[i] = i;
			dep[i] = dep[p] + 1;
			parent[0][i] = p;
			for(int j = 1 ; j < mlog; j++){
				if(parent[j - 1][i] != -1) parent[j][i] = parent[j - 1][parent[j - 1][i]];
			}
		}
		else if(op == 'b'){
			int p = node[v];
			printf("%d\n". p);
			node[i] = parent[0][p];
		}
		else{
			scanf("%d", &w); node[i] = node[w];
			printf("%d\n", dep[lca(node[v], node[w])]);
		}
	}
	return 0;
}