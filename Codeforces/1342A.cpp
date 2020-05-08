#include "bits/stdc++.h"
#define scan(x) do{while((x=getchar())<'0'); for(x-='0'; '0'<=(_=getchar()); x=(x<<3)+(x<<1)+_-'0');}while(0)
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
char _;

void solve(){
	ll a, b, x, y, tot = 0;
	scanf("%lld%lld%lld%lld", &x, &y, &a, &b);
	//cout << a << " " << b << " " << x << " " << y << endl;
	if(x > y)swap(x, y);
	tot += (y - x) * a;
	tot += min(b, 2 * a) * x;
	printf("%lld\n", tot);
}
int main(){
	int t;
	scan(t);
	while(t--){
		solve();
	}
	return 0;
}