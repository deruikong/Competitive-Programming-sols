#include <bits/stdc++.h>
#define INF 0x3f3f3f3f
#define ll long long
#define ull unsigned long long
#define pii pair<int, int>
#define pll pair<ll, ll>
#define pdd pair<double, double>
using namespace std;
int N;

int main(){
    scanf("%d", &N);
    vector<int> arr(N);
    ll a = 0, b = 0;
    for (int i = 0; i < N; i++)
    {
        scanf("%d", &arr[i]);
        b+=arr[i];
    }
    b /= 2;
    sort(arr.rbegin(), arr.rend());
    for(int i = 1; i < N; i++){
        a+=arr[i];
    }
    cout << min(a,b);
    return 0;
}