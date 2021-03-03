#include<bits/stdc++.h>

using namespace std;

typedef long long int ll;



int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
	string s;
	cin >> s;
	int i=1;
	int j=0;
	int cnt = 0;
	int mini = -1;
	
	while(i < s.size()) {
		j = i-1;
		bool used = false;
		while(j > mini and i < s.length() and s[i] == s[j]) {
			cnt++;
			j--;
			i++;
			used = true;
			
		}
		if(used) mini = i-1;
		
		i++;
	}
	//cerr << cnt << endl;
	cout << ((cnt%2) == 0 ? "No" : "Yes" )<< endl;
}
