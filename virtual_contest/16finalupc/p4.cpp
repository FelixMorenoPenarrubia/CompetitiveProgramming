#include<bits/stdc++.h>

using namespace std;

typedef long long int ll;
typedef vector<ll> vi;
typedef vector<vi> vvi;
typedef pair<ll, ll> ii;
typedef vector<ii> vii;

#define X first
#define Y second



int main() {
    string s, t;
    while(cin >> s >> t) {
        int n = s.length();
        int m = t.length();
        int j = 0;
        bool alter = false;
        for(int i=0; i < m; ++i) {
            if(j < n and s[j] == t[i]) {
                ++j;
            }
            else if(j > 0 and s[j-1] == t[i]) {
                alter = true;
            }
        }
        if(j < n) cout << "zero" << endl;
        else if(alter) cout << "multiple" << endl;
        else cout << "one" << endl;
    }
}
