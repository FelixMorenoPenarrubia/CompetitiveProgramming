#include<bits/stdc++.h>

using namespace std;

typedef long double ld;

const ld pi = 2*acos(0);

int main() {

	ld n, m;
	cin >> n >> m;

	ld k = floor(2*m/pi);

	ld ans = 0.0;

	if(m > 1) ans += 2*m*((n*(n+1))/2);


	for(int i=1; i <= n; ++i) {

		//Intralevel
		ans += i*pi * (k*(k+1));

		ans += m*2*i*(2*m-2*k-1);

		//Interlevel

		ans += 2*m*m*((n-i)*(n-i+1));

		ans += i*pi*(k*(k+1))*2*(n-i);

		ans += 2*m*2*i*(2*m-2*k-1)*(n-i);



	}





	cout.setf(ios::fixed);
	cout << setprecision(10);
	cout << ans << endl;



}