#include "bits/stdc++.h"
#define scan(x) do{while((x=getchar())<'0'); for(x-='0'; '0'<=(_=getchar()); x=(x<<3)+(x<<1)+_-'0');}while(0)
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
char _;


int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n, k, d, cnt = 0;
	cin >> n >> k;
	d = 2 * k;
	vector<int> arr(n);
	for(int i = 0; i < n; i++){
		cin >> arr[i];
	}
	sort(arr.begin(), arr.end());
	for(int i = 0; i < n; i++){
		while(d < arr[i]){
			d *= 2; cnt++;
		}
		d = max(d, arr[i] * 2);
	}
	cout << cnt << endl;
	return 0;
}