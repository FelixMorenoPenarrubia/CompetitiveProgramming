#include<bits/stdc++.h>

using namespace std;

typedef long double ld;

const ld EPS = 1e-10;

struct point {
	ld x;
	ld y;
	point() {

	}
	point(ld _x, ld _y) {
		x = _x;
		y = _y;
	}
};

ld norm(point x) {
	return sqrt(x.x*x.x+x.y*x.y);
}

point operator-(point a, point b) {
	return point(a.x-b.x, a.y-b.y);
}
ld dist(point a, point b) {
	return norm(a-b);
	//return sqrt((a.x-b.x)*(a.x-b.x) + (a.y-b.y)*(a.y-b.y));
}
point unit(point a) {
	return point(a.x/norm(a), a.y/norm(a));
}
point perp(point a) {
	return point(-a.y, a.x);
}
ld dot(point a, point b) {
	return a.x*b.x+a.y*b.y;
}
ld cross(point a, point b) {
	return a.x*b.y-a.y*b.x;
}

int main() {
	cout.setf(ios::fixed);
	cout << setprecision(9);
	point a, b, c, d;
	cin >> a.x >> a.y >> b.x >> b.y >> c.x >> c.y >> d.x >> d.y;
	if(dist(a, b) < dist(c, d)) {
		swap(a, c);
		swap(b, d);
	}
	if(dist(a, b) < EPS) {
		cout << dist(a, c) << endl;
		return 0;
	}
	point v1 = unit(b-a);
	ld t1 = norm(b-a);
	point v2 = unit(d-c);
	ld t2 = norm(d-c);
	
	point pb = c-a;
	point vb = v2-v1;
	point pe = point(pb.x+vb.x*t2, pb.y+vb.y*t2);

	ld ans1;
	point n = perp(pe-pb);
	if(t2 > EPS) {
		if(norm(n) < EPS) {
			ans1 = norm(pe);
		}
		else {
			if(cross(pb, n)*cross(pe, n) <= 0) {
				ld co = -n.x*pb.x-n.y*pb.y;
				ans1 = abs(co)/norm(n);
			}
			else {
				ans1 = min(norm(pb), norm(pe));
			}
		}
	}
	else {
		
		pe = pb;
		ans1 = norm(pb);
	}
	//cerr << ans1 << endl;


	vb = point(-v1.x, -v1.y);



	pb = point(pe.x + vb.x*(t1-t2), pe.y+vb.y*(t1-t2));

	/*cerr << vb.x << " " << vb.y << endl;

	cerr << t1 << " " << t2 << endl;

	cerr << pe.x << " " << pe.y << endl;
	cerr << pb.x << " "  << pb.y << endl;*/

	ld ans2;
	n = perp(pe-pb);

//	cerr << "n " << n.x << " " << n.y << endl;

	if(norm(n) < EPS) {
		ans2 = norm(pe);
	}
	else {
		if(cross(pb, n)*cross(pe, n) <= 0) {
			ld co = -n.x*pb.x-n.y*pb.y;

			//cerr << "co" <<  co << endl;
			ans2 = abs(co)/norm(n);
		}
		else {
			ans2 = min(norm(pb), norm(pe));
		}
	}
//	cerr << ans2 << endl;

	cout << min(ans1, ans2) << endl;






}