#include "bits/stdc++.h"
#define scan(x) do{while((x=getchar())<'0'); for(x-='0'; '0'<=(_=getchar()); x=(x<<3)+(x<<1)+_-'0');}while(0)
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
char _;

int main(){
	priority_queue<pii> q, q1;
	int n, m, c;
	bool yes = false;
	scan(n);scan(m);scan(c);
	vector<int> arr(n + 1);
	for(int i = 0; i < n; i++)scan(arr[i]);
	for(int i = m - 1; i < n; i++){
		if(i == m - 1){
			for(int j = 0; j < m; j++){
				q.push(make_pair(arr[j], j));
				q1.push(make_pair(-arr[j], j));
			}
		}
		else{
			while(true){
				bool changed = false;
				pii cur = q.top(), cur1 = q1.top();
				if(cur.second < i - m + 1){
					changed = true;
					q.pop();
				}
				if(cur1.second < i - m + 1){
					changed = true;
					q1.pop();
				}
				// cout << changed << endl;
				if(!changed)break;
			}
			q.push(make_pair(arr[i], i));
			q1.push(make_pair(-arr[i], i));
		}
		//cout << q.top().first << " " << -q1.top().first << endl;
		if(q.top().first + q1.top().first <= c){
			yes = true;
			printf("%d\n", i - m + 2);
		}
	}
	if(!yes)printf("NONE");
	return 0;
}