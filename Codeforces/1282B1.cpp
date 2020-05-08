#include "bits/stdc++.h"
#define scan(x) do{while((x=getchar())<'0'); for(x-='0'; '0'<=(_=getchar()); x=(x<<3)+(x<<1)+_-'0');}while(0)
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
char _;

void solve(){
	int n, p, k, cnt = 0, pref = 0;
	scan(n);scan(p);scan(k);
	vector<int> arr(n), psa(n);

	for(int i = 0; i < n; i++){
		scan(arr[i]);
	}
	sort(arr.begin(), arr.end());
	for(int i = 0; i <= k; i++){
		int tot = pref, cur = i;
		if(tot > p)break;
		for(int j = i + k - 1; j < n; j += k){
			if(tot + arr[j] > p)break;
			tot += arr[j];
			cur += k;
		}
		pref += arr[i];
		cnt = max(cnt, cur);
	}
	printf("%d\n", cnt);
}

int main(){
	int q;
	scan(q);
	while(q--){
		solve();
	}
	return 0;
}
