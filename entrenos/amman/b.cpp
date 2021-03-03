#include<bits/stdc++.h>

using namespace std;

int main() {
	int T;
	cin >> T;
	while(T--) {
		string a, b;
		cin >> a >> b;
		vector<int> cca(26);
		vector<int> ccb(26);
		for(int i=0; i < (int)a.length(); ++i) {
			cca[a[i]-'a']++;
		}
		for(int i=0; i < (int)b.length(); ++i) {
			ccb[b[i]-'a']++;
		}
		int ans = a.length();
		for(int i=0; i < (int)a.length(); ++i) {
			if(ccb[a[i]-'a'] > 0) {
				ccb[a[i]-'a']--;
			}
			else {
				ans = i;
				break;
			}
		}
		
		cout << ans << endl;
	}

}