#include "bits/stdc++.h"
#define scan(x) do{while((x=getchar())<'0'); for(x-='0'; '0'<=(_=getchar()); x=(x<<3)+(x<<1)+_-'0');}while(0)
#define int long long
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
char _;
int n, m, k;
int sum(int val){return (val * (val + 1)) / 2;}
int cnt(int l, int r, int val){
	if((r - l + 1) < val){
		return sum(val) - sum(val - (r - l + 1));
	}
	else{
		return sum(val)  + (r - l + 1) - val;
	}
}
bool good(int a){
	int lf = cnt(1, k - 1,  max(1LL, a - 1)), rg = cnt(k + 1, n, max(1LL, a - 1));
	// cout << a << " " << lf << " " << rg << endl;
	return (lf + rg) <= (m - a);
}

int32_t main(){
	cin >> n >> m >> k;
	int l = 0, h = m;
	while(l < h){
		int mid = (l + h + 1) / 2;
		if(good(mid)){
			l = mid;
		}
		else{
			h = mid - 1;
		}
	}
	cout << l << endl;
	return 0;
}