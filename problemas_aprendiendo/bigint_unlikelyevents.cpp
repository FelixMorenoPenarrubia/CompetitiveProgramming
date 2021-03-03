#include<bits/stdc++.h>

using namespace std;

typedef long double ld;
typedef long long ll;
typedef vector<ll> vi;

struct rational {
	int ptwo;
	int pthree;
	int pfive;
	ld logvalue;
};

rational operator *(rational a, rational b) {
	rational r;
	r.ptwo = a.ptwo+b.ptwo;
	r.pthree = a.pthree+b.pthree;
	r.pfive = a.pfive+b.pfive;
	r.logvalue = a.logvalue+b.logvalue;
	return r;
}

bool operator <(rational a, rational b) {
	return a.logvalue < b.logvalue;
}

const ll base = 10;

struct biginteger {
	vi digits;
};

biginteger operator * (biginteger a, ll b) {
	ll carry = 0;
	biginteger r;
	int n = a.digits.size();
	r.digits = vi(n, 0);
	for(int i=0; i < n; ++i) {
		r.digits[i] = a.digits[i]*b+carry;
		carry = r.digits[i]/base;
		r.digits[i] %= base;
	}
	if(carry > 0) {
		r.digits.push_back(carry);
	}
	return r;
}

void print_integer(biginteger a) {
	int n = a.digits.size();
	for(int i=n-1; i > -1; --i) {
		cout << a.digits[i];
	}
}


int main() {
	int n;
	while(cin >> n) {

		vector<rational> v (n);
		for(int i=0; i < n; ++i) {
			int num, den;
			string str;
			cin >> str;
			num = str[0]-'0';
			den = str[2]-'0';

			if(num == 2) {
				v[i].ptwo += 1;
			}
			if(num == 3) {
				v[i].pthree += 1;
			}
			if(num == 4) {
				v[i].ptwo += 2;
			}
			if(num == 5) {
				v[i].pfive += 1;
			}
			if(num == 6) {
				v[i].ptwo += 1;
				v[i].pthree += 1;
			}


			if(den == 2) {
				v[i].ptwo -= 1;
			}
			if(den == 3) {
				v[i].pthree -= 1;
			}
			if(den == 4) {
				v[i].ptwo -= 2;
			}
			if(den == 5) {
				v[i].pfive -= 1;
			}
			if(den == 6) {
				v[i].ptwo -= 1;
				v[i].pthree -= 1;
			}

			v[i].logvalue = log(ld(num)/ld(den));
		}

		vector<rational> dp (n);
		dp[0] = v[0];
		if(n > 1) dp[1] = min(v[0], v[1]);

		for(int i=2; i < n; ++i) {
			dp[i] = min(dp[i-1], dp[i-2]*v[i]);
		}

	//	cerr << dp[n-1].ptwo << " " << dp[n-1].pthree << " " << dp[n-1].pfive << endl;

		biginteger num;
		num.digits.push_back(1);
		biginteger den;
		den.digits.push_back(1);

		for(int i=0; i < dp[n-1].ptwo; ++i) num = num * 2;
		for(int i=0; i < dp[n-1].pthree; ++i) num = num * 3;
		for(int i=0; i < dp[n-1].pfive; ++i) num = num * 5;
		for(int i=0; i > dp[n-1].ptwo; --i) den = den * 2;
		for(int i=0; i > dp[n-1].pthree; --i) den = den * 3;
		for(int i=0; i > dp[n-1].pfive; --i) den = den * 5;

		print_integer(num);
		cout << "/";
		print_integer(den);
		cout << endl;
	}
}