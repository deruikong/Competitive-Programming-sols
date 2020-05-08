#include <bits/stdc++.h>
#define INF 0x3f3f3f3f
#define ll long long
#define ull unsigned long long
#define pii pair<int, int>
#define pll pair<ll, ll>
#define pdd pair<double, double>
using namespace std;
ll N, ori, ans;
double M;

ull countBits(ull n) 
{ 
   ull count = 0; 
   while (n) 
   { 
        count++; 
        n >>= 1; 
    } 
    return count; 
} 

int main(){
    scanf("%d%lf", &N, &M);
    ori = countBits(N-1);
    ans = ceil(ori/M);
    cout << ans;
    return 0;
}