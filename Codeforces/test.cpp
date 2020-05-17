#include "bits/stdc++.h"
#define scan(x) do{while((x=getchar())<'0'); for(x-='0'; '0'<=(_=getchar()); x=(x<<3)+(x<<1)+_-'0');}while(0)
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
char _;


int main(){
	int n, prev = 0;
	scan(n);
	vector<int> arr(n);
	vector<pii> ans(n);
	vector<bool> vis(n, false);
	bitset<30> val(1073741823);
	for(int i = 0; i < n; i++){
		scan(arr[i]);
		for(int j = 0; j < 30; j++){
			if(arr[i] & (1<<j)){
				if(!vis[j])vis[j] = 1;
				else val[j] = 0;
			}
		}
	}
	for(int i = 0; i < n; i++){
		ans[i] = {val.to_ulong() & arr[i], arr[i]};
	}
	sort(ans.rbegin(), ans.rend());
	for(auto& pp : ans){
		printf("%d ", pp.second);
	}
	printf("\n");
	return 0;
}