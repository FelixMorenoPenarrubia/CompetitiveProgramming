#include<bits/stdc++.h>

using namespace std;

const int K = 26;

struct Vertex {
    int next[K];
    bool leaf = false;
    int p = -1;
    char pch;
    int link = -1;
    int go[K];
    int wlength = 0;
    string word;
    Vertex(int p=-1, char ch='$') : p(p), pch(ch) {
        fill(begin(next), end(next), -1);
        fill(begin(go), end(go), -1);
    }
};

vector<Vertex> t(1);

void add_string(string const& s) {
    int v = 0;
    for (char ch : s) {
        int c = ch - 'a';
        if (t[v].next[c] == -1) {
            t[v].next[c] = t.size();
            t.emplace_back(v, ch);
        }
        v = t[v].next[c];
    }
    t[v].leaf = true;
    t[v].wlength = s.length();
    t[v].word = s;
}

int go(int v, char ch);

int get_link(int v) {
    if (t[v].link == -1) {
        if (v == 0 || t[v].p == 0)
            t[v].link = 0;
        else
            t[v].link = go(get_link(t[v].p), t[v].pch);
    }
    return t[v].link;
}

int go(int v, char ch) {
    int c = ch - 'a';
    if (t[v].go[c] == -1) {
        if (t[v].next[c] != -1)
            t[v].go[c] = t[v].next[c];
        else
            t[v].go[c] = v == 0 ? 0 : go(get_link(v), ch);
    }
    return t[v].go[c];
} 

int main() {
    int n;
    cin >> n;
    vector<string> words (n);
    for(int i=0; i < n; ++i) cin >> words[i];
    for(int i=0; i < n; ++i) add_string(words[i]);
    int m;
    cin >> m;
    
    string dummy;
    getline(cin, dummy);
    
    for(int M=0; M < m; ++M) {
        int cnode = 0;
        string sr;
        getline(cin, sr);
        string s = "";
        for(int j=0; j < (int) sr.length(); ++j) {
            if(sr[j] != ' ' and sr[j] != '/') s += sr[j];
        }
        int l = s.length();
        reverse(s.begin(), s.end());
      //  int lastop = -9999999;
        
   //   cerr << "s = " << s << endl;
        
        
        set<pair<int, string> > ans;
        //ans.emplace(-1, "");
        for(int i=0; i < l; ++i) {
            
//            cerr << "i = " << i << endl;
            
            cnode = go(cnode, s[i]);
            if(t[cnode].wlength > 0) {
                
            //    cerr << "found word " << cnode->word << endl;
                
            //    cerr << "ending idx = " << i << " start idx = " <<i-cnode->wordlength+1 << endl;
                
                auto it = ans.lower_bound(pair<int, string>(i-t[cnode].wlength+1, "$"));
                auto it2 = it;
                bool er = true;
                while(it != ans.end()) {
                     if((it->first-int(it->second.length())+1) < i-t[cnode].wlength+1) er = false;
                     ++it;
                }
                if(er) {
                    
                    it = it2;
                    
                    while(it != ans.end()) {
                        
                   //     cerr << "erasing word " << it->second << endl;
                        
                        it = ans.erase(it);
                    }
                    
                 //   cerr << "add word " << cnode->word << endl;
                    
                    ans.emplace(i, t[cnode].word);
                }
            }
        }
        if(ans.size() == 0) cout << "-" << endl;
        
        else {
            auto it = ans.begin();
            for(; it != ans.end(); ) {
                cout << it->second;
                ++it;
                if(it != ans.end()) cout << " ";
            }
            cout << endl;
        }
       
    }
}
