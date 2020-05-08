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
    int N;
    scanf("%d", &N);
    vector<int> a, factors;
    set<int> f;
    int prev;
    scanf("%d", &prev);
    REP(i, 1, N-1)
    {
        int cur;
        scanf("%d", &cur);
        a.push_back(abs(cur-prev));
        prev = cur;
    }
    REP(i, 1, sqrt(a[0])){
        if(a[0]%i==0){
            if(a[0]/i!=i)factors.push_back(a[0]/i), f.insert(a[0]/i);
            factors.push_back(i);
            f.insert(i);
        }
    }
    for(int x:factors){
        REP(i, 0, N-2){
            if(a[i]%x != 0)f.erase(x);
        }
    }
    f.erase(1);
    for(int x: f){
        printf("%d", x);
        if(x == *f.rbegin())printf("\n");
        else printf(" ");
    }
    return 0;
}