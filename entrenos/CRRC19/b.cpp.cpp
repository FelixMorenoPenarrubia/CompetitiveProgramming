#include<bits/stdc++.h>

using namespace std;

typedef vector<int> vi;
typedef long long ll;

int gcd(int a, int b) {
	if(b == 0) return a;
	return gcd(b, a%b);
}

int main() {

	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int t1, t2;
	cin >> t1 >> t2;
	int t3 = 80;
	if(t1 == t3) {
		cout << 1 << " " << 0; 
		return 0;
	}
	int d = gcd(t3-t2, t1-t3);
	cout << (t3-t2)/d << " " << (t1-t3)/d << endl;
}