#include <bits/stdc++.h>
#define INF 0x3f3f3f3f
#define ll long long
#define ull unsigned long long
#define pii pair<int, int>
#define pll pair<ll, ll>
#define pdd pair<double, double>
using namespace std;

bool myfunc(int a, int b){
    return a%10 < b%10 || (a%10 == b%10 && a > b);
}

int main(){
    int N;
    scanf("%d", &N);
    vector<int> arr(N);
    for (int i = 0; i < N; i++)
    {
        scanf("%d", &arr[i]);
    }
    sort(arr.begin(), arr.end(), myfunc);
    for(int x:arr){
        cout << x << " ";
    }
    return 0;
}