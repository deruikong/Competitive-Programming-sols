#include "bits/stdc++.h"
#define scan(x) do{while((x=getchar())<'0'); for(x-='0'; '0'<=(_=getchar()); x=(x<<3)+(x<<1)+_-'0');}while(0)
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
char _;

int main(){
	int t;
	scan(t);
	while(t--){
		int n, k, l = 1, maxp;
		scan(n);scan(k);
		vector<int> arr(n + 2), psa(n + 2);
		vector<bool> peek(n + 2, false);
		psa[0] = 0;
		for(int i = 1; i <= n; i++){
			scan(arr[i]);
		}
		for(int i = 1; i < k; i++){
			psa[i] = psa[i - 1];
			if(i > 2 && arr[i - 1] > arr[i] && arr[i - 1] > arr[i - 2])psa[i]++;
		}
		maxp = psa[k - 1];

		for(int i = k; i <= n; i++){
			psa[i] = psa[i - 1];
			if(arr[i - 1] > arr[i] && arr[i - 1] > arr[i - 2]){
				psa[i]++;
			}
			//psa[i] -= psa[i - k + 2];
		}

		for(int i = n; i >= k; i--){
			psa[i] -= psa[i - k + 2];
		}
		for(int i = 1; i <= n; i++){
			if(psa[i] > maxp)
			{
				l = i - k + 1;
				maxp = psa[i];
			}
		}
		printf("%d %d\n", maxp + 1, l);
	}
	return 0;
}