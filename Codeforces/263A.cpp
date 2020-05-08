#include "bits/stdc++.h"
#define scan(x) do{while((x=getchar())<'0'); for(x-='0'; '0'<=(_=getchar()); x=(x<<3)+(x<<1)+_-'0');}while(0)
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
char _;


int main(){
	for(int i = 0; i < 5; i++){
		for(int j = 0; j < 5; j++){
			int cur;scan(cur);
			if(cur){
				printf("%d\n", abs(i - 2) + abs(j - 2));
			}
		}
	}
	return 0;
}