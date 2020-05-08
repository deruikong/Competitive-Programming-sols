#include "bits/stdc++.h"
#define scan(x) do{while((x=getchar())<'0'); for(x-='0'; '0'<=(_=getchar()); x=(x<<3)+(x<<1)+_-'0');}while(0)
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
char _;


void solve(){
	int t, a, b;scan(a);scan(b);scan(t);
	if(a > b) swap(a, b);
	vector<int> psa(a*b + 1, 0);
	for(int i = 0; i <= a*b; i++){
		 psa[i] = (i%a)%b != (i%b)%a;
		 if(i != 0)psa[i] += psa[i - 1];
	}
	while(t--){
		ll x, y, cnt = 0, tmp = a * b, xpos;
		scan(x);scan(y);
		xpos = ((x % tmp==0) ? 0 : (x % tmp - 1));
		if(x / tmp == y / tmp){
			// cout << (xpos = ((x % tmp==0) ? 0 : (x % tmp - 1))) << endl;
			cnt = psa[y % tmp] - psa[xpos];
		}
		else{
			ll prefix;
			prefix = psa[tmp] - psa[xpos];
			//cout << (y - x - ((x/tmp + 1) * tmp - x))/tmp << endl;
			cnt += prefix;
			cnt += psa[tmp] * ((y - x - ((x/tmp + 1) * tmp - x)) / tmp);
			cnt += psa[y % tmp];
		}
		// cout << cnt << endl;
		// y -= ;
		//cnt += psa[y];
		printf("%lld\n", cnt);
	}
}

int main(){
	int q;scan(q);
	while(q--){
		solve();
	}
	return 0;
}