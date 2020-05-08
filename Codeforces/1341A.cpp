#include "bits/stdc++.h"
#define scan(x) do{while((x=getchar())<'0'); for(x-='0'; '0'<=(_=getchar()); x=(x<<3)+(x<<1)+_-'0');}while(0)
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
char _;
int t, n, a, b, c, d;

int main(){
	scan(t);
	while(t--){
		scanf("%d%d%d%d%d", &n, &a, &b, &c, &d);
		a -= b; b = a + 2 * b;
		a *= n, b *= n;
		c -= d; d = c + 2 * d;
		//cout << a << " " << b << " " << c << " " <<  d << " " << endl;
		if(b >= c && a <= d){
			printf("YES\n");
		}
		else
			printf("NO\n");
	}
	return 0;
}