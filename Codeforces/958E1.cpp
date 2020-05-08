#include "bits/stdc++.h"
#define scan(x) do{while((x=getchar())<'0'); for(x-='0'; '0'<=(_=getchar()); x=(x<<3)+(x<<1)+_-'0');}while(0)
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
char _;
struct p{
	int x, y;
};
vector<p> base, rebel;
int main(){
	int r, b;
	scan(r);scan(b);
	for(int i = 0; i < r; i++){
		int x, y;
		scanf("%d%d", &x, &y);
		rebel.push_back(p{x, y});
	}
	for(int i = 0; i < b; i++){
		int x, y;
		scanf("%d%d", &x, &y);
		base.push_back(p{x, y});
	}
	if(r != b)printf("No\n");
	else printf("Yes\n");
	return 0;
}