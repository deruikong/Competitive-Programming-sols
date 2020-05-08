#include <bits/stdc++.h>
#define INF 0x3f3f3f3f
#define ll long long
#define ull unsigned long long
#define pii pair<int, int>
#define pll pair<ll, ll>
#define pdd pair<double, double>
#define REP(i,a,b) for (int i = int(a); i <= int(b); i++)
using namespace std;
int N;

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

int main(){
    scanf("%d", &N);
    priority_queue<int> tot;
    int desire = N;
    REP(i, 0, N-1){
        int cur;
        scanf("%d", &cur);
        if(cur == desire){
            printf("%d ", cur);
            desire--;
            while(desire && !tot.empty()){
                int c = tot.top();
                if(c != desire)break;
                printf("%d ", c);
                desire--;
                tot.pop();
            }
        }
        else{
            tot.push(cur);
        }
        printf("\n");
    }

    return 0;
}