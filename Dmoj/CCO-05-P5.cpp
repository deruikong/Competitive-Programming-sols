// #include <bits/stdc++.h>
// #define INF 0x3f3f3f3f
// #define ll long long
// #define ull unsigned long long
// #define pii pair<int, int>
// #define pll pair<ll, ll>
// #define pdd pair<double, double>
// using namespace std;
// const int maxn = 2e6+1;
// ll N, tot = 0;


// int main(){
//     scanf("%d", &N);
//     for (int i = 0; i < N; i++)
//     {
//         int L, R;
//     }
//     printf("%d", tot);
//     return 0;
// }
#include <iostream>
#include <fstream>

using namespace std;

int main()
{
	int i, n;
	cin >> n;
	int L[n+1];
	int R[n+1];
	for (i=1; i<=n; i++) {
		cin >> L[i] >> R[i];
	}
	int lcost, rcost, llcost;
	lcost =n-L[n];
    rcost =n-2*L[n]+R[n];
    for (i=n-1; i>=1; i--) {
     llcost =1+R[i]-L[i] +min(abs(L[i+1]-R[i])+lcost, abs(R[i+1]-R[i])+rcost);
     rcost =1+R[i]-L[i] +min(abs(L[i+1]-L[i])+lcost, abs(R[i+1]-L[i])+rcost);
     lcost =llcost;
	}
   cout << min(L[1]-1+lcost,R[1]-1+rcost) << endl;
   return 0;
}