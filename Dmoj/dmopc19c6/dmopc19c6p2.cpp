#include <bits/stdc++.h>
#define INF 0x3f3f3f3f
#define ll long long
#define ull unsigned long long
#define pii pair<int, int>
#define pll pair<ll, ll>
using namespace std;
double x1, x2, y5, y2, x3, x4, y3, y4;
double x, y;

int det(){
    double a = y2 - y5; 
    double b = x1 - x2; 
    double c = a*x1 + b*y5; 
  
    double a1 = y4 - y3; 
    double b1 = x3 - x4; 
    double c1 = a1*x3+ b1*y3;
    double d = a*b1-a1*b;
    if(d==0){
        if(abs(a)*abs(b1)==abs(a1)*abs(b) && abs(a)*abs(c1) == abs(a1)*abs(c))return 1;
        return 0;
    }
    x = (b1*c - b*c1)/d; 
    y = (a*c1 - a1*c)/d;
    return -1;
}

int main(){
    cin >> x1 >> y5 >> x2 >> y2;
    cin >> x3 >> y3 >> x4 >> y4;
    int ret = det();
    if(ret==1)printf("coincident");
    else if(ret==0)printf("parallel");
    else{
        printf("%lf %lf", x, y);
    }
    return 0;
}