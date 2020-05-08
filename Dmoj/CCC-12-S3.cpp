#include <bits/stdc++.h>
#define INF 0x3f3f3f3f
#define ll long long
#define ull unsigned long long
#define pii pair<int, int>
#define pll pair<ll, ll>
#define pdd pair<double, double>
#define REP(i,a,b) for (int i = int(a); i <= int(b); i++)
using namespace std;
int a[1002];

int main(){
    int t, a1 = 0, a2 = 0;
    memset(a, 0, sizeof(a));
    scanf("%d", &t);
    REP(i, 1, t){
        int cur;scanf("%d", &cur);
        a[cur]++;
    }
    REP(i, 1, 1000){
        if(a[i] > a[a1])a2 = a1, a1 = i;
        else if(a[i] > a[a2])a2 = i;
        else if(a[i] == a[a2] && abs(i-a1)> abs(a2-a1))a2 = i;
    }
    printf("%d", abs(a2-a1));
    return 0;
}