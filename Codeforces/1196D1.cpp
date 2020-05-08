#include "bits/stdc++.h"
#define scan(x) do{while((x=getchar())<'0'); for(x-='0'; '0'<=(_=getchar()); x=(x<<3)+(x<<1)+_-'0');}while(0)
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
char _;
const char t[4] = "RGB";


void solve(){
	int n, k, cnt, ans = 0x3f3f;
	scan(n);scan(k);
	char arr[n + 5];
	scanf("%s", arr);
	for(int i = 0; i < n - k + 1; i++){
		for(int  offset = 0; offset < 3; ++ offset){
			cnt = 0;
			for(int pos = 0; pos < k; ++pos){
				if(arr[i + pos] != t[(pos + offset) % 3]){
					cnt++;
				}
			}
			ans = min(ans, cnt);
		}
	}
	printf("%d\n", ans);
}

int main(){
	int q;
	scan(q);
	while(q--){
		solve();
	}
	return 0;
}