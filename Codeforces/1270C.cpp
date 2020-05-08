#include "bits/stdc++.h"
#define scan(x) do{while((x=getchar())<'0'); for(x-='0'; '0'<=(_=getchar()); x=(x<<3)+(x<<1)+_-'0');}while(0)
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
char _;

vector<ll> arr;

void solve(){
	arr.clear();
	ll sum = 0, XOR = 0;
	int n;
	scan(n);
	// cout << "a" << "b" << endl;
	for(int i = 0; i < n; i++){
		int x;
		scan(x);
		sum += x;
		XOR ^= x;
	}
	printf("2\n%lld %lld\n", XOR, (sum + XOR));
}

int main(){
	int t;
	scan(t);
	while(t--){
		solve();
	}
	return 0;
}
