#include<bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef vector<ll> vi;
typedef vector<vi> vvi;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    string s;
    bool bibliomode = false;
    vector<string> cites;
    int idx = -1;
    map<string, int> index;
    vector<vector<string> > str;
    vector<bool> ext;
    vector<string> es;
    while(cin >> s) {
        if(s == "\\begin{thebibliography}{99}") {
            bibliomode = true;
        }
        else if(s == "\\end{thebibliography}") {
            break;
        }
        else if(s[0] == '\\') {
            if(bibliomode) {
                s = s.substr(8);
                string t = "";
                bool extra = false;
                for(int i=0; i < (int)s.length(); ++i) {
                    if(s[i] == '}') {
                        t = s.substr(i+1);
                        s = s.substr(0, i+1);
                        extra = true;
                        break;
                    }
                }
               // cerr << s << endl;
                idx++;
                index[s] = idx;
                str.push_back(vector<string>());
                ext.push_back(extra);
                es.push_back(t);
            }
            else {
                s = s.substr(5);
                for(int i=0; i < (int)s.length(); ++i) {
                    if(s[i] == '}') {
                        s = s.substr(0, i+1);
                        break;
                    }
                }
                cites.push_back(s);
            }
        }
        else {
            if(bibliomode) {
                str[idx].push_back(s);
            }
        }
    }
    
    bool correct = true;
    for(int i=0; i <= idx; ++i) {
       // cerr << cites[i] << " idx = " << index[cites[i]] << endl;
        if(index[cites[i]] != i) correct = false;
    }
    if(correct) {
        cout << "Correct" << endl;
    }
    else {
        cout << "Incorrect\n\\begin{thebibliography}{99}" << endl;
        for(int i=0; i <= idx; ++i) {
            int j = index[cites[i]];
            int m = str[j].size();
            cout << "\\bibitem" << cites[i];
            if(ext[j]) {
                cout << es[j];
            }
            for(int k=0; k < m; ++k) {
                cout << " " << str[j][k];
                
            }
            cout << endl;
        }
        cout << "\\end{thebibliography}" << endl;
    }
}
