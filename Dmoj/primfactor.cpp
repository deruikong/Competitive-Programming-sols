#include <bits/stdc++.h>
#define INF 0x3f3f3f3f
#define ll long long
#define ull unsigned long long
#define pii pair<int, int>
#define pll pair<ll, ll>
#define pdd pair<double, double>
#define REP(i,a,b) for (int i = int(a); i <= int(b); i++)
using namespace std;

void prime(int N){
    while(N%2==0){
        printf("2 ");
        N >>= 1;
    }
    for(int i = 3; i*i <= N; i+=2){
        while(N%i == 0)
        {
            printf("%d ", i);
            N/=i;
        }
    }
    if(N > 2)printf("%d ", N);
    printf("\n");
}

int main(){
    int T;
    scanf("%d", &T);
    while(T--){
        int N;
        scanf("%d", &N);
        prime(N);
    }
    return 0;
}