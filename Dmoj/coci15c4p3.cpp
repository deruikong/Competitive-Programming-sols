#include "bits/stdc++.h"
#define scan(x) do{while((x=getchar())<'0'); for(x-='0'; '0'<=(_=getchar()); x=(x<<3)+(x<<1)+_-'0');}while(0)
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
char _;


int main(){
	int N;
	cin >> N;
	for(int i = 0; i < N; i++){
		ll x = 0;
		for(int j = 0; j < N; j++){
			ll cur; cin >> cur;
			x |= cur;
			// cout << x << endl;
		}
		cout << x << endl;
	}
	return 0;
}