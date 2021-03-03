#include<bits/stdc++.h>

using namespace std;

typedef long long int ll;
typedef vector<ll> vi;
typedef vector<vi> vvi;
typedef pair<ll, ll> ii;
typedef vector<ii> vii;


int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t, w;
    cin >> t >> w;
    for(int ts=0; ts<t; ++ts) {
        cout << 200 << endl;
        ll r;
        cin >> r;
        r = r >> 33;
        ll r6 = r % 128;
        r = r >> 7;
        ll r5 = r % 128;
        r = r >> 10;
        ll r4 = r;
        cout << 50 << endl;
        cin >> r;
        r -= (1<<12)*r4+(1<<10)*r5+(1<<8)*r6;
        r = r >> 16;
        ll r3 = r % 128;
        r = r >> 9;
        ll r2 = r % 128;
        r = r >> 25;
        ll r1 = r;
        cout << r1 << " " << r2 << " " << r3 << " " << r4 << " " << r5 << " " << r6 << endl;
        ll ans;
        cin >> ans;
        if(ans == -1) return 0;
    }
}
