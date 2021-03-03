#include<bits/stdc++.h>

using namespace std;

typedef long long int ll;



int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
	string s;
	cin >> s;
	int i = 1;
	int cnt = 0;
	while(i < s.size()) {
		if(s[i] == s[i-1]) {
			s = s.substr(0,i-1)+s.substr(i+1);
			i-=2;
			cnt++;
		}
		i++;
	}
	cout << ((cnt%2) == 0 ? "No" : "Yes" )<< endl;
}
