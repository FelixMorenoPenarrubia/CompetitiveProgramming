#include<bits/stdc++.h>

#define DONE ((int)els.size() >= n-1)

using namespace std;

typedef vector<int> vi;
typedef vector<vi> vvi;
typedef long long ll;
typedef pair<int, int> ii;
typedef vector<ii> vii;

int popcount(int x) {
	int r = 0;
	while(x > 0) {
		r += x&1;
		x >>= 1;
	}
	return r;
}


vi dsu;
vvi al;
vi perm;
vi b;
int weight;
int currcc;
vi vcc;
vi ccsize;
vi a;

int findSet(int x) {
	if(x != dsu[x]) dsu[x] = findSet(dsu[x]);
	return dsu[x];
}

void unionSet(int x, int y) {
	dsu[findSet(x)] = findSet(y);
}

void dfs_cc(int v, int p) {
	vcc[v] = currcc;
	ccsize[currcc]++;
	for(int i=0; i < (int)al[v].size(); ++i) {
		if(al[v][i] != p) dfs_cc(al[v][i], v);
	}
}

void dfs(int v, int p) {

	if(p != -1) {
		weight += popcount(a[v]^a[p]);
	}
	perm.push_back(v);
	b.push_back(p);
	for(int i=0; i < (int)al[v].size(); ++i) {
		if(al[v][i] != p) dfs(al[v][i], v);
	}
}

int main() {

	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int T;
	cin >> T;
	while(T--) {
		int n;
		cin >> n;
		a = vi(n);
		for(int i=0; i < n; ++i) {
			cin >> a[i];
		}

		vii els;

		if(n <= 1000) {
			vector<vii> el(20);
			for(int i=0; i < n; ++i) {
				for(int j=i+1; j < n; ++j) {
					el[popcount(a[i]^a[j])].emplace_back(i, j);
				}
			}

			dsu = vi(n);
			for(int i=0; i < n; ++i) dsu[i] = i;

			for(int d=0; d < 20; ++d) {
				for(int k=0; k < (int)el[d].size(); ++k) {
					int i = el[d][k].first;
					int j = el[d][k].second;
					if(findSet(i) != findSet(j)) {
						els.emplace_back(i, j);
						unionSet(i, j);
					}
				}
			}	
		}
		else {
			dsu = vi(n);
			for(int i=0; i < n; ++i) dsu[i] = i;

			vi idx(3e5);
			vvi idx_rep(3e5);
			for(int i=0; i < n; ++i) {
				idx[a[i]] = i+1;
				idx_rep[a[i]].push_back(i);
			}

			for(int i=0; i < 3e5; ++i) {
				for(int j=1; j < (int)idx_rep[i].size(); ++j) {
					unionSet(idx_rep[i][0], idx_rep[i][j]);
					els.emplace_back(idx_rep[i][0], idx_rep[i][j]);
				}
			}



			for(int i=0; i < n && not DONE; ++i) {
				for(int k1=0; k1 < 18; ++k1) {
					int res = a[i]^(1<<k1);
					if(idx[res]) {
						int j = idx[res]-1;
						if(findSet(i) != findSet(j)) {
							unionSet(i, j);
							els.emplace_back(i, j);
						}
					}
				}
			}
			for(int i=0; i < n && not DONE; ++i) {
				for(int k1=0; k1 < 18; ++k1) {
					for (int k2=k1+1; k2 < 18; ++k2) {
						int res = a[i]^(1<<k1)^(1<<k2);
						if(idx[res]) {
							int j = idx[res]-1;
							if(findSet(i) != findSet(j)) {
								unionSet(i, j);
								els.emplace_back(i, j);
							}
						}
					}
				}
			}

			for(int i=0; i < n && not DONE; ++i) {
				for(int k1=0; k1 < 18; ++k1) {
					for (int k2=k1+1; k2 < 18; ++k2) {
						for(int k3=k2+1; k3 < 18; ++k3) {
							int res = a[i]^(1<<k1)^(1<<k2)^(1<<k3);
							if(idx[res]) {
								int j = idx[res]-1;
								if(findSet(i) != findSet(j)) {
									unionSet(i, j);
									els.emplace_back(i, j);
								}
							}
						}
					}
				}
			}
			for(int i=0; i < n && not DONE; ++i) {
				for(int k1=0; k1 < 18; ++k1) {
					for (int k2=k1+1; k2 < 18; ++k2) {
						for(int k3=k2+1; k3 < 18; ++k3) {
							for(int k4=k3+1; k4 < 18; ++k4) {
								int res = a[i]^(1<<k1)^(1<<k2)^(1<<k3)^(1<<k4);
								if(idx[res]) {
									int j = idx[res]-1;
									if(findSet(i) != findSet(j)) {
										unionSet(i, j);
										els.emplace_back(i, j);
									}
								}
							}
						}
					}
				}
			}
			/*
			for(int i=0; i < n && not DONE; ++i) {
				for(int k1=0; k1 < 18; ++k1) {
					for (int k2=k1+1; k2 < 18; ++k2) {
						for(int k3=k2+1; k3 < 18; ++k3) {
							for(int k4=k3+1; k4 < 18; ++k4) {
								for(int k5=k4+1; k5 < 18; ++k5) {
									int res = a[i]^(1<<k1)^(1<<k2)^(1<<k3)^(1<<k4)^(1<<k5);
									if(idx[res]) {
										int j = idx[res]-1;
										if(findSet(i) != findSet(j)) {
											unionSet(i, j);
											els.emplace_back(i, j);
										}
									}
								}
							}
						}
					}
				}
			}
			
			for(int i=0; i < n && not DONE; ++i) {
				for(int k1=0; k1 < 18; ++k1) {
					for (int k2=k1+1; k2 < 18; ++k2) {
						for(int k3=k2+1; k3 < 18; ++k3) {
							for(int k4=k3+1; k4 < 18; ++k4) {
								for(int k5=k4+1; k5 < 18; ++k5) {
									for(int k6=k5+1; k6 < 18; ++k6) {
										int res = a[i]^(1<<k1)^(1<<k2)^(1<<k3)^(1<<k4)^(1<<k5)^(1<<k6);
										if(idx[res]) {
											int j = idx[res]-1;
											if(findSet(i) != findSet(j)) {
												unionSet(i, j);
												els.emplace_back(i, j);
											}
										}
									}
								}
							}
						}
					}
				}
			}*/

			

			currcc = 1;
			vcc = vi(n);
			ccsize = vi(1);

			al = vvi(n);
			for(int i=0; i < (int)els.size(); ++i) {
				int x = els[i].first;
				int y = els[i].second;
				al[x].push_back(y);
				al[y].push_back(x);
			}
			for(int i=0; i < n; ++i) {
				if(vcc[i] == 0) {
					ccsize.push_back(0);
					dfs_cc(i, -1);
					currcc++;
				} 
			}

			int maxsz = 0;
			for(int i=1; i < currcc; ++i) {
				maxsz = max(maxsz, ccsize[i]);
			}
			if(DONE) {

			}
			else if(n-maxsz <= 200) {
				vector<vii> el(20);
				
				for(int i=0; i < n; ++i) {
					//if(ccsize[vcc[i]] <= 200) {
						for(int j=0; j < n; ++j) {
							el[popcount(a[i]^a[j])].emplace_back(i, j);
						}
					//}
				}

				for(int d=0; d < 20; ++d) {
					for(int k=0; k < (int)el[d].size(); ++k) {
						int i = el[d][k].first;
						int j = el[d][k].second;
						if(findSet(i) != findSet(j)) {
							els.emplace_back(i, j);
							unionSet(i, j);
						}
					}
				}
			}
			else if (currcc <= 200) {
				
				vector<vii> el(20);
				
				for(int i=0; i < n; ++i) {
					if(ccsize[vcc[i]] <= 200) {
						for(int j=0; j < n; ++j) {
							if(vcc[j] != vcc[i]) el[popcount(a[i]^a[j])].emplace_back(i, j);
						}
						ccsize[vcc[i]] = 201;
					}
				}

				for(int d=0; d < 20; ++d) {
					for(int k=0; k < (int)el[d].size(); ++k) {
						int i = el[d][k].first;
						int j = el[d][k].second;
						if(findSet(i) != findSet(j)) {
							els.emplace_back(i, j);
							unionSet(i, j);
						}
					}
				}
			}
		/*	else {
				//exit(1);
			}*/	
		}

		al = vvi(n);
		for(int i=0; i < n-1; ++i) {
			int x = els[i].first;
			int y = els[i].second;
			al[x].push_back(y);
			al[y].push_back(x);
		}

		perm = vi();
		b = vi();
		weight = 0;
		dfs(0, -1);
		cout << weight << endl;
		for(int i=0; i < n; ++i) cout << perm[i]+1 << " ";
		cout << endl;
		cout << "1 ";
		for(int i=1; i < n; ++i) cout << b[i]+1 << " ";
		cout << endl;
	}
}