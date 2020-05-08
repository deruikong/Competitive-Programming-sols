#include <bits/stdc++.h>
using namespace std;

int main() {

    long long int n, m, cur, h, l;
    scanf("%lld", &n);
    long long int a[n], b[n] = {0};
    for(int i = 0; i < n; i++)scanf("%lld", &a[i]);
    sort(a, a+n);
    for(int i = 0; i < n; i++)
    {
        b[i]+=a[i];
        if(i != 0) b[i]+=b[i-1];
    }
    scanf("%lld", &m);
    while(m--)
    {
        cin >> cur;
        //cout << cur << endl;
        l = 0;
        h = n-1;
        long long int ans = 0;
        if(cur <= a[l]){
            printf("0\n");
            continue;
        }
        while(l <= h)
        {
            int mid = l+(h-l)/2;
            if(a[mid] < cur){l = mid+1;ans = b[mid];}
            else h = mid-1;
        }
        printf("%lld\n", ans);
    }
    return 0;
};