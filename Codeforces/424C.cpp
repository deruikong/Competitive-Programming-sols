#include "bits/stdc++.h"
#define scan(x) do{while((x=getchar())<'0'); for(x-='0'; '0'<=(_=getchar()); x=(x<<3)+(x<<1)+_-'0');}while(0)
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
char _;


int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n, Q = 0; cin >> n;
	vector<int> arr(n + 1), f(n + 1, 0);
	iota(f.begin(), f.end(), 0);
	for(int i = 1; i <= n; i++){
		int x; cin >> x;
		Q ^= x;
		f[i] ^= f[i - 1];
		// cout << q[i] << endl;
	}
	for(int i = 1; i <= n; i++){
		int x = 0;
		if((n/i) & 1){
			Q ^= f[i - 1] ^ f[n % i];
		}
		else{
			Q ^= f[n % i];
		}
	}
	cout << Q << endl;
	return 0;
}