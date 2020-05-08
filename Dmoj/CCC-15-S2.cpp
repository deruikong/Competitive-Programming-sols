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
    int N, M, tot = 0;
    scanf("%d%d\n", &N, &M);
    vector<int> vis(N+1);
    vector<char> jerseys(N+1);
    REP(i, 1, N){
        char c;
        scanf("%c\n", &c);
        if(c == 'S')jerseys[i] = 0;
        else if(c == 'M')jerseys[i] = 1;
        else jerseys[i] = 2;
    }
    REP(i, 1, M){
        char size;
        int num, s;
        cin>>size>>num;
        if(size == 'S')s = 0;
        else if(size == 'M')s = 1;
        else s = 2;
        if(!vis[num] && jerseys[num] >= s){
            tot++; vis[num] = true;
        }
    }
    printf("%d", tot);
    return 0;
}