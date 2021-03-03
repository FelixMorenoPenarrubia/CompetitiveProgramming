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

ll det(vvi& a) {
    int n = a.size();
    
   // cerr << "det size = " << n << endl;
    
    if(n == 1) return a[0][0];
    if(n == 2) return a[0][0]*a[1][1]-a[0][1]*a[1][0];
    ll mult = 1;
    ll ans = 0;
    for(int i=0; i < n; ++i) {
        vvi b = vvi(n-1, vi());
        for(int j=1; j < n; ++j) {
            for(int k=0; k < n; ++k) {
                if(k == i) continue;
                b[j-1].push_back(a[j][k]);
            }
        }
        ans += a[0][i]*mult*det(b);
        
        mult *= -1;
    }
    return ans;
}

vvi inv(vvi& a) {
    int n = a.size();
    vvi adj = vvi(n, vi(n, 0));
    ll mult = 1;
    ll deta = det(a);
    
    
    for(int i=0; i < n; ++i) {
        for(int j=0; j < n; ++j) {
            vvi b = vvi();
            for(int l=0; l < n; ++l) {
                if(l == i) continue;
                b.push_back(vi());
                int d = b.size()-1;
                for(int k=0; k < n; ++k) {
                    if(k == j) continue;
                    b[d].push_back(a[l][k]);
                }
            }
            adj[j][i] = mult*det(b)/deta;
            mult *= -1;
        }
    }
    return adj;
}
void print(vvi &a) {
    int n = a.size();
    for(int i=0; i < n; ++i) {
        for(int j=0; j < n; ++j) {
            cerr << a[i][j] << " ";
        }
        cerr << endl;
    }
}

int main() {
    cout.setf(ios::fixed);
    cout.precision(4);
   ll pd, qm, pm, qd;
   while(cin >> pd >> qm >> pm >> qd) {
        vvi q1 = {{pd, -pd, 0}, {-1*(1-pm)*qd, 1-(1-pm)*(1-qd), -pm*qd}, {-1*(1-pd)*qm, -pd*qm, 1-(1-pd)*(1-qm)}};
        
         vvi q2 = {{pm, 0, -pm}, {-1*(1-pm)*qd, 1-(1-pm)*(1-qd), -pm*qd}, {-1*(1-pd)*qm, -pd*qm, 1-(1-pd)*(1-qm)}};
         
        
         
        vvi n1 = inv(q1);
        vvi n2 = inv(q2);
        
      //  print(n1);
       // print(n2);
        
        cout << min(n1[0][0]+n1[0][1]+n1[0][2], n2[0][0]+n2[0][1]+n2[0][2]) << endl;
        
   }
}
