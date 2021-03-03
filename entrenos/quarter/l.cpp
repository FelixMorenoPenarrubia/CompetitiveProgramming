#include<bits/stdc++.h>


using namespace std;


typedef long double ld;

typedef ld T; //Tipus del punt: Tocar aixo!
const T INF = 1000000000000000LL;
const ld EPS = 1e-9;
const ld PI = 2*acos(0.0);

struct Pt {
  T x, y;
  int id;
  Pt(T a, T b) : x(a), y(b) {}
  Pt() {} };
//Tocar aixo!
inline bool EQ(T a, T b) { return abs(a - b) < EPS; }
inline T sq(T n) { return n*n; }
inline Pt operator+(Pt a, Pt b) {
  return Pt(a.x + b.x, a.y + b.y); }
inline Pt operator-(Pt a, Pt b) {
  return Pt(a.x - b.x, a.y - b.y); }
inline Pt operator*(T k, Pt a) {
  return Pt(k*a.x, k*a.y); }
inline Pt operator/(Pt a, T k) {
  return Pt(a.x/k, a.y/k); }
inline T operator^(Pt a, Pt b) {
  return a.x*b.y - a.y*b.x; }
inline T operator*(Pt a, Pt b) {
  return a.x*b.x + a.y*b.y; }
inline bool operator==(Pt a, Pt b) {
  return EQ(a.x, b.x) and EQ(a.y, b.y); }
inline bool operator!=(Pt a, Pt b) {
  return !(a == b); }
inline bool operator<(Pt a, Pt b) {
  return EQ(a.x, b.x) ? a.y < b.y : a.x < b.x; }
inline bool operator<=(Pt a, Pt b) {
  return a < b or a == b; }
inline bool operator>(Pt a, Pt b) {
  return !(a <= b); }
inline bool operator>=(Pt a, Pt b) {return !(a < b);}
ostream& operator<<(ostream& out, Pt a) {
  out << "(" << a.x << "," << a.y << ")";return out;}
istream& operator>>(istream& in, Pt& a) {
  in >> a.x >> a.y; return in; }

inline ld area2(Pt a, Pt b, Pt c) {
  return (b - a)^(c - a); } //a is the central point
inline T dist2(Pt a, Pt b) {return (a - b)*(a - b); }
inline ld dist(Pt a, Pt b) {return sqrt(dist2(a,b));}
inline T norm2(Pt a) { return a*a; }
inline ld norm(Pt a) { return sqrt(a*a); }
inline Pt unit(Pt a) { return a/norm(a); }
Pt rot(Pt a) { return Pt(-a.y, a.x); } //CC
Pt rot(Pt a, ld alfa) {
  return Pt(a.x*cos(alfa) - a.y*sin(alfa),
      a.x*sin(alfa) + a.y*cos(alfa)); } //T ld. CC
ld angle_2_vectors(Pt v, Pt w) {
	if(abs(ld(v*w)/(norm(v)*norm(w))) >= 1) {
		return 0;
	}
  return acos(ld(v*w)/(norm(v)*norm(w))); }

// Distance between (p) and the line (a + k * v)
ld dist_punt_recta(Pt a, Pt v, Pt p) {
  return abs(unit(rot(v))*(p - a)); }

// returns: 0 -> parallel, 1 -> single point,
// 2 -> equivalent lines
int lines_intersection(Pt p1, Pt v1,
    Pt p2, Pt v2, Pt& p) {
  if (EQ(v1^v2, 0)) return EQ((p2 - p1)^v1, 0) ? 2:0;
  ld t = ((p1.y - p2.y)*v2.x +
      (p2.x - p1.x)*v2.y)/(v1^v2);
  p = p1 + t*v1;
  return 1;
}
vector<ld> solve_equation(ld a, ld b, ld c) {
  ld d = b*b - 4*a*c;
  if (abs(d) < EPS) d = 0;
  if (d < 0) return vector<ld>(0);
  vector<ld> res(1, (-b + sqrt(d))/(2*a));
  if (d > 0) res.push_back((-b - sqrt(d))/(2*a));
  return res;
}
//Pre: T is ld
vector<Pt> line_circle_intersection(
    Pt p, Pt v, Pt c, ld r) {
  Pt u = p - c;
  vector<ld> lambda =
    solve_equation(norm2(v), 2*u*v, norm2(u) - r*r);
  vector<Pt> res(lambda.size());
  for (int i = 0; i < res.size(); ++i)
    res[i] = p + lambda[i]*v;
  return res;
}
//Pre: T is ld
vector<Pt> circle_circle_intersection(
    Pt c1, ld r1, Pt c2, ld r2) {
  ld d = dist(c1, c2);
  if (r1 + r2 + EPS < d) return vector<Pt>();
  ld t = d*d - r2*r2 + r1*r1; ld x = t/(2*d);
  if (x + EPS < d - r2 or x - EPS > r1)
    return vector<Pt>();
  ld t2 = (sq(2*d*r1) - t*t)/sq(2*d);
  if (abs(t2) < EPS) t2 = 0;
  if (t2 < 0) return vector<Pt>();
  ld y = sqrt(t2);
  vector<Pt> res(1,
      c1 + x*unit(c2 - c1) + y*unit(rot(c2 - c1)));
  if (t2 > 0) res.push_back(
      c1 + x*unit(c2 - c1) - y*unit(rot(c2 - c1)));
  return res;
}

// Lower and the upper bound of the convex hull
pair<vector<Pt>, vector<Pt> >
convex_hull(vector<Pt>& v) {
  int n = v.size(), k1 = 0, k2 = 0;
  vector<Pt> L(n), U(n);
  sort(v.begin(), v.end());
  for (int i = 0; i < n; ++i) {
    while (k1 >= 2 and
        area2(L[k1 - 2], L[k1 - 1], v[i]) <= 0) --k1;
    while (k2 >= 2 and
        area2(U[k2 - 2], U[k2 - 1], v[i]) >= 0) --k2;
    L[k1++] = U[k2++] = v[i];
  }
  L.resize(k1); U.resize(k2);
  return {L, U};
}

vector<Pt> unify(pair<vector<Pt>, vector<Pt> > CH) {
  for (int i = CH.second.size() - 2; i >= 1; --i)
  CH.first.push_back(CH.second[i]);
  return CH.first;
}



typedef Pt pt;



bool cmp(pt a, pt b) {
    return a.x < b.x || (a.x == b.x && a.y < b.y);
}

bool cw(pt a, pt b, pt c) {
    return a.x*(b.y-c.y)+b.x*(c.y-a.y)+c.x*(a.y-b.y) < 0;
}

bool ccw(pt a, pt b, pt c) {
    return a.x*(b.y-c.y)+b.x*(c.y-a.y)+c.x*(a.y-b.y) > 0;
}

void convex_hull_cp(vector<pt>& a) {
    if (a.size() == 1)
        return;

    sort(a.begin(), a.end(), &cmp);
    pt p1 = a[0], p2 = a.back();
    vector<pt> up, down;
    up.push_back(p1);
    down.push_back(p1);
    for (int i = 1; i < (int)a.size(); i++) {
        if (i == a.size() - 1 || cw(p1, a[i], p2)) {
            while (up.size() >= 2 && !cw(up[up.size()-2], up[up.size()-1], a[i]))
                up.pop_back();
            up.push_back(a[i]);
        }
        if (i == a.size() - 1 || ccw(p1, a[i], p2)) {
            while(down.size() >= 2 && !ccw(down[down.size()-2], down[down.size()-1], a[i]))
                down.pop_back();
            down.push_back(a[i]);
        }
    }

    a.clear();
    for (int i = 0; i < (int)up.size(); i++)
        a.push_back(up[i]);
    for (int i = down.size() - 2; i > 0; i--)
        a.push_back(down[i]);
}

int main() {

	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int n;
	ld r;

	cin >> n >> r;

	vector<pt> v;

	for(int i=0; i < n; ++i) {
		int k;
		cin >> k;
		for(int j=0; j < k; ++j) {
			ld x, y;
			cin >> x >> y;
			v.push_back(pt(x, y));
			
		}
	}

	sort(v.begin(), v.end());
	v.resize(unique(v.begin(), v.end())-v.begin());

	//vector<pt> ch = unify(convex_hull(v));
	convex_hull_cp(v);
	vector<pt> ch = v;
	n = ch.size(); 
	ld ans = 0;
	for(int i=0; i < n; ++i) {
		pt next = ch[(i+1+n)%n];
		pt prev = ch[(i-1+n)%n];
		if(ch[i] == prev) {
			continue;
		}
		ans += dist(ch[i], prev);
		ans += r*(angle_2_vectors(ch[i]-prev, next-ch[i]));

		//cerr << prev << ch[i] << next << endl;

		//cerr << "Prev dist: " << dist(ch[i], prev) << " ang dist: " << r*angle_2_vectors(ch[i]-prev, ch[i]-next) << endl;
	}

	cout.setf(ios::fixed);
	cout << setprecision(5);
	cout << ans << '\n';
}
