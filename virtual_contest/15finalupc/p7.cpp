#include<bits/stdc++.h>


using namespace std;

typedef long long int ll;
typedef vector<ll> vi;
typedef vector<vi> vvi;
typedef vector<bool> vb;
typedef long double ld;
typedef vector<ld> vld;

int main() {
    ll n;
    cout.setf(ios::fixed);
    cout.precision(4);
    
    
    while(cin >> n) {
       if(n <= 1) {
           cout << 0.0 << endl; 
           continue;
       }
       //ld ans = 0;
       ll low = 0;
       ll upp = n;
       while(upp-low > 1) {
            ll m = ll(upp+low)/2;
            if((1+(m*(m+1))/2) <= (n)) {
                low = ll(m);
            }
            else {
                upp = ll(m);
            }
       }
       ll m = low;
       ll num = (m*(m+1)*(2*m+4))/6 + (n-1-(m*(m+1))/2)*(m+2);
       cout << ld(num)/n << endl;
       
        
    }
   
}
