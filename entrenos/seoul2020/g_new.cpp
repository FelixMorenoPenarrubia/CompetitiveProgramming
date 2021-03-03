    #include<bits/stdc++.h>
     
     
    using namespace std;
     
    typedef double ld;
     
    vector<ld> v;
    ld d;
    int n;
     
    ld evaluate(ld x) {
    	ld ans = 0;
    	for(int i=0; i < n; ++i) {
    		ans = max(ans, abs(v[i]-(x+d*i)));
    	}
    	return ans;
    }

    ld evaluate2(ld x) {
    	ld ans = 0;
    	for(int i=0; i < n; ++i) {
    		ans = max(ans, abs(v[i]-(x+d*(n-i-1))));
    	}
    	return ans;
    }
     
    int main() {
    	ios::sync_with_stdio(false);
    	cin.tie(NULL);
     
    	
    	cin >> n >> d;
    	v = vector<ld>(n);
    	
    	for(int i=0; i < n; ++i) {
    		cin >> v[i];
    		//l = min(l, v[i]-n*d);
    		//r = max(r, v[i]+n*d);
    	}
     
    	int N = 70;

    	ld l = -2e16;
    	ld r = 2e16;
     
    	while(N--) {
     
    		//cerr << l << " " << r << endl;
    		//cerr << r-l << endl;
     
    		ld m1 = (51*l+49*r)/100.0;
    		ld m2 = (49*l+51*r)/100.0;
     
    		//cerr << m1 << " " << m2 << endl;
     
    		ld a1 = evaluate(m1);
    		ld a2 = evaluate(m2);
    		if(a1 > a2) {
    			l = m1;
    		}
    		else {
    			r = m2;
    		}
    	}


    	ld ans1 = evaluate(l);

    	 N = 70;

    	 l = -1e17;
    	 r = 1e17;

     
    	while(N--) {
     
    		//cerr << l << " " << r << endl;
    		//cerr << r-l << endl;
     
    		ld m1 = (51*l+49*r)/100.0;
    		ld m2 = (49*l+51*r)/100.0;
     
    		//cerr << m1 << " " << m2 << endl;
     
    		ld a1 = evaluate2(m1);
    		ld a2 = evaluate2(m2);
    		if(a1 > a2) {
    			l = m1;
    		}
    		else {
    			r = m2;
    		}
    	}

    	ld ans2 = evaluate2(l);
     
    	cout.setf(ios::fixed);
    	cout << setprecision(1);
    	cout << min(ans1, ans2) << endl;
     
    	
    }