#include <bits/stdc++.h>
#define INF 0x3f3f3f3f
#define ll long long
#define ull unsigned long long
#define pii pair<int, int>
#define pll pair<ll, ll>
#define pdd pair<double, double>
using namespace std;


int main(){
    int N, l = INT_MAX, r = 0;
    scanf("%d",&N);
    vector<int> arr(N), ori(N);
    for (int i = 0; i < N; i++)
    {
        scanf("%d", &arr[i]);
        if(arr[i] == 0)
        {
            if(l == INT_MAX){l = i;r=l;}
            else r = i;
        }
    }
    if(l!=INT_MAX){
        int dis = -1;
        for(int i = l; i <= r; i++){
            if(arr[i] != 0){
                if(dis == -1)dis = arr[i];
                else if(arr[i] != dis){printf("NO");return 0;}
            }
        }
        if(dis==-1){
            if(l==0){
                if(r==N-1){printf("YES");return 0;}
                else{dis = arr[r+1];}
            }
            else dis = arr[l-1];
        }
        for(int i = l; i <= r; i++){
            arr[i] = dis;
        }
    }
    ori = arr;
    sort(arr.begin(), arr.end());
    for(int i = 0; i < N; i++){
        if(ori[i] != arr[i]){printf("NO");return 0;}
    }
    printf("YES");
    return 0;
}