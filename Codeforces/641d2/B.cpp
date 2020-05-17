#include "bits/stdc++.h"
#define scan(x) do{while((x=getchar())<'0'); for(x-='0'; '0'<=(_=getchar()); x=(x<<3)+(x<<1)+_-'0');}while(0)
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
char _;
const int mn = 1e5 + 1;

void solve(){
	int n, ret = 0; scan(n);
	vector<int> arr(n + 1), dist(n + 1, 1);
	for(int i = 1; i <= n; i++){
		scan(arr[i]);
		for(int j = 1; j * j <= i; j++){
			if(i % j == 0){
				if(arr[i] > arr[j])dist[i] = max(dist[i], dist[j] + 1);
				if(arr[i] > arr[i / j]) dist[i] = max(dist[i], dist[i / j] + 1);
			}
		}
	}
	for(int i = 1; i <= n; i++){
		ret = max(ret, dist[i]);
	}
	printf("%d\n", ret);
}

int main(){
	int q;
	scan(q);
	while(q--){
		solve();
	}
	return 0;
}