#include<bits/stdc++.h>


using namespace std;

typedef int ll;
typedef vector<ll> vi;
typedef pair<ll, ll> ii;
typedef vector<ii> vii;

string s, t;
bool process(vii& v, vii& next_v) {
    
   // cerr << "process" << endl;
    
    while(!v.empty()) {
        ii x = v.back();
        v.pop_back();
        int i = x.first;
        int j = x.second;
       // cerr << i << " " << j << endl;
        while(i > -1 and j > -1 and s[i] == t[j]) {
            --i;
            --j;
        }
        if(i == -1 and j == -1) {
            return true;
        }
        else if(i == -1) {
            next_v.push_back({-1, j-1});
        }
        else if(j == -1) {
            next_v.push_back({i-1, -1});
        }
        else {
            next_v.push_back({i-1, j-1});
            next_v.push_back({i, j-1});
            next_v.push_back({i-1, j});
        }
    }
    return false;
}

int main() {
    
    ios::sync_with_stdio(false);
    cin.tie(0);
    int T;
    cin >> T;
    while(T--) {
        cin >> s >> t;
        int n= s.length();
        int m=t.length();
        vii d0;
        vii d1;
        vii d2;
        vii d3;
        vii d4;
        d0.push_back({n-1, m-1});
        if(process(d0, d1)) {
            cout << "You're logged in!" << endl;
        }
        else if(process(d1, d2)) {
            cout << "You almost got it. You're wrong in just one spot." << endl;
        }
        else if(process(d2, d3)) {
            cout << "You almost got it, but you're wrong in two spots." << endl;
        }
        else if(process(d3, d4)) {
            cout << "You're wrong in three spots." << endl;
        }
        else {
            cout << "What you entered is too different from the real password." << endl;
        }
    }
}
