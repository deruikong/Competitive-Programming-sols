#include "bits/stdc++.h"
#define scan(x) do{while((x=getchar())<'0'); for(x-='0'; '0'<=(_=getchar()); x=(x<<3)+(x<<1)+_-'0');}while(0)
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
char _;


int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n; cin >> n;
	vector<int> arr(n + 1), lis(n + 1, 1);
	for(int i = 0; i < n; i++){
		cin >> arr[i];
	}
	for(int i = 1; i < n; i++){
		for(int j = 0; j < i; j++){
			if(arr[i] >= arr[j] && lis[i] < lis[j] + 1){
				lis[i] = lis[j] + 1;
			}
		}
	}
	// for(int i = 0; i < n; i++)cout << lis[i] << " ";
	// cout << endl;
	cout << *max_element(lis.begin(), lis.end()) << endl;
	return 0;
}