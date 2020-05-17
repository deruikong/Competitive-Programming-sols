#include "bits/stdc++.h"
#define scan(x) do{while((x=getchar())<'0'); for(x-='0'; '0'<=(_=getchar()); x=(x<<3)+(x<<1)+_-'0');}while(0)
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
char _;
const int mn = 1e2 + 5;
int dist[mn][mn];

int main(){
	int n, m, cnt = 0;
	scan(n);
	memset(dist, 0x3f3f3f, sizeof(dist));
	for(int i = 1; i <= n; i++){
		for(int j = 1; j <= n; j++){
			char cur = getchar();
			if(cur == '1')dist[i][j] = 1;
			if(i == j)dist[i][j] = 0;
		}
		getchar();
	}
	scan(m);
	vector<int> arr(m + 1), res;
	for(int i = 1; i <= m; i++)scan(arr[i]);
	// floyd-warshall
	for(int k = 1; k <= n; k++)for(int i = 1; i <= n; i++)for(int j = 1; j <= n; j++){
		if(dist[i][k] + dist[k][j] < dist[i][j]){
			dist[i][j] = dist[i][k] + dist[k][j];
		}
	}
	res.push_back(1);
	int idx = 1;
	for(int i = 1; i <= m; i++){
		if(dist[arr[idx]][arr[i]] < i - idx){
			idx = i - 1;
			// cout << idx << " " << i << endl;
			res.push_back(i - 1);

		}
	}
	res.push_back(m);
	printf("%d\n", res.size());
	for(int x : res){
		printf("%d ", arr[x]);
	}
	printf("\n");
	return 0;
}