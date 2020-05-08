#include <bits/stdc++.h>
#define INF 0x3f3f3f3f 
#define ll long long
#define ull unsigned long long
#define pii pair<int, int>
#define pll pair<ll, ll>
#define pdd pair<double, double>
using namespace std;
int N, M, tot = 0;
double P, Q;
pii slope;
pdd pos;
vector<pdd> p;
vector<pair<pdd, pdd>> borders(4);
bool corner(pdd cur){
	return min(abs(cur.first-N), cur.first) < 5 && min(abs(cur.second-M), cur.second) < 5;
}

pdd getInt(pdd A, pdd B, pdd C, pdd D) 
{ 
    double a1 = B.second - A.second; 
    double b1 = A.first - B.first; 
    double c1 = a1*(A.first) + b1*(A.second); 
  
    double a2 = D.second - C.second; 
    double b2 = C.first - D.first; 
    double c2 = a2*(C.first)+ b2*(C.second); 
  
    double determinant = a1*b2 - a2*b1; 
    double x = (b2*c1 - b1*c2)/determinant; 
    double y = (a1*c2 - a2*c1)/determinant; 
    return make_pair(x, y);
} 
  

pdd newpos(pdd p){
	pdd p2, curr;
	p2 = make_pair(p.first+slope.first, p.second+slope.second);
	for(auto& x: borders){
		curr = getInt(p, p2, x.first, x.second);
		if(abs(curr.first-p.first < 0.01) && abs(curr.second-p.second) < 0.01)continue;
		else if(curr.first >= 0 && curr.first <= N && curr.second >= 0 && curr.second <= M)break;
	}
	return curr;
}

int main(){
	scanf("%d%d%lf%lf", &N, &M, &P, &Q);
	slope = make_pair(P-N, -Q);
	pos = make_pair(0, Q);
	borders[0] = make_pair(make_pair(0, 0), make_pair(0, M));
	borders[1] = make_pair(make_pair(0, 0), make_pair(N, 0));
	borders[2] = make_pair(make_pair(N, M), make_pair(N, 0));
	borders[3] = make_pair(make_pair(N, M), make_pair(0, M));
	int i;
	for(i = 0; i < 100000 && !corner(pos); i++){
		tot++;
		pos = newpos(pos);
		slope.first = -slope.first;
	}
	if(i==100000)printf("0");
	else printf("%d", tot);
	return 0;
}