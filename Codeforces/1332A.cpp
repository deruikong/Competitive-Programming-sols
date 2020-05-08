#include "bits/stdc++.h"
#define scan(x) do{while((x=getchar())<'0'); for(x-='0'; '0'<=(_=getchar()); x=(x<<3)+(x<<1)+_-'0');}while(0)
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
char _;

bool intersect(int a,int l,int r){
	//cout << a << " " << l << " " << r << endl;
	if(l > r)swap(l, r);
	if(a >= l && a <= r) return true;
	return false;
}

void solve(){
	int a, b, c, d, x, y, x1, y1, x2, y2;
	scan(a);scan(b);scan(c);scan(d);
	scanf("%d%d%d%d%d%d", &x, &y, &x1, &y1, &x2, &y2);
	if((x1 - x2 == 0 && (a != 0 || b != 0)) || (y1 - y2 == 0 && (c != 0 || d != 0)) || !intersect(x + (b - a), x1, x2) || !intersect(y + (d - c), y1, y2)){
		//cout << (x1 - x2 == 0 && (a != 0 || b != 0)) << " " << (y1 - y2 == 0 && (c != 0 || d != 0)) << " " << !intersect(x + (a - b), x1, x2) << " " << !intersect(y + (c - d), y1, y2);
		printf("No\n");
	}
	else
		printf("Yes\n");
}

int main(){
	int q;
	scan(q);
	while(q--){
		solve();
	}
	return 0;
}