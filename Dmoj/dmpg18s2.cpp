#include "bits/stdc++.h"
#define scan(x) do{while((x=getchar())<'0'); for(x-='0'; '0'<=(_=getchar()); x=(x<<3)+(x<<1)+_-'0');}while(0)
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
char _;


int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n; ll prev = 0; cin >> n;
	vector<ll> psa(n + 1, 0);
	for(int i = 1; i <= n; i++){
		cin >> psa[i];
		psa[i] += psa[i - 1];
		// cout << psa[i] << endl;
	}
	for(int i = 1; i <= n; i++){
		ll x = psa[n - i + 1] - psa[i - 1];
		x += prev;
		prev = x;
		cout << x << endl;
	}
	return 0;
}