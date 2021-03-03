#include<bits/stdc++.h>

using namespace std;

typedef long long int ll;
typedef vector<ll> vi;
typedef vector<vi> vvi;
typedef pair<ll, ll> ii;
typedef vector<ii> vii;

int left(int p) {
    return 2*p;
}
int right(int p) {
    return 2*p+1;
}
int parent(int p) {
    return (p-p%2)/2;
}
ll eval(ii line, ll point) {
    return line.first + line.second*point;
}
void printline(ii line) {
    cerr << line.second << "x + " << line.first;
}

vii old_lichao;
vii new_lichao;
vi a;
vi dp;
vi ndp;
ll INF = 1e18;
ll LIM_LICHAO = 1e6;
int n, k;
void init_lichao(vii &lichao) {
    lichao = vii(4*LIM_LICHAO, ii(INF, 0));
}

void update_lichao(int p, int l, int r, ii line, vii &lichao) {
    
     cerr << "update_lichao(" << p << ", " << l << ", " << r << ", "; printline(line); cerr << ")" << endl;
    
    if(l == r) {
        if(eval(line, l) < eval(lichao[p], l)) lichao[p] = line;
        return;
    }
    int m = (l+r)/2;
    ll a1 = eval(line, l);
    ll a2 = eval(line, m);
    ll b1 = eval(lichao[p], l);
    ll b2 = eval(lichao[p], m);
    
    cerr << a1 << " " << a2 << " " << b1 << " " << b2 << " valores " << endl;
    
    if(a1 >= b1 and a2 >= b2) {
        update_lichao(right(p), m+1, r, line, lichao);
    }
    else if(a1 <= b1 and a2 <= b2) {
        ii tmp = lichao[p];
        lichao[p] = line;
        update_lichao(right(p), m+1, r, tmp, lichao);
    }
    else if(a1 <= b1 and a2 >= b2) {
        update_lichao(left(p), l, m, line, lichao);
    }
    else if(a1 >= b1 and a2 <= b2) {
        ii tmp = lichao[p];
        lichao[p] = line;
        update_lichao(left(p), l, m, tmp, lichao);
    }
    cerr << "lichao[" << p << "] = "; printline(lichao[p]); cerr << endl;
}
ll rmq_lichao(int p, int l, int r, int point, vii &lichao) {
    
    //cerr << "rmq_lichao(" << p << ", " << l << ", " << r << ", " << point << ")" << endl;
    //cerr << "lichao[" << p << "] = "; printline(lichao[p]); cerr << endl;
    
    if(l == r) {
        return eval(lichao[p], point);
    }
    int m = (l+r)/2;
    if (point <= m) return min(eval(lichao[p], point), rmq_lichao(left(p), l, m, point, lichao));
    else return min(eval(lichao[p], point), rmq_lichao(right(p), m+1, r, point, lichao));
}

void update_dp(int i) {
    for(int j=0; j < n; ++j) {
        ndp[j+1] = rmq_lichao(1, 0, LIM_LICHAO, a[j], old_lichao)+a[j]*a[j];
        update_lichao(1, 0, LIM_LICHAO, ii(ndp[j]+a[j]*a[j], -2*a[j]), new_lichao);
        
        cerr << "dp[" << i << "][" << j+1 << "] = " << ndp[j+1] << endl;
    }
}


int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> k;
    a = vi(n);
    for(int i=0; i < n; ++i) cin >> a[i];
    dp = vi(n+1, INF);
    ndp = vi(n+1, INF);
    dp[0] = 0;
    init_lichao(old_lichao);
    init_lichao(new_lichao);
    update_lichao(1, 0, LIM_LICHAO, ii(a[0]*a[0], -2*a[0]), old_lichao);
    for(int i=1; i <= k; ++i) {
        update_dp(i);
        dp = ndp;
        ndp = vi(n+1, INF);
        old_lichao = new_lichao;
        init_lichao(new_lichao);
    }
    cout << dp[n] << endl;
}





