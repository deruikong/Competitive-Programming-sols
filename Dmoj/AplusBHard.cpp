#include <bits/stdc++.h>

#define ll long long int
using namespace std;

struct pair_hash {
    template<class T1, class T2>
    std::size_t operator()(const std::pair<T1, T2> &p) const {
        auto h1 = std::hash<T1>{}(p.first);
        auto h2 = std::hash<T2>{}(p.second);
        return h1 ^ h2;
    }
};

int gcd(int a, int b) { return a == 0 ? b : (b % a, a); }

int fpow(int base, int exp) {
    int result = 1;
    for (;;) {
        if (exp & 1)result *= base;
        exp >>= 1;
        if (!exp)break;
        base *= base;
    }
    return result;
}

//a
void add(string a, string b){
    if(b.size() > a.size())swap(a, b);
    reverse(a.begin(), a.end());
    reverse(b.begin(), b.end());
    int as = a.size();
    for(int i = 0; i < b.size(); i++){
        char cur = b[i];
        if(a[i]-'0' + cur-'0' < 10)a[i] += cur-'0';
        else{
            a[i] = '0'+(a[i]-'0' + cur-'0')%10;
            if(i+1 == as)a.push_back('1');
            else {
                for (int j = i + 1; j < as; j++) {
                    if (a[j] - '0' + 1 < 10) {
                        a[j]++;
                        break;
                    }
                    a[j] = '0';
                    if (j == as-1){
                        a.push_back('1');
                    }
                }
            }
        }
    }
    reverse(a.begin(), a.end());
    cout << a << endl;
}
void sub(string a, string b){
    if(b.size() > a.size()){swap(a, b);cout << '-';}
    else if(b.size()==a.size()){
        for(int i = 0; i < b.size(); i++){
            if(a[i] < b[i]){swap(b,a);cout << '-';break;}
            else if(b[i] < a[i])break;
            if(a==b && i == b.size()-1){cout << 0 << endl; return;}
        }
    }
    reverse(a.begin(), a.end());
    reverse(b.begin(), b.end());
    for(int i = 0; i < b.size(); i++){
        char cur = b[i];
        if(a[i]-'0' - (cur-'0') >= 0)a[i] -= (cur-'0');
        else{
            a[i] += 10-(cur-'0');
            for(int j = i+1; j < a.size(); j++) {
                if(a[j] != 0){a[j]--;break;}
            }
        }
    }
    bool zero = true;
    reverse(a.begin(), a.end());
    for(char i : a){
        if(i == '0' && zero)continue;
        else {zero=false; cout << i;}
    }
    cout << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    ll n;
    cin >> n;
    while(n-->0)
    {
        string a, b;
        cin >> a >> b;
        if(a.front()!='-' && b.front()!='-')add(a,b);
        else if(a.front()=='-' && b.front()=='-'){a.erase(0, 1), b.erase(0, 1);cout << '-';add(a,b);}
        else if(a.front() < b.front())a.erase(0,1),sub(b,a);
        else b.erase(0, 1), sub(a, b);
    }
        //     if(a.front()!='-' && b.front()!='-')add(a,b);
        // else if(a.front()=='-' && b.front()=='-'){a.erase(0, 1), b.erase(0, 1);cout << '-';add(a,b);}
        // else if(a.front() < b.front())a.erase(0,1),sub(b,a);
        // else b.erase(0, 1), sub(a, b);
    return 0;
};