#include "bits/stdc++.h"
#define scan(x) do{while((x=getchar())<'0'); for(x-='0'; '0'<=(_=getchar()); x=(x<<3)+(x<<1)+_-'0');}while(0)
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
char _;

void solve(){
	int n, k;
	scan(n);scan(k);
	k--;
	for(int i = 2; i <= n; i++){
		if(n % i == 0){
			n += i;
			break;
		}
	}
	n += (k * 2);
	printf("%d\n", n);
}

int main(){
	int t;
	scan(t);
	while(t--){
		solve();
	}
	return 0;
}