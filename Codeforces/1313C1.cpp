#include "bits/stdc++.h"
#define scan(x) do{while((x=getchar())<'0'); for(x-='0'; '0'<=(_=getchar()); x=(x<<3)+(x<<1)+_-'0');}while(0)
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
char _;


int main(){
	ll ans = 0;
	int n;
	scan(n);
	vector<int> a(n + 1), fin(n + 1);
	for(int i = 0; i < n; i++)scan(a[i]);
	for(int i = 0; i < n; i++){
		ll sum = a[i];
		vector<int> curr(n + 1);
		curr[i] = a[i];
		for(int j = i - 1; j >= 0; j--){
			curr[j] = min(a[j], curr[j + 1]);
			sum += curr[j];
		}
		for(int j = i + 1; j < n; j++){
			curr[j] = min(a[j], curr[j - 1]);
			sum += curr[j];
		}
		// cout << i << " " << sum << endl;
		// for(int j = 0; j < n; j++){
		// 	printf("%d ", curr[j]);
		// }
		// cout << endl;
		if(sum > ans){
			ans = sum;
			fin = curr;
		}
	}
	for(int i = 0; i < n; i++){
		printf("%d ", fin[i]);
	}
	printf("\n");
	return 0;
}