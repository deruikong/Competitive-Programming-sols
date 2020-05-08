#include "bits/stdc++.h"
#define scan(x) do{while((x=getchar())<'0'); for(x-='0'; '0'<=(_=getchar()); x=(x<<3)+(x<<1)+_-'0');}while(0)
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
char _;
int n; ll lf, rg, sum, w;

int main(){
	scan(n);scan(w);
	lf = w;
	for(int i = 0; i < n; i++){
		int x;
		scanf("%d", &x);
		sum += x;
		rg = max(rg, -sum);
		lf = min(lf, w - sum);
	}
	// cout << lf << " " << rg << endl;
	if(lf - rg  + 1 < 0) printf("0\n");
	else printf("%d\n", lf - rg + 1);
	return 0;
}