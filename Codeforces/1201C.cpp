#include "bits/stdc++.h"
#define scan(x) do{while((x=getchar())<'0'); for(x-='0'; '0'<=(_=getchar()); x=(x<<3)+(x<<1)+_-'0');}while(0)
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
char _;
vector<ll> arr;
int n, k;

bool check(ll val){
	ll cur = k;
	for(int i = n / 2; i < n; i++){
		if(val - arr[i] > 0) cur -= val - arr[i];
		if(cur < 0)return false;
	}
	return true;
}

int main(){
	scan(n);scan(k);
	for(int i = 0; i < n; i++){
		int x;scan(x);arr.push_back(x);
	}
	sort(arr.begin(), arr.end());
	ll l = 0, h = 2e9;
	while(l < h){
		ll mid = (l + h + 1) / 2;
		if(check(mid)){
			l = mid;
		}
		else{
			h = mid - 1;
		}
	}
	printf("%lld\n", l);
	return 0;
}