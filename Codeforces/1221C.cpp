#include "bits/stdc++.h"
#define scan(x) do{while((x=getchar())<'0'); for(x-='0'; '0'<=(_=getchar()); x=(x<<3)+(x<<1)+_-'0');}while(0)
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
char _;
int a, b, c;

bool good(int x){
	return x <= min(a, b) && x <= (a + b + c) - 2 * x;
}

void solve(){
	cin >> a >> b >> c;
	int l = 0, h = 2e8;
	while(l < h){
		int mid = (l + h + 1)/2;
		// cout << mid << " " << good(mid) << endl;
		if(good(mid)){
			l = mid;
		}
		else{
			h = mid - 1;
		}
	}
	cout << l << endl;
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int N; cin >> N;
	while(N--){
		solve();
	}
	return 0;
}