#include "bits/stdc++.h"
#define scan(x) do{while((x=getchar())<'0'); for(x-='0'; '0'<=(_=getchar()); x=(x<<3)+(x<<1)+_-'0');}while(0)
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
char _;
const int mn = 1e5 + 1;

void solve(){
	int n, arr[mn];
	bool bad = false, pos[mn + 1] = {0}, neg[mn + 1] = {0};
	scan(n);
	for(int i = 0; i < n; i++){
		scanf("%d", &arr[i]);
		//cout << arr[i] << endl;
		if(arr[i] > 0)pos[i + 1] = 1;
		else if(arr[i] < 0)neg[i + 1] = 1;
		pos[i + 1] += pos[i], neg[i + 1] += neg[i];
	}
	for(int i = 0; i < n; i++){
		int ans;
		scanf("%d", &ans);
		//cout << ans << arr[i] << endl;
		// cout << (ans > arr[i] && !pos[i]) << " " << (ans < arr[i] && !neg[i]) << endl;
		if((ans > arr[i] && !pos[i]) || (ans < arr[i] && !neg[i])){
			bad = true;
		}
	}
	if(!bad)
		printf("YES\n");
	else
		printf("NO\n");
}

int main(){
	int q;
	scan(q);
	while(q--){
		solve();
	}
	return 0;
}