#include "bits/stdc++.h"
#define scan(x) do{while((x=getchar())<'0'); for(x-='0'; '0'<=(_=getchar()); x=(x<<3)+(x<<1)+_-'0');}while(0)
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
char _;

int primes[12] = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31};

void solve(){
	vector<int> color[12];
	map<int, int> idx;
	int n, x = 1;
	scan(n);
	vector<int> res(n);
	for(int i = 0; i < n; i++){
		int cur;
		scan(cur);
		for(int j = 0; j < 11; j++){
			if(cur % primes[j] == 0){
				if(idx.find(primes[j]) == idx.end()){
					idx[primes[j]] = x++;
				}
				res[i] = primes[j];
				break;
			}
		}
	}
	printf("%d\n", x - 1);
	for(int i = 0; i < n; i++){
		printf("%d ", idx[res[i]]);
	}
	printf("\n");
}

int main(){
	int q;
	scan(q);
	while(q--){
		solve();
	}
	return 0;
}