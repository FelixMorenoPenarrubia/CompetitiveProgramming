#include <cstdio> 
#include <cmath> 
#include <cassert> 
#include <random>
#include <vector>
#include <algorithm>

using namespace std;

#define forn(i, n) for (int i = 0; i < (int)(n); i++)
#define err(...) fprintf(stderr, __VA_ARGS__), fflush(stderr)
#define sz(a) (int)(a).size()
#define all(a) (a).begin(), (a).end()
#define EOL " \n"[i == n - 1]

typedef long long ll;

mt19937 rnd(239);

int start;

void newTest() {
	//puts("end of flie");
	//fclose(stdout);
	char buf[20];
	sprintf(buf, "%03d", ++tn);
	assert(freopen(buf, "wt", stdout));
}

bool readTest() {
	int n, l, u;
	if (scanf("%d%d%d", &n, &l, &u) != 3)
		return 0;
	newTest();
	printf("%d %d %d\n", n, l, u);
	while (n--) {
		int x;
		scanf("%d", &x);
		printf("%d%c", x, " \n"[!n]);
	}
	return 1;
}

void random( int n, int l, int u, int w1, int w2 ) {
	newTest();
	printf("%d %d %d\n", n, l, u);
	uniform_int_distribution<int> gen_weight(w1, w2);
	forn(i, n)
		printf("%d%c", gen_weight(rnd), EOL);
}

void random_exp( int n, int l, int u, int w1, int w2, bool f = 0 ) {
	newTest();
	printf("%d %d %d\n", n, l, u);
	exponential_distribution<double> gen_weight(4);
	if (f)
		swap(w1, w2);
	forn(i, n)
		printf("%d%c", (int)round(w1 + min(gen_weight(rnd), 1.0) * (w2 - w1)), EOL);
}

void antiBruteforce1( int n, int maxW ) {
	newTest();
	//int x = k * k / 2 + k;
	//int u = k * x = k * k * k / 2;
	ll k = pow(maxW * 2.0, 1.0 / 3) - 1;
	ll x = k * k / 2 + k;
	ll u = x * k, l = u - k;
	//err("maxW=%d -> k=%d,x=%d,u=%d\n", maxW, (int)k, (int)x, (int)u);
	assert(u <= maxW);
	vector<int> a;
	forn(i, k) a.push_back(x);
	forn(i, k) a.push_back(x + i + 1);
	shuffle(all(a), rnd);
	printf("%d %d %d\n", n, (int)l, (int)u);
	forn(i, n)
		printf("%d%c", a[i % sz(a)], EOL);
}

void antiBruteforce2( int need = 0 ) {
	newTest();
	vector<int> a;
	for (int x = 950; x <= 1045; x++)
		forn(t, 9)
			a.push_back(x);
	a.push_back(1050);
	while ((int)a.size() < need) a.push_back(1000);
	shuffle(all(a), rnd);
	int n = a.size();
	printf("%d %d %d\n", n, 9400, 9500);
	forn(i, n)
		printf("%d%c", a[i], EOL);
}

void antiBruteforce3( int need = 0 ) {
	newTest();
	vector<int> a;
	for (int x = 960; x <= 1050; x++)
		forn(t, 9)
			a.push_back(x);
	a.push_back(959);
	while ((int)a.size() < need) a.push_back(1000);
	shuffle(all(a), rnd);
	int n = a.size();
	printf("%d %d %d\n", n, 9460, 9600);
	forn(i, n)
		printf("%d%c", a[i], EOL);
}

void genConstruction1( int n, int k, int w ) {
	// n k*w-1 k*w
	// w...w w+1...w+1
	newTest();
	assert(k < w - 3);
	printf("%d %d %d\n", n, k * w - 1, k * w);
	forn(i, n)
		printf("%d%c", w + (i >= n / 2), EOL);
}

void genConstruction2( int n, int k, int w ) {
	// n k*(w+1) k*(w+1)+1
	// w...w w+1...w+1
	newTest();
	assert(k < w - 3);
	printf("%d %d %d\n", n, k * (w + 1), k * (w + 1) + 1);
	forn(i, n)
		printf("%d%c", w + (i >= n / 2), EOL);
}

void genConstruction3( int n, int k, int w ) {
	// n k*w+k/2 k*w+k/2+1
	// w...w w+1...w+1
	newTest();
	assert(k < w - 3);
	printf("%d %d %d\n", n, k * w + k/2, k * w + k/2 + 1);
	forn(i, n)
		printf("%d%c", w + (i >= n / 2), EOL);
}

void antiGreedy3_1( int n, int k, int w ) {
	// 100 86 93
	// 15 15 20 20 20 20 20 20 20 20 
	// ...
	// 21 21 21 21 21 21 21 21 21 21
	newTest();

	int l = (k + 0.5) * w + 1e-9;
	assert(k < w * 0.5 - 4);
	printf("%d %d %d\n", n, l - 3 - 1, l + 3);

	int m = (n / 10) * 5;
	forn(i, n)
		printf("%d%c", w - (i < m / 5) * 5 + (i > n - m), EOL);
}

void antiGreedy3_2( int n, int k, int w ) {
	// 100 87 94
	// 19 19 19 19 19 19 19 19 19 19 
	// ...
	// 20 20 20 20 20 20 20 20 25 25
	newTest();
	
	int l = (k + 0.5) * w + 1e-9;
	assert(k < w * 0.5 - 4);
	printf("%d %d %d\n", n, l - 3, l + 3 + 1);

	int m = (n / 10) * 5;
	forn(i, n)
		printf("%d%c", w + (i > n - m / 5) * 5 - (i < n - m), EOL);
}

void readFromString( const char *tmp ) {
	#define TMP_FILE "tmp.tmp"
	FILE *F = fopen(TMP_FILE, "wt");
	fprintf(F, "%s", tmp);
	fclose(F);
	assert(freopen(TMP_FILE, "rt", stdin));
	while (readTest())
		;
}

void readAll( const char *fname ) {
	if (freopen(fname, "rt", stdin))
		while (readTest())
			;
}

void finish() {
	static int cc = 0;
	err("group #%d : %3d tests, [%3d, %3d]\n", ++cc, tn - start + 1, start, tn);
	start = tn + 1;
}

/** GROUPS */

void genGroup1() {
	random(100, 971,971, 83,83);
	random(100, 63,63, 1,1);
	finish();
}

void genGroup2() {
	random(100, 150,150, 1,1);
	random(100, 50,51 , 1,2);
	random(100, 500,501 , 1,2);
	random(100, 999,1000 , 99,100);
	genConstruction1(100, 25, 35);
	genConstruction2(100, 25, 35);
	genConstruction3(100, 25, 35);
	finish();
}

void genGroup3() {
	random(10,  100,110,  10,20);
	random(100, 990,1000, 10,20);
	random(100, 990,1000, 80,85);
	random(100, 990,1000, 88,90);
	random(100, 990,1000, 90,92);
	random(100, 990,1000, 5,12);
	random(100, 900,990,  991,1000);
	random(100, 750,990,  500,740);
	random_exp(100, 990,1000, 10,20, 0);
	random_exp(100, 990,1000, 10,20, 1);
	antiBruteforce1(100, 1000);
	antiGreedy3_1(100, 4, 20);
	antiGreedy3_2(100, 4, 20);
	finish();
}

void genGroup4() {
	int n = 1e4, w = 1e4;
	random(8000, w,w, 1,1);
	random(n, w-10,w, 10,20);
	random(n, w-10,w, 100,110);
	random(n, w-10,w, 1000,1010);
	random(n, w-10,w, 995,1005);
	random(n, w-100,w, 1,100);
	random(n, 5000,5010, 1000,1010);
	random(n, 5000,5010, 1010,1020);
	random(n, 5000,w, 1,5000);
	random(n, 1,w/2, w/2+10,w);
	random_exp(n, w-100,w, 100,200, 0);
	random_exp(n, w-100,w, 100,200, 1);
	antiBruteforce1(n, n);
	antiGreedy3_1(n, 15, 40);
	antiGreedy3_2(n, 15, 40);
	genConstruction1(n, 70, 100);
	genConstruction2(n, 70, 100);
	genConstruction3(n, 70, 100);
	antiBruteforce2();
	antiBruteforce3();
	finish();
}

void genGroup5() {
	int n = 1e4, w = 5e5;
	int W = 1e5, n1 = n / 4;
	random(n1 * 3, W-n,W, W/n-1, W/n);
	random(n, w-10,w, 10,20);
	random(n, w-15,w, 5,15);
	random(n, w-37,w, 5,40);
	random(n, w-78,w, 5,80);
	random(n, w-10,w, 100,110);
	random(n, w-10,w, 1000,1010);
	random(n, w-10,w, 995,1005);
	random(n, w-10,w, w/2-10,w/2);
	random(n, w-10,w, w/2+1,w/2+11);
	random(n, w-2000,w, 1,2000);
	random(n, 1,w/2, w/2+10,w);
	random_exp(n, w-100,w, 100,200, 0);
	random_exp(n, w-100,w, 100,200, 1);
	antiBruteforce1(1e4, 3e5);
	antiGreedy3_1(n, 150, 1000);
	antiGreedy3_2(n, 150, 1000);
	int k = sqrt(w);
	genConstruction1(n, k / 3, k);
	genConstruction2(n, k / 3, k);
	genConstruction3(n, k / 3, k);
	finish();
}

void genGroup6() {
	int n = 2e5, w = INT_MAX;
	int W = 2e9, n1 = n / 4;
	random(n1 * 3, W-n,W, W/n-1, W/n);
	random(n, w-1000,w, 1e6,1e6+1000);
	random(n, w-1000,w, 1e9,1e9+1000);
	random(n, w-1000,w, 1e5,1e5+1000);
	random(n, 1, w, 1, w);
	random(n, 1e9-10,1e9+10, 1e6,1e6+10);
	random(n, 1e9-10,1e9+10, 1e6-10,1e6);
	random(n, w-1000,w, 1,1000);
	random(n, w-(1<<16),w, (1<<16),(1<<17)-1);
	random(n, 1,w/2, w/2+10,w);
	random_exp(n, w-100,w, 100,200, 0);
	random_exp(n, w-100,w, 100,200, 1);
	antiBruteforce1(2e5, 1e6);
	antiGreedy3_1(n, 1500, 10000);
	antiGreedy3_2(n, 1500, 10000);
	int k = sqrt(w);
	genConstruction1(n, k / 3, k);
	genConstruction2(n, k / 3, k);
	genConstruction3(n, k / 3, k);
	antiBruteforce2(200000);
	antiBruteforce3(200000);
	finish();
}


/**
const int N[] = {MAX_N, 100,   100,   100,   10000, int(1e4), MAX_N};
const int W[] = {MAX_C, 100,   1000,  1000,  10000, int(5e5), MAX_C};
const int D[] = {MAX_C, 0,     1,     MAX_C, MAX_C, MAX_C,    MAX_C};
const int U[] = {MAX_C, 1000,  1000,  1000,  10000, int(5e5), MAX_C};
 */
 
