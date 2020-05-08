#include "bits/stdc++.h"
#define scan(x) do{while((x=getchar())<'0'); for(x-='0'; '0'<=(_=getchar()); x=(x<<3)+(x<<1)+_-'0');}while(0)
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
char _;

int get

void solve(){
	int n, k;
	scan(n);scan(k);
	for(int i = 0; i < n; i++){
		char digit[7 + 5];
		scanf("%s", digit);
		get(digit, k);
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