#include "bits/stdc++.h"
#define scan(x) do{while((x=getchar())<'0'); for(x-='0'; '0'<=(_=getchar()); x=(x<<3)+(x<<1)+_-'0');}while(0)
using namespace std;
typedef long long ll;
char _;
int t, N;
vector<int> p;

void solve(int n){
	for(int i = 1; i < p.size(); i++){
		//cout << p[i] << endl;
		if(n % p[i] == 0){
			printf("%d\n", n/p[i]);
			break;
		}
	}
}

int main(){
	int prev = 1;
	p[0] = 1;
	for(int i = 1; i <= 30; i++){
		p.push_back(p[i - 1] + prev * 2);
		prev *= 2;
		//cout << p[i] << endl;
	}
	scan(t);
	while(t--){
		scan(N);
		solve(N);
	}
	return 0;
}