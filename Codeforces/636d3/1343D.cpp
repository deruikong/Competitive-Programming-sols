#include "bits/stdc++.h"
#define scan(x) do{while((x=getchar())<'0'); for(x-='0'; '0'<=(_=getchar()); x=(x<<3)+(x<<1)+_-'0');}while(0)
using namespace std;
char _;
int n, k;
pair<int, set<int>> max_freq;
vector<int> arr;
map<int, int> freq;

int go(int a, int b, int sum){
	if(sum > k + max(a, b)) return 2;
	else if(sum < 1 + min(a, b))return 2;
	else return 1;
}

int main(){
	int t;
	scan(t);
	//cout << t << endl;
	while(t--){
		int swaps = 0x3f3f;
		max_freq.first = 0;max_freq.second.clear();
		freq.clear();
		scan(n);scan(k);
		arr.resize(n + 2);
		for(int i = 1; i <= n; i++) scan(arr[i]);
		for(int i = 1; i <= n/2; i++){
			int sum = arr[i] + arr[n - i + 1];
			if(freq.find(sum) != freq.end()){
				freq[sum]++;
			}
			else{
				freq[sum] = 1;
			}
			// if(freq[sum] > max_freq.first){
			// 	max_freq.first = freq[sum];
			// 	max_freq.second.clear();
			// 	max_freq.second.insert(sum);
			// }
			// else if(freq[sum] == max_freq.first){
			// 	max_freq.second.insert(sum);
			// }
		}
		for(pair<int, int> cur : freq){
			int tmp = 0, x = cur.first;
			//printf("%d: \n", x);
			for(int i = 1; i <= n/2; i++){
				if(arr[i] + arr[n - i + 1] == x) continue;
				else tmp += go(arr[i], arr[n - i + 1], x);
			}
			swaps = min(swaps, tmp);
			//cout << tmp << endl;
		}
		printf("%d\n", min(swaps, n/2));
	}
	return 0;
}