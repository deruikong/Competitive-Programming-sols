#include <bits/stdc++.h>
#define INF 0x3f3f3f3f
#define ll long long
#define ull unsigned long long
#define pii pair<int, int>
#define pll pair<ll, ll>
#define pdd pair<double, double>
using namespace std;
int N, Q;

int main(){
    scanf("%d%d", &N, &Q);
    vector<int> a(N, 0);
    for (int i = 0; i < Q; i++)
    {
        int cur;
        scanf("%d", &cur);
        if(cur == 1){
            int idx;
            scanf("%d", &idx);
            a[--idx]++;
        }
        else if(cur == 2){
            int idx;
            scanf("%d", &idx);
            a[--idx]--;
        }
        else{
            int l, r, c, tot = 0;
            scanf("%d%d%d", &l, &r, &c);
            for(int j=l-1; j < r; j++){
                if(a[j]==c)tot++;
            }
            printf("%d\n", tot);
        }
    }
    
    return 0;
}