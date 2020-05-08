#include "bits/stdc++.h"
#define scan(x) do{while((x=getchar())<'0'); for(x-='0'; '0'<=(_=getchar()); x=(x<<3)+(x<<1)+_-'0');}while(0)
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
char _;

void solve(){
	int n;
	bool valid = 1;
	scanf("%d", &n);
	//cout << n << endl;
	vector<int> arr(n + 1);
	for(int i = 0; i < n; i++){
		scanf("%d", &arr[i]);
	}
	for(int i = 1; i < n; i++){
		//cout << arr[i] << " " << arr[i - 1] << endl;
		if(arr[i] < arr[i - 1] || arr[i] == arr[i - 1] + 1){
			continue;
		}
		else{
			valid = 0;
		}
	}
	if(valid){
		printf("YES\n");
	}
	else{
		printf("NO\n");
	}
}

int main(){
	int t;
	scan(t);
	while(t--){
		solve();
	}
	return 0;
}