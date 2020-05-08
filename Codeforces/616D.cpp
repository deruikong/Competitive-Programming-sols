// #include "bits/stdc++.h"
// #define scan(x) do{while((x=getchar())<'0'); for(x-='0'; '0'<=(_=getchar()); x=(x<<3)+(x<<1)+_-'0');}while(0)
// using namespace std;
// typedef long long ll;
// typedef pair<int, int> pii;
// char _;

// bool cmp(pii a, pii b){
// 	return abs(a.second - a.first) < abs(b.second - b.first);
// }

// int main(){
// 	int n, k;
// 	pii ans = make_pair(0, 0);
// 	scan(n);scan(k);
// 	vector<int> cnt(n + 1, 0);
// 	set<int> vis;
// 	for(int i = 1; i <= n; i++){
// 		int cur;scan(cur);
// 		if(!vis.count(cur))cnt[i] = 1;
// 		cnt[i] += cnt[i - 1];
// 		vis.insert(cur);
// 	}
// 	for(int i = 1; i <= n; i++){
// 		auto it = upper_bound(cnt.begin(), cnt.end(), k + cnt[i] - 1);it--;
// 		if(*it != k + cnt[i] - 1)continue;
// 		// if(it == cnt.end() || *it != k + cnt[i] - 1)continue;
// 		cout << i << " " << (it - cnt.begin()) << " " << *it << endl;;
// 		// ans = max(ans, make_pair(i, (int)(it - cnt.begin())), cmp);
// 		// for(int j = i; j <= n; j++){
// 		// 	// cout << cnt[j] - cnt[i - 1] << endl;
// 		// 	if(cnt[j] - cnt[i - 1] == k)cout << i << " " << j << endl;
// 		// }
// 	}
// 	printf("%d %d", ans.first, ans.second);
// 	return 0;
// }
#include "bits/stdc++.h"
#define scan(x) do{while((x=getchar())<'0'); for(x-='0'; '0'<=(_=getchar()); x=(x<<3)+(x<<1)+_-'0');}while(0)
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
char _;

bool cmp(pii a, pii b){
	return abs(a.second - a.first) < abs(b.second - b.first);
}

int main(){
	int n, k;
	pii ans = make_pair(1, 1);
	scan(n);scan(k);
	vector<int> arr(n + 1);
	map<int, int> cnt;
	for(int i = 0; i < n; i++){
		scan(arr[i]);
		// cout << arr[i] << endl;
	}
	cnt[arr[0]] = 1;
	for(int l = 0, r = 0;r < n;){
		// cout << cnt.size() << endl;
		// cout << l << " " << r << " " << (k)<< endl;
		if(cnt.size() > k){
			cnt[arr[l]]--;
			if(cnt[arr[l]] == 0)cnt.erase(arr[l]);
			l++;
		}
		else{
			if(r - l > ans.second - ans.first)ans = make_pair(l + 1, r + 1);
			cnt[arr[++r]]++;
		}
	}
	printf("%d %d\n", ans.first, ans.second);
	return 0;
}