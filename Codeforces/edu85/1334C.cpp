#include "bits/stdc++.h"
#define scan(x) do{while((x=getchar())<'0'); for(x-='0'; '0'<=(_=getchar()); x=(x<<3)+(x<<1)+_-'0');}while(0)
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
char _;

void solve(){
	int n, k, ans = 1e9;
	scanf("%d%d", &n, &k);
	vector<int> arr(n + 2), cnt(k * 2 + 1, 0), pref(k * 2 + 2, 0);
	for(int i = 1; i <= n; i++){
		scan(arr[i]);
	}
	for(int i = 1; i <= n/2; i++){
		cnt[arr[i] + arr[n - i + 1]]++;
	}
	for(int i = 1; i <= n/2; i++){
		int left = 1 + min(arr[i], arr[n - i + 1]), right = k + max(arr[i], arr[n - i + 1]);
		pref[left]++, pref[right + 1]--;
	}
	for(int i = 1; i <= 2 * k + 1; i++){
		pref[i] += pref[i - 1];
	}
	for(int i = 2; i <= 2 * k; i++){
		ans = min(ans, pref[i]-cnt[i] + (n/2 - pref[i]) * 2);
	}
	printf("%d\n", ans);
}

int main(){
	int T;
	scan(T);
	while(T--){
		solve();
	}	
	return 0;
}