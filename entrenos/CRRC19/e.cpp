#include<bits/stdc++.h>

using namespace std;

typedef vector<int> vi;
typedef vector<vi> vvi;
typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef vector<vii> vvii;



int n, m;
vector<string> mp;
vvi visited_mp;
vvi astid;
vii astcoord;
vector<vector< vector<vector<char> > > > paths_mp;
map<char, ii> dir;



int nast;
vvii al;
vvi am;
vi deg;
vvii paths_ast;


vii vstack;
int idx_recog;
vi visited;



int dfs_mp(int i, int j, int ast, int previ, int prevj) {
	if(i < 0 or i >= n or j < 0 or j >= m) return -1;

	cerr << i << " " << j << endl;
	
	vector<char> pos_dir = {'L', 'R'};
	if(mp[i][j] == '-') {
		pos_dir = {'L', 'R'};
	}
	else if(mp[i][j] == '|') {
		pos_dir = {'U', 'D'};
	}
	else if(mp[i][j] == 'L') {
		pos_dir = {'U', 'R'};
	}
	else if(mp[i][j] == 'J') {
		pos_dir = {'U', 'L'};
	}
	else if(mp[i][j] == 'r') {
		pos_dir = {'D', 'R'};
	}
	else if(mp[i][j] == '7') {
		pos_dir = {'D', 'L'};
	}
	else if(mp[i][j] == '*') {
		paths_mp[ast][astid[i][j]].push_back(vector<char>());
		return astid[i][j];

	}
	else if(mp[i][j] == '.') {
		return -1;
	}

	int rval = -1;
	int confirmed = 0;
	for(int k=0; k < 2; ++k) {
		int x = i+dir[pos_dir[k]].first;
		int y = j+dir[pos_dir[k]].second;
		if(!((x == previ) && (y == prevj))) {


			int ast2 = dfs_mp(x, y, ast, i, j);
			/*if(ast2 == -1) {
				cerr << "i = " << i << "j = " << j << endl;
				exit(1);
			}
			cerr << ast2 << endl;*/
			paths_mp[ast][ast2].back().push_back(pos_dir[k]);
			rval = ast2;
		}
		else {
			confirmed = 1;
		}
	}
	if(!confirmed) rval = -1;
	return rval;
}

void construct_graph() {
	nast = 0;
	astid = vvi(n, vi(m, 0));
	for(int i=0; i < n; ++i) {
		for(int j=0; j < m; ++j) {
			if(mp[i][j] == '*') {
				astid[i][j] = nast;
				nast++;
			}
		}
	}
	al = vvii(nast, vii());
	am = vvi(nast, vi(nast, 0));
	deg = vi(nast, 0);
	paths_mp = vector<vector< vector<vector< char> > > >(nast, vector<vector<vector<char > > >(nast, vector<vector< char > >()));
	astcoord = vii(nast);
	for(int i=0; i < n; ++i) {
		for(int j=0; j < m; ++j) {
			if(mp[i][j] == '*') {
				astcoord[astid[i][j]] = ii(j+1, i+1);
				for(auto it=dir.begin(); it != dir.end(); ++it) {
					int x = i+it->second.first;
					int y = j+it->second.second;
					if(x < 0 || x >= n || y < 0 || y >= m) continue;

					if(it->first == 'L' && (mp[x][y] != '-' && mp[x][y] != 'r' && mp[x][y] != 'L')) continue;
					if(it->first == 'R' && (mp[x][y] != '-' && mp[x][y] != '7' && mp[x][y] != 'J')) continue;
					if(it->first == 'U' && (mp[x][y] != '|' && mp[x][y] != 'r' && mp[x][y] != '7')) continue;
					if(it->first == 'D' && (mp[x][y] != '|' && mp[x][y] != 'L' && mp[x][y] != 'J')) continue;
					cerr << "DFS INIT" << endl;
					int ast2 = dfs_mp(x, y, astid[i][j], i, j);
					if(ast2 != -1) {

						cerr << "ast2 " << ast2 << endl;

						al[astid[i][j]].emplace_back(ast2, paths_mp[astid[i][j]][ast2].size()-1);
						am[astid[i][j]][ast2]++;
						deg[astid[i][j]]++;
						paths_mp[astid[i][j]][ast2].back().push_back(it->first);

						if(ast2 == astid[i][j]) {
							//al[astid[i][j]].emplace_back(ast2, 1);
							//am[astid[i][j]][ast2]++;
							deg[astid[i][j]]++;
							 break;
						}
					}
				}
			}
		}
	}

}

void dfs_recog(int v, int ori) {
	if(visited[v]) return;
	visited[v] = 1;
	if((deg[v]&1) && v != ori) {
		idx_recog = v;
	}
	for(int i=0; i < (int)al[v].size(); ++i) {
		int u = al[v][i].first;
		if(am[v][u]) {
			dfs_recog(u, ori);
		}
	}
}

bool dfs_fetch(int v, int tar) {
	if(visited[v]) return false;
	visited[v] = true;
	if(v == tar) {
		vstack.emplace_back(v, 0);
		return true;
	}
	for(int i=0; i < (int)al[v].size(); ++i) {
		int u = al[v][i].first;
		if(am[v][u]) {
			if(dfs_fetch(u, tar)) {
				vstack.emplace_back(v, al[v][i].second);
				am[v][u] = 0;
				am[u][v] = 0;
				deg[v]--;
				deg[u]--;
				return true;
			}
		}
	}
	return false;
}

void euler_path(int v) {

	cerr << "euler_path(" << v << ")" << endl;

	vstack = vii();
	visited = vi(nast);
	dfs_recog(v, v);

	visited = vi(nast);
	dfs_fetch(v, idx_recog);

	vii cpath;
	while(!vstack.empty()) {
		int u = vstack.back().first;
		cpath.push_back(vstack.back());
		vstack.pop_back();
		
		if(deg[u] == 2) {
			int v1 = -1;
			int v2 = -1;
			for(int i=0; i < (int)al[u].size(); ++i) {
				int l = al[u][i].first;
				if(am[u][l]) {
					if(v1 == -1) v1 = l;
					else v2 = l;
				}
			}
			dfs_fetch(v1, v2);
		}
	}
	paths_ast.push_back(cpath);
}

void euler_tour(int first) {

	cerr << "et" << first << endl;
   


  

    vii st;
    st.emplace_back(first, 0);
    vii res;
    while (!st.empty()) {
        int v = st.back().first;
        int edg = st.back().second;
        int i;
        int nedg = 0;
        
        for (i = 0; i < nast; ++i)
            if (am[v][i])
                break;
        for(int j=0; j < (int)al[v].size(); ++j) {
        	if(al[v][j].first == i && al[v][j].second >= 0) {
        		nedg = al[v][j].second;
        		al[v][j].second = -1;
        		break;
        	}
        }
        if (i == nast) {
            res.emplace_back(v, edg);
            st.pop_back();
        } else {
            --am[v][i];
            --deg[v];
            if(i != v) --am[i][v];
            --deg[i];

            st.emplace_back(i, nedg);
        }
    }

    
    vii rres;
    for(int i=0; i+1 < (int)res.size(); ++i) {
    	rres.emplace_back(res[i].first, res[i+1].second);
    }
    rres.emplace_back(res.back().first, 0);
    paths_ast.push_back(rres);

    
}


int main() {

	ios::sync_with_stdio(false);
	cin.tie(NULL);


	cin >> n >> m;
	
	mp = vector<string>(n);

	dir['U'] = {-1, 0};
	dir['D'] = {1, 0};
	dir['L'] = {0, -1};
	dir['R'] = {0, 1};
 
	for(int i=0; i < n; ++i) {
		cin >> mp[i];
	}

	construct_graph();

	for(int i=0; i < nast; ++i) {
		while(deg[i]&1) {
			euler_path(i);
		}
	}
	for(int i=0; i < nast; ++i) {
		if(deg[i] > 0) {
			euler_tour(i);
		}
	}

	int k = paths_ast.size();
	cout << k << endl;


	for(int i=0; i < k; ++i) {
		for(int j=0; j < (int)paths_ast[i].size(); ++j) {
			cerr << paths_ast[i][j].first << " " << paths_ast[i][j].second << " - " ;
		}
		cerr << endl;
	}


	//vvi pmpc = vvi(nast, vi(nast, 0));

	for(int i=0; i < k; ++i) {
		cout << astcoord[paths_ast[i][0].first].first << " " << astcoord[paths_ast[i][0].first].second << " ";
		for(int j=0; j+1 < (int)paths_ast[i].size(); ++j) {
			vector<char> s = paths_mp[paths_ast[i][j].first][paths_ast[i][j+1].first][paths_ast[i][j].second];
			//pmpc[paths_ast[i][j]][paths_ast[i][j+1]]++;
			
			for(int l=(int)s.size()-1; l > -1; --l ) {
				cout << s[l];
			}
		}
		cout << endl;
	}

}