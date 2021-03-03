#include<bits/stdc++.h>

using namespace std;

typedef long long int ll;



int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    string s;
    cin >> s;
    int vcount = 0;
    int hcount = 0;
    for(int i=0; i < s.size(); i++) {
		if(s[i] == '0') {
			cout << "1 " << (vcount%4)+1 << endl;
			vcount++;
		}
		else {
			cout << "3 " << (hcount%2)*2+1 << endl;
			hcount++;
		}
	}

}
