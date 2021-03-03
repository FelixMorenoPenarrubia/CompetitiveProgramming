#include<bits/stdc++.h>

using namespace std;

typedef long long ll;

struct point {
    double x;
    double y;
};

double sq(double x) {
    return x*x;
}

double dist(point a, point b) {
    return sqrt(sq(a.x-b.x)+sq(a.y-b.y));
}

double area(point x, point y, point z) {
    double a = dist(x, y);
    double b = dist(y, z);
    double c = dist(z, x);
    double s = (a+b+c)/2;
    return sqrt(s*(s-a)*(s-b)*(s-c));
}

int main() {
    int T = 0;
    cin >> T;
    for(int t=0; t < T; ++t) {
        int n;
        cin >> n;
        vector<point> vpt;
        double minx = 1e9;
        double maxx = -1e9;
        double miny = 1e9;
        for(int i=0; i < n; ++i) {
            point p;
            cin >> p.x >> p.y;
            if(p.y <= miny) {
                if(p.y < miny) {
                    minx = 1e9;
                    maxx = -1e9;
                    miny = p.y;
                }
                minx = min(minx, p.x);
                maxx = max(maxx, p.x);
            }
            vpt.push_back(p);
        }
        double cmx = 0;
        double tarea = 0;
        for(int i=0; i < n-2; ++i) {
            double carea = area(vpt[0], vpt[i+1], vpt[i+2]);
            cmx += ((vpt[0].x+vpt[i+1].x+vpt[i+2].x)/3)*carea;
            tarea += carea;
        }
        cmx /= tarea;
        if(cmx > maxx or cmx < minx) cout << "NO" << endl;
        else cout << "YEJ" << endl;
        
    }
}
