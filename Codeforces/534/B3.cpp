#include<bits/stdc++.h>

using namespace std;

typedef long long int ll;
typedef vector<int> vi;

vi fcnu;

int firstcharnotused(int i) {
	if(i < 0) return -1;
	if(fcnu[i] == i) return i;
	fcnu[i] = firstcharnotused(fcnu[i]);
	return fcnu[i];
	
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
	string s;
	cin >> s;
	for(int i=0; i < s.size(); i++) {
		fcnu.push_back(i);
	}
	int i = 1;
	int cnt = 0;
	while(i < s.size()) {
		int j = firstcharnotused(i-1);
		
		while(j > -1 and i < s.length() and s[i] == s[j]) {
			cnt++;
			fcnu[j] = firstcharnotused(j-1);
			fcnu[i] = firstcharnotused(i-1);
			j = fcnu[j];
			i++;
			
			
		}
		
		
		i++;
	}
	cout << ((cnt%2) == 0 ? "No" : "Yes" )<< endl;
}
