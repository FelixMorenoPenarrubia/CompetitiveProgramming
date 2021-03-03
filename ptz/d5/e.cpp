#include<bits/stdc++.h>


using namespace std;

typedef vector<int> vi;
typedef vector<vi> vvi;
typedef pair<int, int> ii;
typedef vector<ii> vii;


#define MAXN 501
vector<vector<int> > adj;
int match[MAXN],save[MAXN],vlabel[MAXN],used[MAXN],q[MAXN];
int n; // n global
int up, down;
void rematch(int x, int y){
 int m=match[x]; match[x]=y;
 if (match[m]==x){
  if (vlabel[x]<=n){
   match[m]=vlabel[x];
   rematch(vlabel[x],m);
  } else {
   int a=1+(vlabel[x]-n-1)/n;
   int b=1+(vlabel[x]-n-1)%n;
   rematch(a,b);rematch(b,a);
}}}
void traverse(int x){
 for (int i = 1; i <= n; ++i)save[i]=match[i];
 rematch(x,x);
 for (int i = 1; i <= n; ++i){
  if (match[i]!=save[i])used[i]++;
  match[i]=save[i];
}}
void relabel(int x,int y){
 for (int i = 1; i <= n; ++i)used[i]=0;
 traverse(x);traverse(y);
 for (int i = 1; i <= n; ++i){
  if (used[i]==1&&vlabel[i]<0){
   vlabel[i]=n+x+(y-1)*n;
   q[up++]=i;
}}}
void maxmatching(){
 memset(match,0,n+2);
 for (int i = 1; i <= n; ++i)if (match[i]==0){
  for (int j = 1; j <= n; ++j)vlabel[j]=-1;
  vlabel[i]=0;down=1;up=1;q[up++]=i;
  while (down!=up){
   int x=q[down++];
   for (int p = 0; p < adj[x].size(); ++p){
    int y=adj[x][p];
    if (match[y]==0&&i!=y){
     match[y]=x;rematch(x,y);
     down=up;break;
    }
    if (vlabel[y]>=0){
     relabel(x, y);
     continue;
    }
    if (vlabel[match[y]]<0){
     vlabel[match[y]]=x;
     q[up++]=match[y];
}}}}}

int sn;
vector<vector<int>> g, gt;
vector<bool> visited;
vector<int> order, comp;
vector<bool> assignment;
int bad_num;

void dfs1(int v) {
    visited[v] = true;
    for (int u : g[v]) {
        if (!visited[u])
            dfs1(u);
    }
    order.push_back(v);
}

void dfs2(int v, int cl) {
    comp[v] = cl;
    for (int u : gt[v]) {
        if (comp[u] == -1)
            dfs2(u, cl);
    }
}

bool solve_2SAT() {
    visited.assign(sn, false);
    for (int i = 0; i < sn; ++i) {
        if (!visited[i])
            dfs1(i);
    }

    comp.assign(sn, -1);
    for (int i = 0, j = 0; i < sn; ++i) {
        int v = order[sn - i - 1];
        if (comp[v] == -1)
            dfs2(v, j++);
    }

    assignment.assign(sn / 2, false);
    for (int i = 0; i < sn; i += 2) {
        if (comp[i] == comp[i + 1]) {
        	bad_num = i/2+1;
            return false;
        }
        assignment[i / 2] = comp[i] > comp[i + 1];
    }
    return true;
}

vii el;

void print_ans() {
	int c = 0;
	for(int i=0; i < n; ++i) {
		if(assignment[i]) c++;
	}
	cout << c << "\n";
	for(int i=0; i < n; ++i) {
		if(assignment[i]) cout << i+1 << " ";
	}
	cout << "\n";
}



int main(){

	ios::sync_with_stdio(false);
	cin.tie(NULL);

  int T;
  cin >> T;
  while(T--) {
	  int m;
	  cin >> n >> m; // n global
	  el = vii();
	  adj.clear(); adj.resize(n+1);
	  for (int i = 0; i < m; ++i) {
	    int x, y;
	    cin >> x >> y; // 1 <= x,y <= n
	    adj[x].push_back(y);
	    adj[y].push_back(x);
	    el.emplace_back(x, y);
	  }
	  maxmatching();

	  /*for(int i=1; i <= n; ++i) {
	  	cerr << match[i] << endl;
	  }*/

	  sn = 2*n;
	  g = vvi(sn, vi());
	  gt = vvi(sn, vi());

	  for(int i=0; i < m; ++i) {
	  	int x = el[i].first;
	  	int y = el[i].second;
	  	if(match[x] == y && match[y] == x) {
	  		cerr << "holA " << x << " " << y << endl;
 
	  		g[2*(x-1)].push_back(2*(y-1)+1);
	  		gt[2*(y-1)+1].push_back(2*(x-1));
	  		g[2*(x-1)+1].push_back(2*(y-1));
	  		gt[2*(y-1)].push_back(2*(x-1)+1);
	  	}
	  	else if(match[x] > 0 && match[y] > 0) {
	  		g[2*(x-1)+1].push_back(2*(y-1));
	  		gt[2*(y-1)].push_back(2*(x-1)+1);
	  	}
	  	else if(match[x] > 0) {
	  		g[2*(x-1)+1].push_back(2*(x-1));
	  		gt[2*(x-1)].push_back(2*(x-1)+1);
	  	}
	  	else if(match[y] > 0) {
	  		g[2*(y-1)+1].push_back(2*(y-1));
	  		gt[2*(y-1)].push_back(2*(y-1)+1);
	  	}
	  	else {
	  		cerr << "DAMMIT" << endl;
	  		return 1;
	  	}
	  	swap(x, y);
	  	if(match[x] == y && match[y] == x) {
	  		cerr << "holA " << x << " " << y << endl;
 
	  		g[2*(x-1)].push_back(2*(y-1)+1);
	  		gt[2*(y-1)+1].push_back(2*(x-1));
	  		g[2*(x-1)+1].push_back(2*(y-1));
	  		gt[2*(y-1)].push_back(2*(x-1)+1);
	  	}
	  	else if(match[x] > 0 && match[y] > 0) {
	  		g[2*(x-1)+1].push_back(2*(y-1));
	  		gt[2*(y-1)].push_back(2*(x-1)+1);
	  	}
	  	else if(match[x] > 0) {
	  		g[2*(x-1)+1].push_back(2*(x-1));
	  		gt[2*(x-1)].push_back(2*(x-1)+1);
	  	}
	  	else if(match[y] > 0) {
	  		g[2*(y-1)+1].push_back(2*(y-1));
	  		gt[2*(y-1)].push_back(2*(y-1)+1);
	  	}
	  	else {
	  		cerr << "DAMMIT" << endl;
	  		return 1;
	  	}
	  }


	  if(solve_2SAT()) {
	  	print_ans();
	  }
	  else {

	  	cerr << "second round " << bad_num << endl;

		  	g = vvi(sn, vi());
		  gt = vvi(sn, vi());

		  for(int i=0; i < m; ++i) {
		  	int x = el[i].first;
		  	int y = el[i].second;
		  	if(match[x] == y && match[y] == x) {
		  		if(x == bad_num || y == bad_num) {

		  			cerr << "holi" << endl;

		  			g[2*(x-1)+1].push_back(2*(x-1));
		  			gt[2*(x-1)].push_back(2*(x-1)+1);
		  			g[2*(y-1)+1].push_back(2*(y-1));
		  			gt[2*(y-1)].push_back(2*(y-1)+1);
		  		}
		  		else {

		  			cerr << "hola" << endl;

			  		g[2*(x-1)].push_back(2*(y-1)+1);
			  		gt[2*(y-1)+1].push_back(2*(x-1));
			  		g[2*(x-1)+1].push_back(2*(y-1));
			  		gt[2*(y-1)].push_back(2*(x-1)+1);
			  	}
		  	}
		  	else if(match[x] > 0 && match[y] > 0) {

		  		cerr << "xd?" << endl;

		  		g[2*(x-1)+1].push_back(2*(y-1));
		  		gt[2*(y-1)].push_back(2*(x-1)+1);
		  	}
		  	else if(match[x] > 0) {

		  		cerr << "holu" << endl;

		  		g[2*(x-1)+1].push_back(2*(x-1));
		  		gt[2*(x-1)].push_back(2*(x-1)+1);
		  	}
		  	else if(match[y] > 0) {
		  		g[2*(y-1)+1].push_back(2*(y-1));
		  		gt[2*(y-1)].push_back(2*(y-1)+1);
		  	}
		  	else {
		  		cerr << "DAMMIT" << endl;
		  		return 1;
		  	}
		  	swap(x, y);

		  	if(match[x] == y && match[y] == x) {
		  		if(x == bad_num || y == bad_num) {
		  		/*	g[2*(x-1)+1].push_back(2*(x-1));
		  			gt[2*(x-1)].push_back(2*(x-1)+1);
		  			g[2*(y-1)+1].push_back(2*(y-1));
		  			gt[2*(y-1)].push_back(2*(y-1)+1);*/
		  		}
		  		else {

		  			cerr << "hola2" << endl;

			  		g[2*(x-1)].push_back(2*(y-1)+1);
			  		gt[2*(y-1)+1].push_back(2*(x-1));
			  		g[2*(x-1)+1].push_back(2*(y-1));
			  		gt[2*(y-1)].push_back(2*(x-1)+1);
			  	}
		  	}
		  	else if(match[x] > 0 && match[y] > 0) {
		  		g[2*(x-1)+1].push_back(2*(y-1));
		  		gt[2*(y-1)].push_back(2*(x-1)+1);
		  	}
		  	else if(match[x] > 0) {
		  		g[2*(x-1)+1].push_back(2*(x-1));
		  		gt[2*(x-1)].push_back(2*(x-1)+1);
		  	}
		  	else if(match[y] > 0) {
		  		g[2*(y-1)+1].push_back(2*(y-1));
		  		gt[2*(y-1)].push_back(2*(y-1)+1);
		  	}
		  	else {
		  		cerr << "DAMMIT" << endl;
		  		return 1;
		  	}
		  }
		   if(solve_2SAT()) {
		  	print_ans();
		  }
		  else {
		  	cout << "not smol\n";
		  	cerr << bad_num << endl;
		  }
	  }
	 
	  

	}
}


