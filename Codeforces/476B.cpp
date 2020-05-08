#include "bits/stdc++.h"
#define scan(x) do{while((x=getchar())<'0'); for(x-='0'; '0'<=(_=getchar()); x=(x<<3)+(x<<1)+_-'0');}while(0)
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
char _;
double tot = 1;

int fpow(int base, int exp)
{
    int result = 1;
    for (;;)
    {
        if (exp & 1) result *= base;
        exp >>= 1;
        if (!exp) break;
        base *= base;
    }
    return result;
}

void bfs(string str, int& cnt, int pos){
	int len = str.length();
	list<pii> q;
	q.emplace_back(0, 0);
	while(!q.empty()){
		pii cur = q.front();q.pop_front();
		// cout << cur.first << " " << cur.second << endl;
		if(cur.first == pos && cur.second == len){
			cnt++;
			continue;
		}
		char ch = str[cur.second++];
		if(ch == '?' || ch == '+'){
			q.emplace_back(cur.first + 1, cur.second);
		}
		if(ch == '?' || ch == '-'){
			q.emplace_back(cur.first - 1, cur.second);
		}
	}
}

// void bfs(string str, int& cnt, int pos){
// 	int len = str.length();
// 	list<pair<int, string>> q;
// 	q.emplace_back(0, "");
// 	while(!q.empty()){
// 		pair<int, string> cur = q.front();q.pop_front();
// 		// cout << cur.second << " " << cur.first << endl;
// 		if(cur.first == pos && cur.second.length() == len){
// 			cnt++;
// 			continue;
// 		}
// 		char ch = str[cur.second.length()];
// 		if(ch == '?' || ch == '+'){
// 			q.emplace_back(cur.first + 1, cur.second + ch);
// 		}
// 		if(ch == '?' || ch == '-'){
// 			q.emplace_back(cur.first - 1, cur.second + ch);
// 		}
// 	}
// }

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int pos = 0, cnt = 0;
	string a, b;
	cin >> a >> b;
	for(char ch : a){
		//cout << ch;
		if(ch == '-')--pos;
		else ++pos;
	}
	for(char ch : b){
		if(ch == '?')tot *=2;
	}
	bfs(b, cnt, pos);
	// cout << cnt << " " << tot << endl;
	cout << fixed << setprecision(11) << cnt/tot << endl;
	return 0;
}