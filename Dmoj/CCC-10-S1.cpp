#ifdef ray
#include "bits/stdc++.h"
#else
#include <bits/stdc++.h>
#endif
#define INF 0x3f3f3f3f
#define ll long long
#define ull unsigned long long
#define pii pair<int, int>
#define pll pair<ll, ll>
#define pdd pair<double, double>
#define REP(i,a,b) for (int i = int(a); i <= int(b); i++)
using namespace std;
int N;
vector<pair<int, string>> r;

bool comp(pair<int, string> a, pair<int, string> b){
	return a.first > b.first || (a.first == b.first && a.second < b.second);
}

int main(){
	cin >> N;
	REP(i, 1, N){
		string cur;
		int a, b, c;
		cin >> cur >> a >> b >> c;
		r.emplace_back(2*a+3*b+c, cur);
	}
	sort(r.begin(), r.end(), comp);
	if(r.size() > 0)cout << r[0].second << endl;
	if(r.size() > 1)cout << r[1].second << endl;
	return 0;
}