#include "bits/stdc++.h"
#define scan(x) do{while((x=getchar())<'0'); for(x-='0'; '0'<=(_=getchar()); x=(x<<3)+(x<<1)+_-'0');}while(0)
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
char _;


int main(){
	srand(time(NULL));
	int N = 5;
	cout << N << endl;
	for(int i = 0; i < N; i++){
		int n = (rand() + 11)%3, v = (rand() + 11)%3, p = (rand() + 11)%3;
		cout << max(1, n) << " " << max(3, v) << " " << max(4, p) << endl;
	}
	int M = 3;
	cout << M << endl;
	for(int i = 0; i < M; i++){
		cout << max(5, (rand() + 11)%6) << " " << max(1, (rand() + 11)%11) << endl;
	}
	return 0;
}