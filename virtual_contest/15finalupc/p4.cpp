#include<bits/stdc++.h>


using namespace std;

typedef long long int ll;
typedef vector<ll> vi;
typedef vector<vi> vvi;
typedef vector<bool> vb;

int n;
ll k;

bool edge(ll x, ll y) {
    if(x > y) return not edge(y, x);
    ll r = (k + x)*(k - x)*(k + y)*(k - y);
    ll nd = 1;
    ll p10 = 10;
    while(p10 <= r) {
        p10 *= 10;
        nd++;
    }
    for(int i=0; i < (nd-1)/2; ++i) {
        r /= 10;
    }
    
    
  //  cerr << "Edge request: " << x << "->" << y << " Result: " << (r%10)%2 << endl;
    
    return (r%10)%2;
}


int main() {
    
    while(cin >> n >> k) {
        list<ll> path;
        list<ll> notpath;
        path.push_back(1);
        for(int i=2; i <= n; ++i) {
            notpath.push_back(i);
        }
      //  vb inpath = vb(n+1, false);
      //  inpath[1] = true;
        for(int ps=1; ps < n; ++ps) {
            bool good = false;
            ll tail = *(path.begin());
            auto ite = path.end();
            --ite;
            ll head = *(ite);
            
          //  cerr << "head = " << head << " tail = " << tail << endl;
            
            for(auto it=notpath.begin(); it != notpath.end() and not good; ++it) {
                ll i = *(it);
                //if(not inpath[i]) {
                    if(edge(head, i)) {
                        path.push_back(i);
                      //  inpath[i] = true;
                        notpath.erase(it);
                        good = true;
                    }
                    else if(edge(i, tail)) {
                        path.push_front(i);
                        notpath.erase(it);
                     //   inpath[i] = true;
                        good = true;
                    }
               // }
            }
            if(not good) {
                for(auto ite=notpath.begin(); ite != notpath.end() and not good; ++ite) {
                    ll i = *ite;
                    //if(not inpath[i]) {
                        auto it = path.begin();
                        int prev = *it;
                        ++it;
                        while(it != path.end()) {
                            int act = *it;
                            if(edge(prev, i) and edge(i, act)) {
                                path.insert(it, i);
                               // inpath[i] = true;
                                notpath.erase(ite);
                                good = true;
                                break;
                            }
                            
                            prev = act;
                            ++it;
                        }
                    //}
                }
            }
        }
        for(auto it = path.begin(); it != path.end(); ++it) {
            cout << *it;
            ++it;
            if(it != path.end()) cout << " ";
            --it;
        }
        cout << endl;
        
    }
}
