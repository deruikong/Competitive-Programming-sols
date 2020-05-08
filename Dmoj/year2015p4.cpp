#include <bits/stdc++.h>
#define INF 0x3f3f3f3f
#define ll long long
#define ull unsigned long long
#define pii pair<int, int>
#define pll pair<ll, ll>
#define pdd pair<double, double>
#define REP(i,a,b) for (int i = int(a); i <= int(b); i++)
using namespace std;


int main(){
    int va, vb, m;
    scanf("%d%d%d", &va, &vb, &m);
    if(m%va!=0 && m%vb!=0 && m%(va-vb)!= 0)printf("Not possible!");
    return 0;
}