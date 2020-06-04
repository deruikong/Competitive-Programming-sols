#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
char in[5010];
const int BB=26, MOD = 1e9 + 7;
ll ppow[5010], hhash[5010];
int n;
unordered_set<ll> us;

char* substr(const char *src, int m, int n)
{
    int len = n - m;
    char *dest = (char*)malloc(sizeof(char) * (len + 1));
    for (int i = m; i < n && (*(src + i) != '\0'); i++)
    {
        *dest = *(src + i);
        dest++;
    }*dest = '\0';
    return dest - len;
}

ll q(int l,int r){
    return ((((hhash[r]-hhash[l])*ppow[n-l-1]) % MOD) + MOD) % MOD;
}
int main() {
    scanf("%s",in);
    n=strlen(in);
    ppow[0]=1;
    for(int i=1; i<=n; i++){
        ppow[i]=ppow[i-1]*BB;
    }
    for(int i=0; i<n; i++){
        hhash[i+1]=(hhash[i]+(in[i]-'a'+1)*ppow[i]) % MOD;
    }
    int ans=0;
    for(int i = 1; i * 2 <= n; i++){
        for(int l = 0; l <= n - i; l++){
            ll curr = q(l, l + i), alt;
            // cout << curr << " " << substr(in, l, l + i) << endl;
            int k = l + i;
            while(k + i <= n){
                alt = q(k, k + i);
                // cout << alt << " " << substr(in, k, k + i) << endl;
                if(alt == curr){
                    ll altt = q(l, k + i);
                    if(us.find(altt) == us.end()){
                        // cout << altt << " " << substr(in, l, k + i) << endl;
                        us.insert(altt);
                    }
                }else break;
                k += i;
            }
            // cout << endl;
        }
    }
    printf("%d\n",us.size());
    return 0;
}