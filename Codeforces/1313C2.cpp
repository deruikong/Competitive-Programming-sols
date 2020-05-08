#include "bits/stdc++.h"
#define scan(x) do{while((x=getchar())<'0'); for(x-='0'; '0'<=(_=getchar()); x=(x<<3)+(x<<1)+_-'0');}while(0)
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
char _;


int main(){
	ll sum = -1, tmp = 0;
	int n, idx;
	scan(n);
	vector<ll> arr(n + 1), ml(n + 1), mr(n + 1), lf(n + 1, 0), rg(n + 1, 0);
	for(int i = 0; i < n; i++) scan(arr[i]);
	//precalc
	stack<pii> S;  
    for(int i = 0;i < n; i++){
    	while(!S.empty() && S.top().first >= arr[i])S.pop();
    	if(S.empty())ml[i] = -1;
    	else ml[i] = S.top().second;
    	S.emplace(arr[i], i);
    }
    while(!S.empty())S.pop();
	for(int i = 0; i < n; i++){
		if(ml[i] == -1){
			lf[i] = (i + 1) * arr[i];
		}
		else{
			lf[i] = lf[ml[i]] + arr[i] * (i - ml[i]);
		}
	}
	for(int i = n - 1;i >= 0; i--){
    	while(!S.empty() && S.top().first >= arr[i])S.pop();
    	if(S.empty())mr[i] = -1;
    	else mr[i] = S.top().second;
    	S.emplace(arr[i], i);
    }
	for(int i = n - 1; i >= 0; i--){
		if(mr[i] == -1){
			rg[i] = (n - i) * arr[i];
		}
		else{
			rg[i] = rg[mr[i]] + arr[i] * (mr[i] - i);
		}
	}

	for(int i = 0; i < n; ++i){
		ll alt = rg[i] + lf[i] - arr[i];
		if(alt > sum){
			idx = i;
			sum = alt;
		}
	}
	vector<ll> curr(n + 1);
	curr[idx] = arr[idx];
	for(int j = idx - 1; j >= 0; j--){
		curr[j] = min(arr[j], curr[j + 1]);
	}
	for(int j = idx + 1; j < n; j++){
		curr[j] = min(arr[j], curr[j - 1]);
	}
	for(int i = 0; i < n; i++){
		printf("%lld ", curr[i]);
	}
	printf("\n");
	return 0;
}