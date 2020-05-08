#include "bits/stdc++.h"
#define scan(x) do{while((x=getchar())<'0'); for(x-='0'; '0'<=(_=getchar()); x=(x<<3)+(x<<1)+_-'0');}while(0)
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
char _;


void solve(){
	int n;
	cin >> n;
	vector<string> pipe(2);
	cin >> pipe[0] >> pipe[1];
	int r = 0, c = 0;
	for(c = 0; c < n; c++){
		if(pipe[r][c] >= '3'){
			if(pipe[r ^ 1][c] < '3') break;
			else r ^= 1;
		}
	}
	// cout << c << " " << r << endl;
	if(c == n && r == 1){
		cout << "YES" << '\n';
	}
	else{
		cout << "NO" << '\n';
	}
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	int q;
	cin >> q;
	while(q--){
		solve();
	}
	return 0;
}