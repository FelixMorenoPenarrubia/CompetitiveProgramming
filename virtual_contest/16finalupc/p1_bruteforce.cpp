#include<bits/stdc++.h>

using namespace std;

typedef long double ll;
typedef vector<ll> vi;
typedef vector<vi> vvi;
typedef pair<ll, ll> ii;
typedef vector<ii> vii;

#define X first
#define Y second

vvi operator * (vvi a, vvi b) {
    int n = a.size();
    vvi r = vvi(n, vi(n, 0));
    for(int i=0; i < n; ++i) {
        for(int j=0; j < n; ++j) {
            for(int k=0; k < n; ++k) {
                r[i][j] += a[i][k]*b[k][j];
            }
        }
    }
    return r;
}

int main() {
    cout.setf(ios::fixed);
    cout.precision(4);
   ll pd, qm, pm, qd;
   while(cin >> pd >> qm >> pm >> qd) {
        vvi md = vvi(4, vi(4, 0));
        md[0][0] = 1-pd;
        md[0][1] = pd;
        
        md[1][0] = (1-pm)*qd;
        md[1][1] = (1-pm)*(1-qd);
        md[1][2] = pm*qd;
        md[1][3] = pm*(1-qd);
        
        md[2][0] = (1-pd)*qm;
        md[2][1] = pd*qm;
        md[2][2] = (1-pd)*(1-qm);
        md[2][3] = pd*(1-qm);
        
        md[3][3] = 1;
        
        vvi mm = vvi(md);
        mm[0][0] = 1-pm;
        mm[0][1] = 0;
        mm[0][2] = pm;
        
        vvi cpd = vvi(md);
        vvi cpm = vvi(mm);
        ll prevpd = 0;
        ll prevpm = 0;
        ll ans1 = 0;
        ll ans2 = 0;
        
        for(ll i=2; i <= 1000; i+=1) {
            cpd = cpd*md;
            cpm = cpm*mm;
            
            ans1 += (cpd[0][3]-prevpd)*i;
            ans2 += (cpm[0][3]-prevpm)*i;
            
            prevpd = cpd[0][3];
            prevpm = cpm[0][3];
            
        }
        cout << min(ans1, ans2) << endl;
        
   }
}
