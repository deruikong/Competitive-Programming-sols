#include <bits/stdc++.h>
#define INF 0x3f3f3f3f
#define ll long long
#define ull unsigned long long
#define pii pair<int, int>
#define pll pair<ll, ll>
#define pdd pair<double, double>
#define REP(i,a,b) for (int i = int(a); i <= int(b); i++)
using namespace std;

int fpow(int base, int exp)
{
    int result = 1;
    for (;;)
    {
        if (exp & 1) result *= base;
        exp >>= 1;
        if (!exp) break;
        base *= base;
    }
    return result;
}

bool getres(int m, int x, int y){
    int cx = x, cy = y;
    if(m != 1)cx = x/fpow(5,m-1), cy = y/fpow(5, m-1);
    if((cx==1&&cy==0) || (cx==2 && cy<2) ||(cx==3 && cy==0))return true;
    else if(m != 1 && ((cx==1 && cy == 1) || (cx==3 && cy == 1)||(cx==2 && cy == 2)))return getres(m-1, x-cx*fpow(5, m-1), y-cy*fpow(5, m-1));
    else return false;
}

int main(){
    int t;
    scanf("%d", &t);
    while(t--){
        int m, x, y;
        scanf("%d%d%d", &m, &x, &y);
        if(getres(m, x, y))printf("crystal\n");
        else printf("empty\n");
    }
    return 0;
}