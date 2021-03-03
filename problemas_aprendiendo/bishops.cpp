#include<bits/stdc++.h>

using namespace std;

typedef vector<int> vi;
typedef vector<vi> vvi;


int n;

void solve_board(vvi& board, int d) {
	vi diags (2*n-1, 0);
	vi cdiags (2*n-1, 0);
	for(int i=0; i < n; ++i) {
		for(int j=0; j < n; ++j) {
			if(board[i][j] == 1) {
				diags[j-i+n-1] = 1;
				cdiags[i+j] = 1;
			}
		}
	}

	for(int sum=d; sum < 2*n-1; sum += 2) {
		if(cdiags[sum]) continue;
		for(int ctr=0; ctr < min(sum+1, 2*n-1-sum); ++ctr) {
			int i, j;
			if(ctr%2) {
				if(sum < n) {
					i = sum-ctr/2;
				}
				else {
					i = (n-1)-ctr/2;
				}
			}
			else {
				if(sum < n) {
					i = ctr/2;
				}
				else {
					i = ctr/2+sum-(n-1);
				}
			}
			j = sum-i;

			//cerr << "(i, j) = (" << i << ", " << j << ")" << endl;

			if(!diags[j-i+n-1] and !cdiags[i+j]) {

				board[i][j] = 2;
				diags[j-i+n-1] = 1;
				cdiags[i+j] = 1;
			}
		}	
	}


}


int main() {
	
	while(cin >> n) {
		vvi board = vvi(n, vi(n, 0));
		for(int i=0; i < n; ++i) {
			string s;
			cin >> s;
			for(int j=0; j < n; ++j) {
				if(s[j] == 'B') board[i][j] = 1;
			}
		}
		solve_board(board, 0);
		solve_board(board, 1);
		for(int i=0; i < n; ++i) {
			string s = string( n, '-');
			for(int j=0; j < n; ++j) {
				if(board[i][j] == 0) s[j] = '.';
				else if(board[i][j] == 1) s[j] = 'B';
				else s[j] = 'W';
			}
			cout << s << endl;
		}
		cout << string(20, '-') << endl;
	}
}