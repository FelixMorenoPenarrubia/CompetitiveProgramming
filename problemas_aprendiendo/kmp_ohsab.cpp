#include<bits/stdc++.h>

using namespace std;

typedef vector<int> vi;
typedef pair<int, int> ii;
typedef vector<ii> vii;

bool cmp(const string& a, const string& b) {
	return a.length() > b.length();
}

int main() {
	int n;
	cin >> n;
	vector<string> words(n);
	for(auto &x : words) cin >> x;
	sort(words.begin(), words.end(), cmp);

	int m;
	cin >> m;

	string dummy;
	getline(cin, dummy);

	for(int zzz=0; zzz < m; ++zzz) {
		string line;
		getline(cin, line);
		string s = "";
		for(int i=0; i < (int)line.length(); ++i) {
			if(line[i] != ' ' && line[i] != '/') s += line[i];
		}
		reverse(s.begin(), s.end());
		/*cerr << "DEBUG" << endl;
		cerr << line << endl;
		cerr << s << endl;
		cerr << "ENDDEBUG" << endl;*/

		
		vi foundwords(s.length(), -1);
		for(int l=0; l < n; ++l) {
			string t = words[l] + "#" + s;
			int len = t.length();
			vi kmp(len);
			for(int i=1; i < len; ++i) {
				int j = i-1;
				while(j >= 0 and t[kmp[j]] != t[i]) {
					j = kmp[j]-1;
				}
				if(j >= 0) kmp[i] = kmp[j]+1;
				else kmp[i] = 0;

				if(i > (int)words[l].length() && kmp[i] == (int)words[l].length() && foundwords[i-2*words[l].length()] == -1) {
					foundwords[i-2*words[l].length()] = l;
				}
			}
		}
		
		bool first = true;
		for(int i=0; i < (int)s.length(); ++i) {

			//cerr << "foundwords[" << i << "] = (" << foundwords[i].first << ", " << words[foundwords[i].second] << ")" << endl;
			int l = foundwords[i];
			if(l >= 0) {
				if(!first) cout << " ";
				cout << words[l];
				first = false;
				i = i+words[l].length()-1;
			}
		}
		if(first) cout << "-";
		cout << '\n';


	}
}