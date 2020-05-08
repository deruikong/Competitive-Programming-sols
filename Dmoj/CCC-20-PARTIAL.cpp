#include <bits/stdc++.h>
using namespace std;
#define d 256

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    string n, h;
    int nl, hl, tot = 0;
    const int arrLen = 26;
    int N[arrLen] = {0}, H[arrLen] = {0}, q = 101, m = 1;
    unordered_set<string> p;
    cin >> n >> h;
    nl = n.length();
    hl = h.length();
    if(nl <= hl){
        string t = h.substr(0, nl);
        for(int i = 0; i < nl; i++){
            H[h[i]-'a']++;
            N[n[i]-'a']++;
        }
        for(int i = 0; i < hl-nl+1; i++){
            if(i != 0){
                H[t[0]-'a']--;
                t.erase(0,1);
                H[h[i+nl-1]-'a']++;
                t.push_back(h[i+nl-1]);
            }
            if(p.find() != p.end())continue;
            p.insert(t);
            int j;
            for(j = 0; j < 26; j++){
                if(H[j]!=N[j])break;
            }
            if(j == 26)tot++;
        }
    }
    cout << tot;

    return 0;
}
