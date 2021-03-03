#include<bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef vector<vi> vvi;

int main() {
	string s;
	cin >> s;
	int n = s.length();
	int ai = 0;
	int aj = 0;
	int aa = -2;
	int cv = 0;
	int ci = 0;
	for(int i=0; i < n; ++i) {
		if(s[i] == 'R') {
			cv++;
		}
		else cv--;
		if(cv > aa) {
			aa = cv;
			ai = ci;
			aj = i;
		}
		if(cv < 0) {
			ci = i+1;
			cv = 0;
		}
	}
	int bi = 0;
	int bj = 0;
	int ba = -2;
	cv = 0;
	ci = 0;
	for(int i=0; i < n; ++i) {
		if(s[i] == 'B') {
			cv++;
		}
		else cv--;
		if(cv > ba) {
			ba = cv;
			bi = ci;
			bj = i;
		}
		if(cv < 0) {
			ci = i+1;
			cv = 0;
		}
	}
	if(aa > ba) cout << ai+1 << " " << aj+1 << endl;
	else if(aa == ba) {
		if(ai < bi) {
			cout << ai+1 << " " << aj+1 << endl;
		}
		else if(ai == bi) {
			if(aj < bj) cout << ai+1 << " " << aj+1 << endl;
			else cout << bi+1 << " " << bj+1 << endl;
		}
		else {
			cout << bi+1 << " " << bj+1 << endl;
		}
	}
	else cout << bi+1 << " " << bj+1 << endl;
	
}