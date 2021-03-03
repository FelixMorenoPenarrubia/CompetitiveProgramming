#include<bits/stdc++.h>

using namespace std;

typedef long long ll;



void caso(string t, int r, int p, int s) {
    int n = t.length();
    vector<int> sb = vector<int>(n+1, 0);
    for(int i=1; i <= n; ++i) {
        if(t[n-i] == 'R') sb[i] = sb[i-1];
        else if(t[n-i] == 'S') sb[i] = sb[i-1]+1;
        else sb[i] = sb[i-1]+2;
    }
    int crp = 0;
    for(int i=0; i < r; ++i) {
        if(t[i] == 'R') ++crp;
        else if(t[i] == 'S') crp+=2;
    }
    int sol = 0;
    for(int i=r; i <= n-(p+s); ++i) {
        int cpp = 0;
        for(int j=0; j < p; ++j) {
            if(t[i+j] == 'P') ++cpp;
            else if(t[i+j] == 'R') cpp+=2;
        }
        for(int j=p; i+j <= n-s; ++j) {
            sol = max(sol, crp+cpp+sb[n-i-j]);
            if(t[i+j] == 'P') ++cpp;
            else if(t[i+j] == 'R') cpp+=2;
        }
        if(t[i] == 'R') ++crp;
        else if(t[i] == 'S') crp+=2;
    }
    cout << sol << endl;
}

int main() {
    string t;
    int r, p, s;
    while(cin >> t >> r >> p >> s) caso(t, r, p, s);
}
