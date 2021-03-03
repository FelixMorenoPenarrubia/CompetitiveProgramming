#include<bits/stdc++.h>

using namespace std;

typedef long double ld;
typedef ld T;
const T INF = 1000000000000000LL;
const ld EPS = 1e-18;


struct Pt {
  T x, y;
  int id;
  Pt(T a, T b) : x(a), y(b) {}
  Pt() {} };
typedef Pt pt;

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
  return acos(ld(v*w)/norm(v)/norm(w)); }

 

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

typedef Pt point_t;

ld eps = EPS;
ld pi = 2*acos(0);
ld maxd = 1e18;

int dblcmp(double x) {
  return (x < -eps ? -1 : x > eps);
}

double cross(point_t p1, point_t p2) {
  return p1.x * p2.y - p2.x * p1.y;
}

double dot(point_t p1, point_t p2) {
  return p1.x * p2.x + p1.y * p2.y;
}

// count-clock wise is positive direction
double angle(point_t p1, point_t p2) {
  double x1 = p1.x, y1 = p1.y, x2 = p2.x, y2 = p2.y;
  double a1 = atan2(y1, x1), a2 = atan2(y2, x2);
  double a = a2 - a1;
  while (a < -pi) a += 2 * pi;
  while (a >= pi) a -= 2 * pi;
  return a;
}

bool onSeg(point_t p, point_t a, point_t b) {
  return dblcmp(cross(a - p, b - p)) == 0 && dblcmp(dot(a - p, b - p)) <= 0;
}

// 1 normal intersected, -1 denormal intersected, 0 not intersected
int testSS(point_t a, point_t b, point_t c, point_t d) {
  if (dblcmp(max(a.x, b.x) - min(c.x, d.x)) < 0) return 0;
  if (dblcmp(max(c.x, d.x) - min(a.x, b.x)) < 0) return 0;
  if (dblcmp(max(a.y, b.y) - min(c.y, d.y)) < 0) return 0;
  if (dblcmp(max(c.y, d.y) - min(a.y, b.y)) < 0) return 0;
  int d1 = dblcmp(cross(c - a, b - a));
  int d2 = dblcmp(cross(d - a, b - a));
  int d3 = dblcmp(cross(a - c, d - c));
  int d4 = dblcmp(cross(b - c, d - c));
  if ((d1 * d2 < 0) && (d3 * d4 < 0)) return 1;
  if ((d1 * d2 <= 0 && d3 * d4 == 0) || (d1 * d2 == 0 && d3 * d4 <= 0)) return -1;
  return 0;
}

vector<point_t> isLL(point_t a, point_t b, point_t c, point_t d) {
  point_t p1 = b - a, p2 = d - c;
  vector<point_t> ret;
  double a1 = p1.y, b1 = -p1.x, c1;
  double a2 = p2.y, b2 = -p2.x, c2;
  if (dblcmp(a1 * b2 - a2 * b1) == 0) return ret; // colined <=> a1*c2-a2*c1=0 && b1*c2-b2*c1=0
  else {
    c1 = a1 * a.x + b1 * a.y;
    c2 = a2 * c.x + b2 * c.y;
    ret.push_back(point_t((c1 * b2 - c2 * b1) / (a1 * b2 - a2 * b1), (c1 * a2 - c2 * a1) / (b1 * a2 - b2 * a1)));
    return ret;
  }
}

int cnt =0;
// O(NlogN) sol, Left is valid half plane. Note that the edge of hull may degenerate to a point.
struct hp_t {
	point_t p1, p2;
	double a;
	int id;
	hp_t() { }
	hp_t(point_t tp1, point_t tp2, int tid) : p1(tp1), p2(tp2), id(tid) {
		tp2 = tp2 - tp1;
		a = atan2(tp2.y, tp2.x);
	}
	bool operator==(const hp_t &r) const {
		return abs(a - r.a) < EPS;
	}
	bool operator<(const hp_t &r) const {
		if (abs(a - r.a) < EPS) return (area2(r.p1, r.p2, p2)) >= 0;
		else return a < r.a;
	}
} hp[500010];

void addhp(point_t p1, point_t p2) {
	hp[++cnt] = hp_t(p1, p2, -1);
}
void addhp(point_t p1, point_t p2, int id) {
	hp[++cnt] = hp_t(p1, p2, id);
}


void init() {
	cnt = 0;
	addhp(point_t(-maxd, -maxd), point_t(maxd, -maxd));
	addhp(point_t(maxd, -maxd), point_t(maxd, maxd));
	addhp(point_t(maxd, maxd), point_t(-maxd, maxd));
	addhp(point_t(-maxd, maxd), point_t(-maxd, -maxd));
}

bool checkhp(hp_t h1, hp_t h2, hp_t h3) {
	if(isLL(h1.p1, h1.p2, h2.p1, h2.p2).empty()) return true;
	point_t p = isLL(h1.p1, h1.p2, h2.p1, h2.p2)[0];
	return dblcmp(cross(p - h3.p1, h3.p2 - h3.p1)) > 0;
}

vector<int> ans;

vector<point_t> hp_inter() {
	sort(hp + 1, hp + 1 + cnt);
	cnt = unique(hp + 1, hp + 1 + cnt) - hp - 1;
	deque<hp_t> DQ;
	DQ.push_back(hp[1]);
	DQ.push_back(hp[2]);
	for (int i = 3; i <= cnt; ++i) {
		while (DQ.size() > 1 && checkhp(*----DQ.end(), *--DQ.end(), hp[i])) DQ.pop_back();
		while (DQ.size() > 1 && checkhp(*++DQ.begin(), *DQ.begin(), hp[i])) DQ.pop_front();
		DQ.push_back(hp[i]);
	}
	while (DQ.size() > 1 && checkhp(*----DQ.end(), *--DQ.end(), DQ.front())) DQ.pop_back();
	while (DQ.size() > 1 && checkhp(*++DQ.begin(), *DQ.begin(), DQ.back())) DQ.pop_front();
	DQ.push_front(DQ.back());
	vector<point_t> res;
	while (DQ.size() > 1) {
		hp_t tmp = DQ.front();
		DQ.pop_front();
		if(!isLL(tmp.p1, tmp.p2, DQ.front().p1, DQ.front().p2).empty()) res.push_back(isLL(tmp.p1, tmp.p2, DQ.front().p1, DQ.front().p2)[0]);
		//if(tmp.id > -1) ans.push_back(tmp.id);
	}
	return res;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int n;
	cin >> n;
	vector<pt> p(n);
	for(int i=0; i < n; ++i) {
		cin >> p[i].x >> p[i].y;
	}

	init();
	for(int i=0; i < n-1; ++i) {
		addhp(p[i+1], p[i]);
	}
	addhp(p[0], p[n-1]);
	vector<pt> pol = hp_inter();
	int m = pol.size();
	ld ar = 0;
	for(int i=0; i < m; ++i) {
	//	cerr << pol[i].x << " " << pol[i].y << endl;
		ar += pol[i].x*pol[(i+1)%m].y-pol[(i+1)%m].x*pol[i].y;
	}
	if(ar < 0) ar = -ar;
	ar *= 0.5;
	cout.setf(ios::fixed);
	cout << setprecision(10);

	cout << ar << endl;
}