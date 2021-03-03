#include<bits/stdc++.h>
#define X first
#define Y second

using namespace std;

typedef long long ll;
typedef vector<ll> vi;
typedef vector<vi> vvi;
typedef pair<ll, ll> ii;
typedef vector<ii> vii;
typedef vector<vii> vvii;

ll gcd(ll a, ll b) {
    if(b == 0) return a;
    return gcd(b, a%b);
}

int solve(const map<ll, ll>& mp) {
    ll chained = 0;
    ll isolated = 0;
    for(auto it=mp.begin(); it != mp.end(); ++it) {
        if(it->second > 1) {
            chained += it->second;
        }
        else if(it->second == 1) {
            isolated += it->second;
        }
    }
    if(isolated >= 2) {
        if(chained%2) return chained+1;
        return chained+2;
    }
    else if(isolated == 1) {
        return chained+1;
    }
    else {
        return chained;
        
    }
}


int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int T;
    cin >> T;
    for(int t=0; t < T; ++t) {
        int n;
        cin >> n;
        vii p(n);
        for(int i=0; i < n; ++i) {
            cin >> p[i].X >> p[i].Y;
        }
        set<ii> directions;
        for(int i=0; i < n; ++i) {
            for(int j=0; j < n; ++j) {
                if(i == j) continue;
                ll dx = p[i].X-p[j].X;
                ll dy = p[i].Y-p[j].Y;
                directions.emplace(dx/gcd(dx, dy), dy/gcd(dx, dy));
                
            }
        }
        int ans = 1;
        for(auto it=directions.begin(); it != directions.end(); ++it) {
            ii dir = *it;
            map<ll, ll> mp;
            ll dx = dir.X;
            ll dy = dir.Y;
            for(int i=0; i < n; ++i) {
                mp[p[i].X*dy-p[i].Y*dx]++;
            }
            ans = max(ans, solve(mp));
            
        }
        cout << "Case #" << t+1 << ": " << ans << endl;
        
    }
}
