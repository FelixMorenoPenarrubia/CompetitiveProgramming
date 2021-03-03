#include<bits/stdc++.h>

using namespace std;


typedef vector<int> vi;

string s;
int n;
int m;
vi op;
string paren;

void baq(int idx, int cur) {
	if(idx ==  n) {
		if(cur == 0) cout << paren << endl;
		return;
	}
	if(n-idx-cur > 0) {
	
		for(int i=0; i < m; ++i) {
			
			paren[idx] = s[2*i];
			op[cur] = i;
			baq(idx+1, cur+1);
			
		}

	}
	if(cur > 0) {
		paren[idx] = s[2*op[cur-1]+1];
		baq(idx+1, cur-1);
	}

}


int main() {
	cin >> s >> n;
	m = s.length()/2;
	op = vi(n, 0);
	paren = string(n, '-');
	baq(0, 0);

}