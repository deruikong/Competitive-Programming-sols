#include <bits/stdc++.h>
#define INF 0x3f3f3f3f
#define ll long long
#define ull unsigned long long
#define pii pair<int, int>
#define pll pair<ll, ll>
#define pdd pair<double, double>
using namespace std;


int main(){
    int N,K;
    scanf("%d%d", &N, &K);
    vector<int> arr(N);
    for (int i = 0; i < N; i++)
    {
        scanf("%d", &arr[i]);
    }
    sort(arr.begin(), arr.end());
    int MAX = 0;
    for(int l = 0, r = 0; r < N;){
        if(arr[r]-arr[l] <= K)MAX = max(MAX, (r++)-l+1);
        else l++;
    }
    printf("%d", MAX);
    return 0;
}