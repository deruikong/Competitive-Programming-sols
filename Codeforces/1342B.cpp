#include "bits/stdc++.h"
#define scan(x) do{while((x=getchar())<'0'); for(x-='0'; '0'<=(_=getchar()); x=(x<<3)+(x<<1)+_-'0');}while(0)
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
char _;

void solve(){
	bool same = true;
	int idx = 0;
	char str[105];
	scanf("%s", str);
	for(int i = 1; i < strlen(str); i++){
		if(str[i] != str[i - 1]){
			same = false;
			break;
		} 
	}
	if(same){
		printf("%s\n", str);
		return;
	}
	for(int i = 0; i < strlen(str); i++){
		printf("10");
	}
	printf("\n");
}

int main(){
	int t;
	scan(t);
	while(t--){
		solve();
	}
	return 0;
}