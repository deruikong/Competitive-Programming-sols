//
// Created by RayKo on 2020-02-28.
//

#include <bits/stdc++.h>
using namespace std;

struct comp {
    bool operator() (const char& lhs, const char& rhs) const
    {return lhs<rhs;}
};

int main() {
    int a = 0;
    char cur;
    map<char,pair<int, int>> dis = {
            {'A',make_pair(0, 0)},
            {'B',make_pair(0,1)},
            {'C',make_pair(0,2)},
            {'D',make_pair(0,3)},
            {'E',make_pair(1,0)},
            {'F',make_pair(1,1)},
            {'G',make_pair(1,2)},
            {'H',make_pair(1,3)},
            {'I',make_pair(2,0)},
            {'J',make_pair(2,1)},
            {'K',make_pair(2,2)},
            {'L',make_pair(2,3)},
            {'M',make_pair(3,0)},
            {'N',make_pair(3,1)},
            {'O',make_pair(3,2)},
    };

    for(int i = 0; i<4; i++)
    {
        for(int j = 0; j < 4; j++){
            cin >> cur;
            if(cur != '.')a+=abs(dis[cur].first-i)+abs(dis[cur].second-j);
        }
    }
    cout << a;
    return 0;
};
