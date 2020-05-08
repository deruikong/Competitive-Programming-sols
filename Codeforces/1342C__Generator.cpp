#include "bits/stdc++.h"
#define scan(x) do{while((x=getchar())<'0'); for(x-='0'; '0'<=(_=getchar()); x=(x<<3)+(x<<1)+_-'0');}while(0)
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
char _;


int main(){
	int a, b;
	srand(time(NULL));
	cout << 1 << endl << max(11, rand() * 123 % 100) << " " << max(10, rand() * 123 % 100) << " 1" << endl;
	a = rand()%(int)1e3, b = rand()%(int)1e3;
	if(a > b)swap(a, b);
	cout << a << " " << b << endl;
	return 0;
}