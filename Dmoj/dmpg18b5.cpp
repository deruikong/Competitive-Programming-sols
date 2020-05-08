#include "bits/stdc++.h"
#define scan(x) do{while((x=getchar())<'0'); for(x-='0'; '0'<=(_=getchar()); x=(x<<3)+(x<<1)+_-'0');}while(0)
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
char _;


int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int k, tot = 0;
	set<char> distinct;
	vector<int> cnt(26, 0);
	string str;
	cin >> str;
	cin >> k;
	for(int i = k - 1; i < str.length(); i++){
		//cout << str.substr(i - k + 1, k) << endl;
		if(i == k -1){
			for(int j = 0; j < k; j++){
				//cout << j;
				cnt[str[j] - 'a']++;
			}
			//cout << endl;
		}
		else{
			cnt[str[i - k] - 'a']--;
			cnt[str[i] - 'a']++;
		}
		int cur = 0;
		for(int i = 0; i < 26; i++){
			//cout << cnt[i] << " ";
			if(cnt[i])cur++;
		}
		//cout << endl;
		if(cur == 1)tot++;
	}
	cout << tot << endl;
	return 0;
}