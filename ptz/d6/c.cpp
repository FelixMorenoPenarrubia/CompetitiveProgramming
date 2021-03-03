#include <bits/stdc++.h>
using namespace std;

typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<vvi> vvvi;
typedef pair<int, int> pi;
typedef vector<pi> vpi;

typedef long double ld;
typedef ld T; //Tipus del punt: Tocar aixo!
const T INF = 1000000000000000LL;
const ld EPS = 1e-5;
const ld PI = acos(-1);

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
  return acos(ld(v*w)/norm(v)/norm(w)); }

vector<ld> solve_equation(ld a, ld b, ld c) {
  ld d = b*b - 4*a*c;
  if (abs(d) < EPS) d = 0;
  if (d < 0) return vector<ld>(0);
  vector<ld> res(1, (-b + sqrt(d))/(2*a));
  if (d > 0) res.push_back((-b - sqrt(d))/(2*a));
  return res;
}

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

// Returns a pair of the two points on the circle
// with radius r centered around c whose tangent
// lines intersect p. If p lies within the circle
// NaN-points are returned. T = double. The first
// point is the one to the right as seen from p
// towards c. TESTED.
vector<Pt> circleTangents(Pt p, Pt c, ld r) {
  Pt a = p - c;
  ld x = r*r/norm2(a), y = sqrt(x-x*x);
  vector<Pt> v(2);
  v[0] = c+x*a+y*rot(a);
  v[1] = c+x*a-y*rot(a);
  return v;
}

bool pointInsideSegment(Pt s1, Pt s2, Pt p) {
  if (s1.x == s2.x)
    return (s1.y <= p.y and p.y <= s2.y)
      or (s2.y <= p.y and p.y <= s1.y);
  return (s1.x <= p.x and p.x <= s2.x)
    or (s1.x >= p.x and p.x >= s2.x);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.setf(ios::fixed);
    cout.precision(3);
    int t;
    cin >> t;
    while (t--) {
        Pt a, b, o;
        ld r;
        cin >> a >> b >> o >> r;
        Pt u = b-a;
        vector<Pt> v = line_circle_intersection(a, u, o, r);
        if (v.size() == 2 and pointInsideSegment(a, b, v[0]) and pointInsideSegment(a, b, v[1])) {

        	//cerr << v[0] << endl;

            vector<Pt> v1 = circleTangents(a, o, r);
            vector<Pt> v2 = circleTangents(b, o, r);
            ld best = INF;
            for (int i = 0; i < 4; ++i) {
                Pt p1 = v1[(i&2)>>1];
                Pt p2 = v2[i&1];
                Pt u1 = p1 - o;
                Pt u2 = p2 - o;
                ld d = dist(p1, a) + dist(p2, b);
                ld theta1 = atan2(u1.y, u1.x);
                ld theta2 = atan2(u2.y, u2.x);
                ld theta = fabs(theta1-theta2);
                if (theta > PI) theta = 2*PI - theta;
                d += r*theta;
                if (d < best) best = d;
            }
            cout << best << endl;
        }
        else {

        	//cerr << "Via 2" << endl;
        	
        	if(((a-o)^(b-o)) < 0) {

        	//	cerr << "swap" << endl;

        		swap(a, b);
       		}
        	ld ang = angle_2_vectors(a-o, b-o);
        	
       		Pt dir_a = a-o;
        	Pt dir_b = b-o;
        	ld ang_a = atan2(dir_a.y, dir_a.x);

        	

        	vector<Pt> va = circleTangents(a, o, r);
            vector<Pt> vb = circleTangents(b, o, r);

            ld l = max((ld)0.0, ang-angle_2_vectors(dir_b, vb[0]-o));
       		ld h = min(ang, angle_2_vectors(dir_a, va[0]-o));


       		
       		ld EPS_BS = 1e-16;
       		while(h-l > EPS_BS) {
       			ld md = (l+h)/2;

       			Pt c = o+Pt(r*cos(ang_a+md), r*sin(ang_a+md));

       			//cerr << "Trying " << c << endl;

       			Pt vt = rot(c-o);

       			ld aga = angle_2_vectors(a-c, -1*vt);
       			ld agb = angle_2_vectors(b-c, vt);

       			//cerr << aga << " " << agb << endl;

       			if(aga > agb) {
       				l = md;
       			}
       			else {
       				h = md;
       			}

       		}

       		Pt c = o+Pt(r*cos(ang_a+l), r*sin(ang_a+l));
       		//cerr << c << endl;

       		cout << dist(a, c)+dist(b, c) << "\n";
        }
    }
}
