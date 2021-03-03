#include<bits/stdc++.h>

using namespace std;

typedef long long int ll;

ofstream fout ("out.txt");

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    string s = "b";
	for(int i=2; i < 10000; i++) {
		s += 'a'+(i%3);
	}
	for(int i = 10001;i < 100000; i++) {
		s += 'a';
	} 
	
	fout << s << endl;
}
