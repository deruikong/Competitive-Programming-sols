#include "bits/stdc++.h"
#define scan(x) do{while((x=getchar())<'0'); for(x-='0'; '0'<=(_=getchar()); x=(x<<3)+(x<<1)+_-'0');}while(0)
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
char _;


int main(){
	int t; cin >> t;
	while(t--){
		ll x, y, x2, y2;
		cin >> x >> y >> x2 >> y2;
		cout << (x2-x) * (y2 - y) + 1 << '\n';
	}
	return 0;
}