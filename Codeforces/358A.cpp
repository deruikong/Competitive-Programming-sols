#include "bits/stdc++.h"
#define scan(x) do{while((x=getchar())<'0'); for(x-='0'; '0'<=(_=getchar()); x=(x<<3)+(x<<1)+_-'0');}while(0)
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
char _;
int arr[(int)1e3 + 1];

bool intersect(int l, int r){
	int a = arr[l], b = arr[l + 1], c = arr[r], d = arr[r + 1];
	if(a > b)swap(a, b);
	if(c > d)swap(c, d);
	// cout << a << " " << b << " " << c << " " << d << " " <<  ((c < a < d < b) || b < d) << endl;
	return (a < c && c < b && b < d) || (c < a && a < d && d < b);
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n;
	cin >> n;
	for(int i = 0; i < n; i++){
		cin >> arr[i];
	}
	for(int i = 0; i < n - 1; i++){
		for(int j = i + 1; j < n - 1; j++){
			if(intersect(i, j)){
				cout << "yes" << endl;
				return 0;
			}
		}
	}
	cout << "no" << endl;
	return 0;
}