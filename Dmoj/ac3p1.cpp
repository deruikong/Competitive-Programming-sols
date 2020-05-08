#include <bits/stdc++.h>
#define INF 0x3f3f3f3f
#define ll long long
#define ull unsigned long long
#define pii pair<int, int>
#define pll pair<ll, ll>
#define pdd pair<double, double>
using namespace std;
const int MAX = 1000001;
int e[MAX];

int main(){
    int a, b, dis = 1;
    ll tot = 0;
    scanf("%d%d", &a, &b);
    vector<int> arr(a);
    for(int i = 0; i< a; i++){
        scanf("%d", &arr[i]);
        e[i] = 0;
    }
    e[arr[0]]++;
    for(int l = 0, r = 0; r < a;){
        if(dis >= b){
            tot += a-r;
            if(--e[arr[l++]] == 0)dis--;
        }
        else{
            if(r+1 == a)break;
            if(e[arr[++r]]++ == 0)dis++;
        }
    }
    printf("%lld\n", tot);
}