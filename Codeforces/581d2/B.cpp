#include "bits/stdc++.h"
#define scan(x) do{while((x=getchar())<'0'); for(x-='0'; '0'<=(_=getchar()); x=(x<<3)+(x<<1)+_-'0');}while(0)
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
char _;


int main(){
	int n, l, r, cnt = 0, MIN = 0, MAX = 0, largest = 1;
	scan(n);scan(l);scan(r);
	for(int i = 0; i < n; i++){
		if(cnt == l)MIN += 1;
		else{
			MIN += largest;
			largest *= 2;
			cnt++;
		}
	}
	cnt = 0, largest = 1;
	for(int i = 0; i < n; i++){
		if(cnt == r)MAX += largest/2;
		else{
			MAX += largest;
			largest *= 2;
			cnt++;
		}
	}
	printf("%d %d", MIN, MAX);
	return 0;
}