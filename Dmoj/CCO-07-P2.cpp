#include <bits/stdc++.h>
#define INF 0x3f3f3f3f
#define ll long long
#define ull unsigned long long
#define pii pair<int, int>
#define pll pair<ll, ll>
#define pdd pair<double, double>
using namespace std;
int N;
set<vector<int>> a;

int main(){
    scanf("%d", &N);
    for(int i = 0; i < N; i++){
        vector<int> c1(6), cur(6);
        vector<vector<int>> perms(6), perms1(6);
        for (int j = 0; j < 6; j++)
        {
            scanf("%d", &c1[j]);
        }
        cur = c1;
        reverse(c1.begin(), c1.end());
        perms[0] = cur;
        perms1[0] = c1;
        for(int j = 1; j < 6; j++){
            for(int i = 0; i < 5; i++){
                swap(cur[i], cur[i+1]);
                swap(c1[i], c1[i+1]);
            }
            perms[j] = cur;
            perms1[j] = c1;
        }
        sort(perms.begin(), perms.end());
        sort(perms1.begin(), perms1.end());
        if(a.find(perms[0]) != a.end() || a.find(perms1[0]) != a.end()){printf("Twin snowflakes found.\n");return 0;}
        a.insert(perms[0]);
        a.insert(perms1[0]);
    }
    printf("No two snowflakes are alike.\n");
    return 0;
}