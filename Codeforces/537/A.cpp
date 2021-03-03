#include<bits/stdc++.h>

using namespace std;

typedef long long int ll;
typedef vector<ll> vi;
typedef vector<vi> vvi;
typedef pair<ll, ll> ii;
typedef vector<ii> vii;

bool isVowel(char x) {
	return (x == 'a' or x == 'e' or x == 'i' or x == 'o' or x == 'u');
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
	string s, t;
	cin >> s >> t;
	if(s.size() != t.size()) {
		cout << "No" << endl; 
	}
	else {
		for(int i=0; i < s.size(); ++i) {
			if((isVowel(s[i]) and isVowel(t[i])) or (!isVowel(s[i]) and !isVowel(t[i]))) {
				
			}
			else {
				cout << "No" << endl;
				return 0;
			}
		}
		cout << "Yes" << endl;
	}
	
}
