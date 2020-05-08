#include "bits/stdc++.h"
#define scan(x) do{while((x=getchar())<'0'); for(x-='0'; '0'<=(_=getchar()); x=(x<<3)+(x<<1)+_-'0');}while(0)
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
char _;


int main(){
	int t, n, x;
	scan(t);
	while(t--){
		//cout << t << endl;
		scan(n);scan(x);
		int wealthy = 0;
		ll sum = 0;
		vector<int> arr(n + 1);
		for(int i = 0; i < n; i++){
			scan(arr[i]);
			//cout << arr[i] << endl;
		}
		sort(arr.rbegin(), arr.rend());
		for(int i = 0; i < n; i++){
			if(sum + (arr[i] - x) < 0)break;
			else wealthy++, sum += arr[i] - x;
		}
		//cout << "yes" << endl;
		printf("%d\n", wealthy);
	}
	return 0;
}