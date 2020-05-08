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
    int N, M, vis = 1, tot = 0;
    scanf("%d%d", &M, &N);
    set<int> nyeoooooooooooooooooooooooooooooooooooooooooooooooooooooooowuuuuuuuuwuuuuuuuuuu;
    REP(i, 1, M)nyeoooooooooooooooooooooooooooooooooooooooooooooooooooooooowuuuuuuuuwuuuuuuuuuu.insert(-i);
    REP(i, 0, N-1){
        int iamafuckingplane;
        scanf("%d", &iamafuckingplane);
        if(nyeoooooooooooooooooooooooooooooooooooooooooooooooooooooooowuuuuuuuuwuuuuuuuuuu.lower_bound(-iamafuckingplane) == nyeoooooooooooooooooooooooooooooooooooooooooooooooooooooooowuuuuuuuuwuuuuuuuuuu.end()){
            printf("%d", tot);
            return 0;
        }
        tot++;
        nyeoooooooooooooooooooooooooooooooooooooooooooooooooooooooowuuuuuuuuwuuuuuuuuuu.erase(nyeoooooooooooooooooooooooooooooooooooooooooooooooooooooooowuuuuuuuuwuuuuuuuuuu.lower_bound(-iamafuckingplane));
    }
    printf("%d", tot);
    return 0;
}