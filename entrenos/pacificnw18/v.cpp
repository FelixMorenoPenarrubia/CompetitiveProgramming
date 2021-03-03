#include<bits/stdc++.h>

using namespace std;

#define int ll

typedef long long ll;
typedef vector<ll> vi;
typedef vector<vi> vvi;
typedef pair<vector<pair<int, string> >, vi> repr;


struct com {
	int type;
	int del;
	int pos;
	int rpos;
	int slen = 1;
	//list<char> s;
	string s;
};

repr read_repr() {
	//cerr << "ini lec" << endl;


	char c;
	cin >> c;
	vector<com> vc;
	while(c != 'E') {
		com a;
		if(c == 'D') {
			a.type = 0;
			a.del = 0;
			cin >> a.pos;
		}
		else {
			a.type = 1;
			a.del = 0;
			cin >> a.pos >> a.s;
		}
		vc.push_back(a);
		cin >> c;
	}
	vector<pair<int, string> > insertions;
	vi deletions;

	int n = vc.size();
	/*for(int i=0; i < n; ++i) {
		if(vc[i].type == 0) {
			int pos = vc[i].pos;
			for(int j=i-1; j > -1; --j) {
				if(vc[j].del) continue;
				if(vc[j].type == 1) {
					if(pos == vc[j].pos) {
						vc[j].del = 1;
						vc[i].del = 1;
						break;
					}
					else if(pos > vc[j].pos) {
						pos--;
					}
				}
				else {
					if(pos >= vc[j].pos) {
						pos++;
					}
				}
			}
		}
	}*/
	for(int i=0; i < n; ++i) {
		if(vc[i].del) continue;
		int pos = vc[i].pos;
		for(int j=i-1; j > -1; --j) {
			if(vc[j].del) continue;
			if(vc[i].type == 1) {
				if(vc[j].type == 1) {
					if(pos == vc[j].pos) {
						//LINKED LIST

						vc[j].s = vc[i].s+vc[j].s;
						vc[j].slen = vc[i].slen+vc[j].slen;
						vc[i].del = 1;
						break;
					}
					else if(pos == vc[j].pos+1) {

						//LINKED LIST
						vc[j].s = vc[j].s+vc[i].s;
						vc[j].slen = vc[i].slen+vc[j].slen;
						vc[i].del = 1;
						break;
					}
					else if(pos > vc[j].pos) {
						pos--;
					}
				}
				else {
					if(pos >= vc[j].pos) {
						pos++;
					}
				}
			}
			else {
				if(vc[j].type == 1) {
					if(pos == vc[j].pos) {
						if(vc[i].slen == 1) {
							vc[j].del = 1;
						}
						else {
							vc[j].s = vc[j].s.substr(1);
							vc[j].slen--;
						}
						vc[i].del = 1;
						break;
					}
					else if(pos > vc[j].pos) {
						pos--;
					}
				}
				else {
					if(pos >= vc[j].pos) {
						pos++;
					}
				}
			}
		}
		
		vc[i].rpos = pos;
	}
	for(int i=0; i < n; ++i) {
		if(vc[i].del) continue;
		if(vc[i].type == 1) {
			insertions.emplace_back(vc[i].rpos, vc[i].s);
		}
		else {

			//cerr << "i = " << i << " pos = " << pos << endl;
			deletions.push_back(vc[i].rpos);
		}
	}
	sort(insertions.begin(), insertions.end());

	sort(deletions.begin(), deletions.end());


	for(int i=0; i+1 < (int)insertions.size(); ++i) {
		int j = i;
		while(j+1 < (int)insertions.size() || insertions[i].first == insertions[j+1].first) {
			j++;
		}
		for(int k=i+1; k <= j; ++k) {
			insertions[i].second += insertions[k].second;
			
		}
		for(int k=i+1; k <= j; ++k) {
			insertions.delete(i+1);
		}
	}


	return make_pair(insertions, deletions);
}

void print(const repr& a) {
	vector<pair<int, string> > ins = a.first;
	vi del = a.second;
	cerr << "ins: " << endl;
	for(auto x : ins) {
		cerr << x.first << x.second << endl;
	}
	cerr << "dels: " << endl;
	for(auto x : del) {
		cerr << x << endl;
	}
}

signed main() {
	repr a = read_repr();
	repr b = read_repr();

	/*
	cerr << "a: " << endl;
	print(a);
	cerr << "b: " << endl;
	print(b);
	*/
	

	cout << int((a != b)) << endl;
	
}