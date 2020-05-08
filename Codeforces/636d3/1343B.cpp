#include "bits/stdc++.h"
#define scan(x) do{while((x=getchar())<'0'); for(x-='0'; '0'<=(_=getchar()); x=(x<<3)+(x<<1)+_-'0');}while(0)
#define ll long long
using namespace std;
char _;
int t, N;

void solve(int n){
	int sum = 0;
	if(n/2 & 1){
		printf("NO\n");
	}
	else{
		printf("YES\n");
		for(int i = 1; i <= n/2; i++){
			printf("%d ", i*2);
			sum += i * 2;
		}
		for(int i = 1, val = 1; i < n/2; i++, val += 2){
			printf("%d ", val);
			sum -= val;
		}
		printf("%d\n", sum);
	}
}

int main(){
	scan(t);
	while(t--){
		scan(N);
		solve(N);
	}
	return 0;
}