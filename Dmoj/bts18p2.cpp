#include <bits/stdc++.h>
#define INF 0x3f3f3f3f
#define ll long long
#define ull unsigned long long
#define pii pair<int, int>
#define pll pair<ll, ll>
#define pdd pair<double, double>
using namespace std;

string tot;
int prearr[(int)1e6+1][26+1];

int main(){
    getline(cin, tot);
    for(int i = 0; i < 26; i++){
        prearr[0][i] = 0;
    }
    for(int i = 1; i< 1+tot.length(); i++){
        for(int j = 0; j < 26; j++){
            prearr[i][j] = prearr[i-1][j];
        }
        if(tot[i-1] == ' ')continue;
        else prearr[i][tot[i-1]-'a']++;
    }
    int N;
    scanf("%d", &N);
    for(int i = 0; i<N; i++){
        int l, r;
        char le;
        scanf("%d%d %c", &l, &r, &le);
        printf("%d\n", (prearr[r][le-'a']-prearr[l-1][le-'a']));
    }
    return 0;
}