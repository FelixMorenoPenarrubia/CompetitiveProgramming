#include<bits/stdc++.h>

using namespace std;

typedef vector<int> vi;
typedef vector<vi> vvi;


const int MAX_STD = 2e5+5;
const int INF = (1<<30)-1;

int n;
int B;
int n_trees;
int n_nodes;
vi cti;
vi roots;
vvi children;


vi st;

int rmq(int p, int l, int r, int i, int j) {
	if(l > j || r < i) return INF;
	if(l >= i && r <= j) {
		return st[p];
	}

	return rmq( 2*p, l, (l+r)/2, i, j)&rmq( 2*p+1, (l+r)/2+1, r, i, j);
	
}

void update( int p, int l, int r, int i, int v) {
	if(l > i || r < i) return;
	if(l == i && r == i) {
		st[p] = v;
	}
	else {
		update( 2*p, l, (l+r)/2, i, v);
		update( 2*p+1, (l+r)/2+1, r, i, v);
		st[p] = st[2*p]&st[2*p+1];
	}
}


vi parent, depth, heavy, head, pos;
int cur_pos;

int dfs(int v, vector<vector<int>> const& adj) {
    int size = 1;
    int max_c_size = 0;
    for (int c : adj[v]) {
        if (c != parent[v]) {
            parent[c] = v, depth[c] = depth[v] + 1;
            int c_size = dfs(c, adj);
            size += c_size;
            if (c_size > max_c_size)
                max_c_size = c_size, heavy[v] = c;
        }
    }
    return size;
}

void decompose(int v, int h, vector<vector<int>> const& adj) {
    head[v] = h, pos[v] = cur_pos++;
    if (heavy[v] != -1)
        decompose(heavy[v], h, adj);
    for (int c : adj[v]) {
        if (c != parent[v] && c != heavy[v])
            decompose(c, c, adj);
    }
}

int segment_tree_query(int x, int y) {
	return rmq( 1, 0, n_nodes-1, x, y);
}

int ans_query(int a, int b) {
    int res = (1<<(B+2))-1;
    for (; head[a] != head[b]; b = parent[head[b]]) {
        if (depth[head[a]] > depth[head[b]])
            swap(a, b);
        //for(int j=0; j < B; ++j) {
	        int cur_heavy_path_max = segment_tree_query(pos[head[b]], pos[b]);
	        res &= cur_heavy_path_max;
	       // if(res[j] == 0) return -1;
	    //}
    }
    if (depth[a] > depth[b])
        swap(a, b);
   // for(int j=0; j < B; ++j) {
	    int last_heavy_path_max = segment_tree_query(pos[a], pos[b]);
	    res &= last_heavy_path_max;
	//}
	int ans = 0;
	if((!(res&(1<<B))) || (res&(1<<(B+1)))) return -1;
	for(int j=0; j < B; ++j) {
		if(res&(1<<j)) ans++;
		
	}
    return ans;
}

void dfs_printtree(int v) {
	cerr << "v: " << v << endl;
	cerr << "head " << head[v] << endl;
	cerr << "pos " << pos[v] << endl;
	cerr << "heavy " << heavy[v] << endl;

	for(int i=0; i < (int)children[v].size(); ++i) {
		dfs_printtree(children[v][i]);
	}
}




void dfs_cti(int v, int ccti) {
	cti[v] = ccti;
	for(int i=0; i < (int)children[v].size(); ++i) {
		dfs_cti(children[v][i], ccti);
	}
}

struct query {
	int type;
	int x;
	int y;
	int f;
	int k;
	vi t;
};


int main() {


	ios::sync_with_stdio(false);
	cin.tie(0);

	int b;
	cin >> n >> b;
	B = b;
	unordered_map<int, int> realidx;
	int cidx = 0;
	children = vvi(MAX_STD, vi());
	roots = vi();

	vector<query> queries;

	for(int i=0; i < n; ++i) {
		query e;
		e.type = 2;
		cin >> e.x >> e.f;
		cin >> e.k;
		e.t = vi(e.k);
		for(int j=0; j < e.k; ++j) cin >> e.t[j];
		queries.push_back(e);
	}
	int q;
	cin >> q;
	for(int i=0; i < q; ++i) {
		query e;
		cin >> e.type;
		if(e.type == 0) {
			cin >> e.x;
		}
		else if(e.type == 1) {
			cin >> e.x >> e.y;
		}
		else {
			cin >> e.x >> e.f;
			cin >> e.k;
			e.t = vi(e.k);
			for(int j=0; j < e.k; ++j) cin >> e.t[j];
		}
		queries.push_back(e);
	}

	for(int i=0; i < n+q; ++i) {
		query e = queries[i];
		if(e.type == 2) {
			int x, f;
			x = e.x;
			f = e.f;

			if(realidx.find(x) == realidx.end()) {
				realidx[x] = cidx;
				cidx++;
			}
			if(realidx.find(f) == realidx.end()) {
				realidx[f] = cidx;
				cidx++;
			}
			x = realidx[x];
			f = realidx[f];
			if(x == f) {
				roots.push_back(x);
			}
			else {
				children[f].push_back(x);
			}
		}
		else if(e.type == 1) {
			if(realidx.find(e.x) == realidx.end()) {
				realidx[e.x] = cidx;
				cidx++;
			}
			if(realidx.find(e.y) == realidx.end()) {
				realidx[e.y] = cidx;
				cidx++;
			}
		}
	}

	n_trees = roots.size();
	n_nodes = cidx;
	cti = vi(n_nodes);
	for(int i=0; i < n_trees; ++i) {
		dfs_cti(roots[i], i);
	}


	parent = vector<int>(n_nodes);
    depth = vector<int>(n_nodes);
    heavy = vector<int>(n_nodes, -1);
    head = vector<int>(n_nodes);
    pos = vector<int>(n_nodes);
    cur_pos = 0;

    for(int i=0; i < n_trees; ++i) {
    	dfs(roots[i], children);
    	decompose(roots[i], roots[i], children);
    }

   // st_col = vvi(b, vi(4*n_nodes, 0));
    st = vi(4*n_nodes, 0);

    /*
    //DEBUG_BS

    for(auto x : realidx) {
    	cerr << x.first << " -> " << x.second << endl;
    }
    for(int i=0; i < n_trees; ++i) {
    	dfs_printtree(roots[i]);
    }


    //END_DEBUG_BS
	*/

    for(int i=0; i < n+q; ++i) {

    	//if(i > 150000) return 0;

    	query e = queries[i];
    	if(e.type == 0) {
    		update(1, 0, n_nodes-1, pos[realidx[e.x]], 0);
    	}
    	else if(e.type == 2) {
    		int topics = (1<<b);
    		for(int j=0; j < (int)e.t.size(); ++j) {
    			topics |= (1<<(e.t[j]-1));
    		}
    		
    		update(1, 0, n_nodes-1, pos[realidx[e.x]], topics);
    		
    	}
    	else {
    		int x = realidx[e.x];
    		int y = realidx[e.y];
    		if(cti[x] == cti[y]) {
    			cout << ans_query(x, y) << '\n';
    		}
    		else {
    			cout << -1 << '\n';
    		}
    	}
    }

}