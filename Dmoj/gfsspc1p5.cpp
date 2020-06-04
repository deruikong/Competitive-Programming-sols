#include "bits/stdc++.h"
#define scan(x) do{while((x=getchar())<'0'); for(x-='0'; '0'<=(_=getchar()); x=(x<<3)+(x<<1)+_-'0');}while(0)
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
char _;

int arr[1001];

int getdist(int a, int b){
	if(abs(a - b) < max(abs(a), abs(b))){
		return max(abs(a), abs(b));
	}
	else{
		return min(abs(a) * 2 + abs(b), abs(b) * 2 + abs(a));
	}
}

int main(){
	ios_base::sync_with_stdio(false); 
	cin.tie(NULL);
	int n, t, dist = INT_MAX; cin >> n >> t;
	for(int i = 0; i < n; i++) cin >> arr[i];
	sort(arr, arr + n);
	int l = 0, r = t - 1;
	// for(int i = 0; i < n; i++) cout << arr[i] << endl;
	while(r != n){
		dist = min(dist, getdist(arr[l++], arr[r++]));
	}
	cout << dist << endl;
	return 0;
}