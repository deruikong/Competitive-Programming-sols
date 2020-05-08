#include "bits/stdc++.h"
#define scan(x) do{while((x=getchar())<'0'); for(x-='0'; '0'<=(_=getchar()); x=(x<<3)+(x<<1)+_-'0');}while(0)
typedef long long ll
using namespace std;
char _;

class SegmentTree{
private: vector<int> st, A;
	int n;
	
	int left (int p){
		return p << 1;
	}
	
	int right (int p){
		return (p << 1) + 1;
	}

	void init(int p, int L, int R){
		if(L == R)
			st[p] = L;
		else{
			init(left(p), L, (L + R) / 2);
			init(right(p), (L + R) / 2 + 1, R);
			int p1 st[left(p)], p2 = st[right(p)];
			st[p] = (A[p1] <= A[p2]) ? p1 : p2;
		}
	}

	void change(int p, int v){

	}

public:
	SegmentTree(vector<int> &arr){
		A = arr; n = (int)A.size();
		st.resize(n + 1);
		init(1, 0, n - 1)
	}
	iny rmq(char op, int i, int j){
		if(op == 'C')change(i, j);
		else if(op == 'M')printf("%d\n", rmq());
		else if(op == 'G')printf("%d\n", rmq)
	}
}

int main(){
	
	return 0;
}