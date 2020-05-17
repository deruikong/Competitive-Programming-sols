#include "bits/stdc++.h"
#define scan(x) do{while((x=getchar())<'0'); for(x-='0'; '0'<=(_=getchar()); x=(x<<3)+(x<<1)+_-'0');}while(0)
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
char _;


int main(){
	int c, d, n, m, k, tot;
	cin >> c >> d >> n >> m >> k;
	tot = max(0, n * m - k);
	if(!tot){
		cout << 0 << endl;
	}
	else{
		cout << min(min(c * (tot/n + (bool)(tot%n)), tot * d), c*(tot/n) + d*(tot % n)) << endl;
	}
}