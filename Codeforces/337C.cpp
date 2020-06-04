#include "bits/stdc++.h"
#define scan(x) do{while((x=getchar())<'0'); for(x-='0'; '0'<=(_=getchar()); x=(x<<3)+(x<<1)+_-'0');}while(0)
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
char _;
int n, m, k;

bool good(int x){
	if(x * k > n) return false;
	return true;
}

int main(){
	cin >> n >> m >> k;
	int l = 0, h = n;
	while(l <= h){
		int mid = (l + h + 1)/2;
		if(good(mid)){
			l = mid;
		}
		else{
			h = mid - 1;
		}
	}
	cout << res(l) << endl;
	return 0;
}