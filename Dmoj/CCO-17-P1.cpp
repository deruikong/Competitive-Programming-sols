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
    int K;
    scanf("%d", &K);
    int cnt = 0, tot = 0;
    stringstream fout;
    while(K){
        int c = 1;
        while(c*(c-1)/2 <= K){
            c++;
        }
        c--;
        K -= c*(c-1)/2;
        c--;
        REP(i, cnt, cnt+c-1){
            fout << i+1 << " " << i+2 << endl;
        }
        fout << cnt + c + 1 << " " << cnt + 1 << endl;
        fout << cnt + c + 1 << " " << cnt + c + 2 << endl;
        cnt += c+1;
        tot += c + 2;
    }
    cout << cnt+1 << " " << tot << endl;
    cout << fout.str() << endl;
    return 0;
}