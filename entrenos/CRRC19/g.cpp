    #include <bits/stdc++.h>
#pragma comment(linker, "/stack:200000000")
#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")


    using namespace std;
     
    const int MAX_TIME = 38;
    int n;
     
    unordered_map<int, int> m;
    unordered_map<int, int> out;
    vector<int> v;
    unordered_map<int, int> m2;
     
    int encode(vector<int> x, int t) {
        int res = t;
        for (int i = n-1; i >= 0; --i) {
            res <<= 5;
            res += x[i];
        }
        return res;
    }
     
    void dp(int x) {
        int y = x;
        vector<int> times(n);
        for (int i = 0; i < n; ++i) {
            times[i] = x&31;
            x >>= 5;
        }
        int t = x;
        m2[t] = y;
        for (int i = 0; i < (1<<n); ++i) {
            vector<int> times2 = times;
            int low = 2e9;
            for (int j = 0; j < n; ++j) {
                if ((1<<j)&i) times2[j] = v[j] - times2[j];
                if (times2[j] > 0 and times2[j] < low) low = times2[j];
            }
            for (int j = 0; j < n; ++j) if (times2[j] > 0) times2[j] -= low;
            int s = encode(times2, t+low);
            if (!m.count(s) and t+low <= MAX_TIME) {
                m[s] = y;
                out[s] = low*(1<<n) + i;
                dp(s);
            }
        } 
    }
     
    int main() {
        cin >> n;
        v = vector<int>(n);
        for (int i = 0; i < n; ++i) cin >> v[i];
        m[0] = 0;
        dp(0);
        int k;
        cin >> k;
        vector<int> knap(k+1, -1);
        knap[0] = 0;
        for (int i = 0; i < k; ++i) {
            if (knap[i] > -1) {
                for (int j = 0; j < n; ++j) {
                    int t = i + v[j];
                    if (t <= k and knap[t] == -1) knap[t] = j;
                }
            }
        }
        vector<int> events1, events2;
        for (int i = 0; i <= MAX_TIME and i <= k; ++i) {
            if (knap[k-i] >= 0 and m2.count(i)) {
                int s = m2[i];
                while (s != 0) {
                    events1.push_back(out[s]);
                    s = m[s];
                }
                s = k-i;
                while (s != 0) {
                    events2.push_back(knap[s]);
                    s = s-v[knap[s]];
                }
                cout << events1.size()+events2.size()+1 << "\n";
                int time = 0;
                for (int i = events2.size()-1; i >= 0; --i) {
                    cout << time << " 1 " << events2[i]+1 << "\n";
                    time += v[events2[i]];
                }
                for (int i = events1.size()-1; i >= 0; --i) {
                    int s = events1[i];
                    vector<int> w(n, 0);
                    int cnt = 0;
                    for (int j = 0; j < n; ++j) {
                        if (s&1) w[j] = 1, ++cnt;
                        s >>= 1;
                    }
                    cout << time << " " << cnt;
                    for (int j = 0; j < n; ++j) if (w[j] == 1) cout << " " << j+1;
                    cout << endl;
                    time += s;
                }
                cout << k << " " << 0 << "\n";
                return 0;
            }
        }
        cout << -1 << '\n';
    }