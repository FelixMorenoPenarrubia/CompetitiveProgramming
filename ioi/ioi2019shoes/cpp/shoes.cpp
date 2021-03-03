#include "shoes.h"

using namespace std;

typedef long long int ll;
typedef vector<ll> vi;
typedef vector<vi> vvi;

vi st;

void build_st(int p, int l, int r) {
    if(l == r) {
        st[p] = 1;
    }
    else {
        build_st(2*p, l, (l+r)/2);
        build_st(2*p+1, (l+r)/2+1, r);
        st[p] = st[2*p]+st[2*p+1];
    }
}

void update_st(int p, int l, int r, int i, ll v) {
    if(i < l or i > r) return;
    if(l == r) {
        st[p] += v;
    }
    else {
        update_st(2*p, l, (l+r)/2, i, v);
        update_st(2*p+1, (l+r)/2+1, r, i, v);
        st[p] = st[2*p]+st[2*p+1];
    }
}
ll rsq(int p, int l, int r, int i, int j) {
    if(j < l or i > r) return 0;
    if(l >= i and r <= j) return st[p];
    return rsq(2*p, l, (l+r)/2, i, j) + rsq(2*p+1, (l+r)/2+1, r, i, j);
}
ll absol(ll x) {
    return (x > 0) ? x : -x;
}
ll sign(ll x) {
    return (x > 0) ? 1 : -1;
}


long long count_swaps(std::vector<int> s) {
	ll sol = 0;
    ll inv = 0;
    int n = s.size();
    vvi ind = vvi(n+1, vi());
    vi cind = vi(n+1, 0);
    st = vi(4*n, 0);
    build_st(1, 0, n-1);
    for(int i=0; i < n; ++i) {
        ll cs = absol(s[i]);

        if(cind[cs] == ind[cs].size() || sign(s[ind[cs][cind[cs]]]) == sign(s[i])) {
            ind[cs].push_back(i);
        }
        else {
            int idx = ind[cs][cind[cs]];
            if(i > idx+1) sol += rsq(1, 0, n-1, idx+1, i-1);
            if(sign(s[i]) == -1) inv++;
            update_st(1, 0, n-1, i, -1);
            update_st(1, 0, n-1, idx, 1);
            cind[cs]++;
        }
    }
    return sol+inv;
}
