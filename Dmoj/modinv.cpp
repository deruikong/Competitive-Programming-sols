#ifdef ray
#include "bits/stdc++.h"
#else
#include <bits/stdc++.h>
#endif
#define scan(x) do{while((x=getchar())<'0'); for(x-='0'; '0'<=(_=getchar()); x=(x<<3)+(x<<1)+_-'0');}while(0)
#define LINF 0x3f3f3f3f3f3f3f3f
#define INF 0x3f3f3f3f
#define ll long long
#define ull unsigned long long
#define pii pair<int, int>
#define pll pair<ll, ll>
#define pdd pair<double, double>
#define REP(i,a,b) for (int i = int(a); i <= int(b); i++)
using namespace std;
char _;
ull a, b;

void modinv(ull a, ull b){
	//if(b == 1)printf("-1\n");
	const ull bb = b;
	// ax+by = gcd(a, b);
	// modvinv only works when gcd is 1
	// if we replace b with MOD, we can remove by, so ax % MOD = gcd(a, b)
	// we don't have t cuz we don't care about it
	ll s = 0, prev = 1;
	while(a > 1 && b != 0){
		ll q = a/b, tmp; // get quotient
		
		tmp = b;
		b = a%b, a = tmp; // remainder
		
		tmp = s;
		s = prev - q*s;
		prev = tmp;

		// cout << a <<" " << b <<" " << s << endl;
	}
	if(prev < 0){
		prev += bb;
	}
	//s is the x, so 
	cout << prev << endl;
}

int main(){
	scan(a);scan(b);
	modinv(a, b);
	return 0;
}

// Iterative C++ program to find modular 
// inverse using extended Euclid algorithm 
// #include <stdio.h> 

// // Returns modulo inverse of a with respect 
// // to m using extended Euclid Algorithm 
// // Assumption: a and m are coprimes, i.e., 
// // gcd(a, m) = 1 
// int modInverse(int a, int m) 
// { 
// 	int m0 = m; 
// 	int y = 0, x = 1; 

// 	if (m == 1) 
// 	return 0; 

// 	while (a > 1) 
// 	{ 
// 		// q is quotient 
// 		int q = a / m; 
// 		int t = m; 

// 		// m is remainder now, process same as 
// 		// Euclid's algo 
// 		m = a % m, a = t; 
// 		t = y; 

// 		// Update y and x 
// 		y = x - q * y; 
// 		x = t; 
// 	} 

// 	// Make x positive 
// 	if (x < 0) 
// 	x += m0; 

// 	return x; 
// } 

// // Driver program to test above function 
// int main() 
// { 
// 	int a = 3, m = 11; 

// 	printf("Modular multiplicative inverse is %d\n", 
// 		modInverse(a, m)); 
// 	return 0; 
// } 
