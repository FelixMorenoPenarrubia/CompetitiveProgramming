#include<bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<ll, ld> ii;
typedef vector<ld> vi;
typedef vector<ii> vii;
vii p;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n;
    cin >> n;
    
    cout.setf(ios::fixed);
    cout.precision(1);
    if(n < 3) {
        cout << 0.0 << endl;
        return 0;
    }
    ld low = 0;
    ld upp = 0;
    for(int i=0; i < n; ++i) {
        long long int v, l;
        cin >> v >> l;
        upp = max(upp, ld(l));
        p.push_back(ii(v, ld(l)));
    }
    sort(p.begin(), p.end());
    vi gd = vi(n);
    vi pd = vi(n);
    ld mx = p[n-1].second;
    ld mn = p[n-1].second;
    for(int i=n-1; i > -1; i--) {
        gd[i] = mx;
        pd[i] = mn;
        if(i > 0) {
            mx = max(mx, p[i-1].second);
            mn = min(mn, p[i-1].second);
        }
    }
    if(p[0].first == 0) low = p[0].second;
    while (upp-low > 0.001) {
        ld x = (upp+low)/2.0;
        int fgx = 0;
        if(p[0].first == 0) fgx = 1;
        while(fgx < n and p[fgx].second <= x) fgx++;
        if(fgx > n-3 and n > 3 or fgx > n-2) {
            upp = x;
            continue;
        }
        ld ge = p[fgx].second;
        ld pe = p[fgx].second;
       /* for(int i=0; i <= fgx; ++i) {
            ge = max(ge, p[i].second);
            pe = max(pe, p[i].second);
        }*/
        
        //cerr << fgx << ":" << p[fgx].second <<  " is first greater than " << x << endl;
        
        bool good = false;
        for(int i=fgx+1; i < n; i++) {
           // cerr << "pd[" << i << "] = " << pd[i] << endl;
            if(ge-x > pe+x) {
               break;
             //  continue;
            }
            else if(gd[i]-x <= pd[i]+x and pd[i]+x >= ge-x) {
                good = true;
                break;
            }
            ge = max(ge, p[i].second);
            pe = min(pe, p[i].second);
        }
        if(good) upp = x;
        else low = x;
        
    }
    cout << (upp+low)/2.0 << endl;
    
    
    
}
