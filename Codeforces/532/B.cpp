#include<bits/stdc++.h>

using namespace std;

typedef long long int ll;
typedef vector<int> vi;


int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
	int n, m;
	cin >> n >> m;
	vi diffcount = vi(n, 0);
	vi probcount = vi(m, 0);
	for(int i=0; i < m; i++) {
		int a;
		cin >> a;
		a--;
		probcount[diffcount[a]]++;
		if(probcount[diffcount[a]] == n) {
			cout << 1;
		}
		else {
			cout << 0;
		}
		diffcount[a]++;
		
	}
	cout << endl;
}
