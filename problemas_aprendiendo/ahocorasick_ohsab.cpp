#include<bits/stdc++.h>

using namespace std;

struct node {
    node* parent;
    node* suffixlink;
    vector<node*> children;
    int ci;
    int wordlength;
    string word;
    node(int i) {
        children = vector<node*>(30, nullptr);
        wordlength = 0;
        ci = i;
        parent = nullptr;
        suffixlink = nullptr;
    }
};

typedef node* pnode;

int to_int(char c) {
    if(c == '/') return 28;
    return int(c-'a');
}



pnode build_automata(vector<string> &v) {
    pnode root = new node(-1);
    int n = v.size();
    for(int i=0; i < n; ++i) {
        
        
        string s = v[i];
        
        //cerr << "Building word: " << s << endl;
        
        int m = s.length();
        pnode cnode = root;
        for(int j=0; j < m; ++j) {
            
        //    cerr << "Current char: " << s[j] << " (" << to_int(s[j]) << ") " << endl;
            
            if(cnode->children[to_int(s[j])] == nullptr) {
                cnode->children[to_int(s[j])] = new node(to_int(s[j]));
                
            }
            cnode->children[to_int(s[j])]->parent = cnode;
            cnode = cnode->children[to_int(s[j])];
            
           // cerr << "Char of parent: " << cnode->parent->ci << endl;
        }
        cnode->wordlength = m;
        cnode->word = s;
    }
    return root;
}


pnode next_node(pnode cnode, int i);

pnode suffix_link(pnode p) {
    
   // cerr << "suffix_link(" << p->ci << ")" << endl;
    
    if(p->suffixlink == nullptr) {
        if(p->parent == nullptr) return p;
        if(p->parent->parent == nullptr) return p->parent;
        
        
        pnode pr = suffix_link(p->parent);
        pr = next_node(pr, p->ci);
        p->suffixlink = pr;
        
    }
    return p->suffixlink;
}

pnode next_node(pnode cnode, int i) {
   
    
    //cerr << "next_node(" << cnode->ci << ", " << c << " (" << i << ") )" << endl;
    
    if(cnode->children[i] == nullptr) {
        while(cnode->children[i] == nullptr and cnode->parent != nullptr) cnode = suffix_link(cnode);
        if(cnode->children[i] == nullptr) return cnode;
        else return cnode->children[i];
    }
    else return cnode->children[i];
}

int main() {
    int n;
    cin >> n;
    vector<string> words (n);
    for(int i=0; i < n; ++i) cin >> words[i];
    pnode root = build_automata(words);
    int m;
    cin >> m;
    
    string dummy;
    getline(cin, dummy);
    
    for(int t=0; t < m; ++t) {
        pnode cnode = root;
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
            
            cnode = next_node(cnode, to_int(s[i]));
            if(cnode->wordlength > 0) {
                
            //    cerr << "found word " << cnode->word << endl;
                
            //    cerr << "ending idx = " << i << " start idx = " <<i-cnode->wordlength+1 << endl;
                
                auto it = ans.lower_bound(pair<int, string>(i-cnode->wordlength+1, ""));
                if(it == ans.end() or (it->first-int(it->second.length())+1) >= i-cnode->wordlength+1) {
                    while(it != ans.end()) {
                        
                   //     cerr << "erasing word " << it->second << endl;
                        
                        it = ans.erase(it);
                    }
                    
                 //   cerr << "add word " << cnode->word << endl;
                    
                    ans.emplace(i, cnode->word);
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
