#include "bits/stdc++.h"
#define ll long long
#define scan(x) do{while((x=getchar())<'0'); for(x-='0'; '0'<=(_=getchar()); x=(x<<3)+(x<<1)+_-'0');}while(0)
using namespace std;
char _;


int main(){
	int t, N;
	scan(t);
	while(t--){
		ll sum = 0;
		scan(N);
		vector<int> arr(N + 1), final;
		for(int i = 0; i < N; i++){
			scanf("%d", &arr[i]);
		}
		for(int i = 0; i < N; i++){
			//cout << i << endl;
			int cur = -0x3f3f3f3f;
			if(arr[i] > 0){
				while(true){
					cur = max(cur, arr[i]);
					if(arr[i + 1] < 0 || i + 1 == N) break;
					i++;
				}
			}
			else{
				while(true){
					cur = max(cur, arr[i]);
					if(arr[i + 1] > 0 || i + 1 == N) break;
					i++;
				}
			}
			sum += cur;
		}
		printf("%lld\n", sum);
	}
	return 0;
}