#include <bits/stdc++.h>
#define INF 0x3f3f3f3f
#define ll long long
#define ull unsigned long long
#define pii pair<int, int>
#define pll pair<ll, ll>
#define pdd pair<double, double>
using namespace std;


int main(){
    int a,b,c;
    cin>>a>>b>>c;
    if(a < b+c && b<c+a && c < b+a)printf("yes\n");
    else printf("no");
    return 0;
}