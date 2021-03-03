#include<bits/stdc++.h>

using namespace std;

typedef long long int ll;
typedef vector<ll> vi;
typedef vector<vi> vvi;
typedef pair<ll, ll> ii;
typedef vector<ii> vii;
typedef vector<bool> vb;
typedef vector<vb> vvb;




ll gcd(ll a, ll b) {
    if(b == 0) return a;
    return gcd(b, a%b);
}
ll powm(ll a, ll b, ll m) {
    if(b == 0) return 1;
    ll sq = powm(a, b/2, m);
    return (b&1) ? (((sq*sq)%m)*a)%m : (sq*sq)%m;
}

ll _x;
ll _y;

void extea(ll a, ll b) {
  //  cerr << "extea(" << a << ", " << b << ") begin" << endl;
    /*if(b > a) {
        extea(b, a);
        swap(_x, _y);
    }*/
    if(b == 0) {
        _x = 1;
        _y = 0;
    }
    else {
        extea(b, (a-(a/b)*b));
        ll _nx = _y;
        _y = _x-(a/b)*_y;
        _x = _nx;
    }
  /*  cerr << "extea(" << a << ", " << b << ") end" << endl;
    cerr << "_x = " << _x << " _y = " << _y << endl;*/
}

ll inv(ll a, ll m) {
    a %= m;
    extea(a, m);
    _x += m;
    _x %= m;
    if((a*_x)%m != 1)  {
        //cerr << "BAD EXTEA ERROR ARGH" << endl;
      /* volatile bool fl = true;
       while(fl) {
           
       }*/
      vector<ll> v = vector<ll>(1e9, 0);
    }
    return _x;
}
ll sqroot(ll n) {
    ll l = 0;
    ll r = n+1;
    while(r-l > 1) {
        ll d = (l+r)/2;
        if(d*d > n) {
            r = d;
        }
        else l = d;
    }
    return l;
}


ll solve(ll a, ll b, ll m) {
    ll n = (int) sqrt (m + .0) + 1;

    ll an = 1;
    for (ll i = 0; i < n; ++i)
        an = (an * a) % m;

    unordered_map<ll, ll> vals;
    for (ll p = 1, cur = an; p <= n; ++p) {
        if (!vals.count(cur))
            vals[cur] = p;
        cur = (cur * an) % m;
    }

    for (ll q = 0, cur = b; q <= n; ++q) {
        if (vals.count(cur)) {
            ll ans = vals[cur] * n - q;
            return ans;
        }
        cur = (cur * a) % m;
    }
    return -1;
}

void caso(ll n, ll a, ll b) {
    /*if(solve(a, b, n) == -1) {
        cout << "NO" << endl;
    }
    else {
        cout << "YES" << endl;
    }*/
    
    ll k = sqroot(n);
    unordered_set<ll> pval;
    ll ca = powm(a, k, n);
    ll am = ca;
    for(ll i=1; i <= n/k+1; ++i) {
        
        pval.insert(ca);
        ca *= am;
        ca %= n;
    }
    ca = b;
    am = a;
    for(ll i=0; i <= k; ++i) {
        ll v = (ca);
        if(pval.find(v) != pval.end()) {
            cout << "YES" << endl;
            return;
        }
        ca *= am;
        ca %= n;
    }
    cout << "NO" << endl;
    
}


int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int c;
    cin >> c;
    for(int t=0; t < c; ++t) {
        ll n, a, b;
        cin >> n >> a >> b;
         if(b == 1) { 
             cout << "YES" << endl;
             continue;
         }
         else if(a == 0) {
            cout << ((b == 0) ? "YES" : "NO") << endl;
            continue;
         }
        ll d = gcd(a, n);
        
      //  cerr << "initial d = " << d << endl;
        
        while(d != 1 and b%d == 0) {
            //a /= d;
            b /= d;
            n /= d;
            b *= inv(a/d, n);
           // a *= d;
            d = gcd(a, n);
            a %= n;
            b %= n;
            
          //  cerr << d << endl;
        }
        if(b == 1) cout << "YES" << endl;
        else if(d == 1) caso(n, a, b);
        else cout << "NO" << endl;
    }
}
