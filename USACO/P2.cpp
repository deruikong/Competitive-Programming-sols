#include <bits/stdc++.h>
using namespace std;

struct point {
    int a;
    int b;

    bool operator<(point const& rhs) const{
        return tie(a, b) < tie(rhs.a, rhs.b);
    }
    bool operator == (point const& rhs) const{
        return tie(a, b) == tie(rhs.a, rhs.b);
    }
};

int main() {
    adsa
    ifstream fin;
    ofstream fout;
    fin.open("triangles.in");
    fout.open("triangles.out");
    string b, e;
    vector<point> p;
    set<point> cmp;
    getline(fin,b);
    int a = stoi(b);
    double area = 0;
    for (int i = 0; i < a; i++) {
        getline(fin, b);
        stringstream cur(b);
        vector<int> d;
        point c;
        while (getline(cur, e, ' '))d.emplace_back(stoi(e));
        c.a = d[0];
        c.b = d[1];
        p.emplace_back(c);
        cmp.insert(c);
    }
    for(int i = 0; i < p.size(); i++)
    {
        for(int j = i; j < p.size(); j++)
        {
            if(p[i].a != p[j].a && p[i].b != p[j].b)
            {
                point p1{p[i].a, p[j].b}, p2{p[i].b, p[j].a};
                if(cmp.find(p1) != cmp.end())
                {
                    cout << p1.a << p1.b;
                    area+= abs(p[i].a-p[j].a)*abs(p[i].a-p[j].a)/2;
                }
                if(cmp.find(p2) != cmp.end())
                {
                    cout << p2.a << p2.b;
                    area+= abs(p[i].a-p[j].a)*abs(p[i].a-p[j].a)/2;
                }
            }
        }
    }
}