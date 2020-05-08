#include <bits/stdc++.h>
#define INF 0x3f3f3f3f
#define ll long long
#define ull unsigned long long
#define pii pair<int, int>
#define pll pair<ll, ll>
#define pdd pair<double, double>
using namespace std;
int N, K;
vector<int> arr((int)101);

int main(){
    scanf("%d%d", &N, &K);
    for (int i = 1; i <= N; i++)
    {
        int cur;
        scanf("%d", &cur);
        if(abs(cur-i) % K != 0){printf("NO");return 0;}
    }
    printf("YES");
    return 0;
}