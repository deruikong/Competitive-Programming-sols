#include "bits/stdc++.h"
#define scan(x) do{while((x=getchar())<'0'); for(x-='0'; '0'<=(_=getchar()); x=(x<<3)+(x<<1)+_-'0');}while(0)
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
char _;

int main(){
	int t;
	scan(t);
	while(t--){
		for(int i = 0; i < 9; i++){
			char a[15];
			scanf("%s", a);
			// cout << i << endl;
			// cout << a << endl;
			for(int j = 0; j < 9; j++){
				if(a[j] - '0' == 2) printf("1");
				else printf("%d", a[j] - '0');
			}
			printf("\n");
		}
	}
	return 0;
}