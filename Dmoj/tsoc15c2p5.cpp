#include <bits/stdc++.h>
#define INF 0x3f3f3f3f
#define ll long long
#define ull unsigned long long
#define pii pair<int, int>
#define pll pair<ll, ll>
#define pdd pair<double, double>
#define REP(i,a,b) for (int i = int(a); i <= int(b); i++)
using namespace std;

int S;

struct beth{
    int b, c, d, i;
};

bool cmp(beth a, beth x){
    return a.b < x.b || (a.b == x.b && a.b >= S && a.c < x.c) || (a.b == x.b && a.b < S && a.d < x.d) || (a.b == x.b && a.b >= S && a.c == x.c && a.i < x.i) || (a.b == x.b && a.b < S && a.d == x.d && a.i < x.i);
}

int main(){
    int N;
    scanf("%d%d", &S, &N);
    vector<beth> arr(N);
    REP(i, 0, N-1){
        arr[i].i = i+1;
        scanf("%d%d%d", &arr[i].b, &arr[i].d, &arr[i].c);
    }
    sort(arr.rbegin(), arr.rend(), cmp);
    scanf("%d", &N);
    REP(i, 0, N-1){
        int idx;
        scanf("%d", &idx);
        cout << arr[idx-1].i << endl;
    }
    return 0;
}