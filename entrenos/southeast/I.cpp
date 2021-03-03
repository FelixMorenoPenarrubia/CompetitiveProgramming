#include<bits/stdc++.h>

using namespace std;

typedef long long int ll;
typedef vector<ll> vi;
typedef vector<vi> vvi;
typedef pair<ll, ll> ii;
typedef vector<ii> vii;
typedef vector<vii> vvii;

int main() {
    freopen("integral.in", "r", stdin);
    freopen("integral.out", "w", stdout);
    int n;
    cin >> n;
    ll ans = 0;
    vi x(n);
    vi y(n);
    for(int i=0; i < n; ++i) {
        cin >> x[i];
        cin >> y[i];
        if(x[i] < 0) x[i] = -x[i];
        if(y[i] < 0) y[i] = -y[i];
        x[i] %= 2;
        y[i] %= 2;
    }
    ll area = x[0]*y[n-1]+y[0]*x[n-1];
    for(int i=0; i < n-1; ++i) {
        area += x[i]*y[i+1]+y[i]*x[i+1];
    }
    if(area%2) {
        cout << 0 << endl;
        return 0;
    }
    vi cps(n+1, 0);
    
    for(int i=0; i < n-1; ++i) cps[i+1] = (x[i]*y[i+1]+x[i+1]*y[i]+cps[i])%2;
    vi e_cps(n+1);
    vi o_cps(n+1);
    vi e_cps_px(n+1);
    vi o_cps_px(n+1);
    vi e_cps_py(n+1);
    vi o_cps_py(n+1);
    vi e_cps_pxy(n+1);
    vi o_cps_pxy(n+1);
    for(int i=0; i < n; ++i) {
        ll u_cps = cps[i];
        ll u_cps_px = cps[i]+x[i];
        ll u_cps_py = cps[i]+y[i];
        ll u_cps_pxy = cps[i]+x[i]+y[i];
        if(u_cps%2) {
            o_cps[i+1] = o_cps[i]+1;
            e_cps[i+1] = e_cps[i];
        }
        else {
            o_cps[i+1] = o_cps[i];
            e_cps[i+1] = e_cps[i]+1;
        }
        
         if(u_cps_px%2) {
            o_cps_px[i+1] = o_cps_px[i]+1;
            e_cps_px[i+1] = e_cps_px[i];
        }
        else {
            o_cps_px[i+1] = o_cps_px[i];
            e_cps_px[i+1] = e_cps_px[i]+1;
        }
          if(u_cps_py%2) {
            o_cps_py[i+1] = o_cps_py[i]+1;
            e_cps_py[i+1] = e_cps_py[i];
        }
        else {
            o_cps_py[i+1] = o_cps_py[i];
            e_cps_py[i+1] = e_cps_py[i]+1;
        }
          if(u_cps_pxy%2) {
            o_cps_pxy[i+1] = o_cps_pxy[i]+1;
            e_cps_pxy[i+1] = e_cps_pxy[i];
        }
        else {
            o_cps_pxy[i+1] = o_cps_pxy[i];
            e_cps_pxy[i+1] = e_cps_pxy[i]+1;
        }
         
    }
    
    for(int i=0; i < n-1; ++i) {
        
        int m = n;
        if(i == 0) m = n-1;
        
       // int preans = ans;
        
       /* cerr << "i = " << i << endl;
        cerr << "cps[i] = " << cps[i] << " x[i] = " << x[i] << " y[i] = " << y[i] << endl;
        cerr << "e_cps[i+2] = " << e_cps[i+2] << endl;
        cerr << "o_cps[i+2] = " << o_cps[i+2] << endl;
        cerr << "e_cps_px[i+2] = " << e_cps_px[i+2] << endl;
        cerr << "o_cps_px[i+2] = " << o_cps_px[i+2] << endl;
        cerr << "e_cps_py[i+2] = " << e_cps_py[i+2] << endl;
        cerr << "o_cps_py[i+2] = " << o_cps_py[i+2] << endl;
        cerr << "e_cps_pxy[i+2] = " << e_cps_pxy[i+2] << endl;
        cerr << "o_cps_pxy[i+2] = " << o_cps_pxy[i+2] << endl;*/
        
        
        if(cps[i]%2) {
            if(y[i]%2) {
                if(x[i]%2) {
                    ans += o_cps_pxy[m]-o_cps_pxy[i+2];
                }
                else {
                    ans += o_cps_px[m]-o_cps_px[i+2];
                }
            }
            else {
                if(x[i]%2) {
                    ans += o_cps_py[m]-o_cps_py[i+2];
                }
                else {
                    ans += o_cps[m]-o_cps[i+2];
                }
            }
        }
        else {
             if(y[i]%2) {
                if(x[i]%2) {
                    ans += e_cps_pxy[m]-e_cps_pxy[i+2];
                }
                else {
                    ans += e_cps_px[m]-e_cps_px[i+2];
                }
            }
            else {
                if(x[i]%2) {
                    ans += e_cps_py[m]-e_cps_py[i+2];
                }
                else {
                    ans += e_cps[m]-e_cps[i+2];
                }
            }
        }
        //if((x[i]*y[i+1]+y[i]*x[i+1])%2 == 0) ans++;
        
        //cerr << "Increase: " << ans-preans << endl;
    }
    cout << ans << endl;
    
}
