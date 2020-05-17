#include "bits/stdc++.h"
#define scan(x) do{while((x=getchar())<'0'); for(x-='0'; '0'<=(_=getchar()); x=(x<<3)+(x<<1)+_-'0');}while(0)
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
char _;


int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	string str; cin >> str;
	vector<unsigned char> rev(str.size(), 0);
	for(int i = 1; i < str.length(); i++){
		if(str[i] == 'a'){
			// cout << i << endl;
			rev[i] = 1;
			rev[i - 1] ^= 1;
		}
		// cout << i << " " << str[i] <<  endl;
	}
	for(bool a : rev){
		printf("%d ", a);
	}
	printf("\n");
	return 0;
}