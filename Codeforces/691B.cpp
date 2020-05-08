#include "bits/stdc++.h"
#define scan(x) do{while((x=getchar())<'0'); for(x-='0'; '0'<=(_=getchar()); x=(x<<3)+(x<<1)+_-'0');}while(0)
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
char _;
string sym = "AOoTUVvWwXxYMIH";
map<char, char> opp = {
	{'p', 'q'},
	{'q', 'p'},
	{'b', 'd'},
	{'d', 'b'}
};

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	string str;cin >> str;
	if(str.length() < 2 && sym.find(str[0]) == string::npos){
		printf("NIE\n");
		return 0;
	}
	for(int i = 0; i <= str.length() / 2; i++){
		// cout << str[i] << "  " << (sym.find(str[i]) == string::npos) << (opp.find(str[i]) == opp.end()) << endl;
		if(sym.find(str[i]) == string::npos && opp.find(str[i]) == opp.end()){
			printf("NIE\n");
			return 0;
		}
		else if(sym.find(str[i]) != string::npos && str[i] != str[str.length() - i - 1]){
			printf("NIE\n");
			return 0;
		}
		else if(opp.find(str[i]) != opp.end() && opp[str[i]] != str[str.length() - i - 1]){
			printf("NIE\n");
			return 0;
		}
	}
	printf("TAK\n");
	return 0;
}