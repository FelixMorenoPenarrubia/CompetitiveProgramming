/** Author: Sergey Kopeliovich (Burunduk30@gmail.com) */

#ifdef BURUNDUK
#	include "my_testlib.h"
#else
#	include "testlib.h"
#endif

#include <vector>

#define forn(i, n) for (int i = 0; i < (int)(n); i++)

typedef long long ll;
										
int n, l, u;
std::vector<int> w;

void readInput( InStream &in ) {
	n = in.readInt();
	l = in.readInt();
	u = in.readInt();
	w.resize(n);
	forn(i, n)
		w[i] = in.readInt();
}

bool checkOutput( InStream &out ) {
    quitif(out.readLine() != "14e047d7a2907b9034950b074822b302", _sv, "Secret is incorrect!");
	int a = out.readInt(0, n);
	if (a == 0)
		return 0;
	if (a < 0)
	    out.quitf(_wa, "answer has negative length");
	std::vector<bool> marked(n);
	ll sum = 0;
	while (a--) {
		int x = out.readInt(0, n - 1);
		if (marked[x])
			out.quitf(_wa, "item #%d is taken twice", x);
		marked[x] = 1;
		sum += w[x];
	}
	if (!(l <= sum && sum <= u))
		out.quitf(_wa, "sum of weights should be in [%d..%d] but it is %lld", l, u, sum);
	return 1;
}

int main(int argc, char *argv[]) {
	registerTestlibCmd(argc, argv);

	readInput(inf);

	bool ja = checkOutput(ans);
	bool ca = checkOutput(ouf);

	if (ca && !ja) quitf(_fail, "Contestant can find answer, jury can not");
	if (!ca && ja) quitf(_wa,   "Contestant can not find answer, jury can");
	if (!ouf.seekEof())
		quitf(_sv, "contestant outputs some trash to stdout");
	quitf(_ok, "OK (n = %d, answer = %s)", n, ca ? "YES" : "NO");
}
