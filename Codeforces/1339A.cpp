#include "bits/stdc++.h"
#define scan(x) do{while((x=getchar())<'0'); for(x-='0'; '0'<=(_=getchar()); x=(x<<3)+(x<<1)+_-'0');}while(0)
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
char _;
int t, n;

void solve(int n){
	printf("%d\n", n);
}

int main(){
	scan(t);
	while(t--){
		scan(n);
		solve(n);
	}
	return 0;
}