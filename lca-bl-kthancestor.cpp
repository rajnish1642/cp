//https://codeforces.com/gym/102694/problem/C
#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define mod 1000000007
#define endl "\n"
#define all(x) (x).begin(),(x).end()
#define gg(...) [](const auto&...x){ char c='='; cerr<<#__VA_ARGS__<<" "; ((cerr<<exchange(c,',')<<" "<<x),...); cerr<<endl; }(__VA_ARGS__);

int n;
vector<vector<int>>adj(300001);
int sparse_table[300001][20];
int level[300001];
void dfs(int current, int parent){

	sparse_table[current][0] = parent;
	for (auto child : adj[current]){
		if(child != parent){
			level[child] = level[current]+1;
			dfs(child,current);
		}
	}
}

void init(){
	dfs(1,-1);

	for(int j = 1; j < 20; j++){
		for (int i = 1; i <= n;i++){
			if(sparse_table[i][j-1] != -1)
				sparse_table[i][j] = sparse_table[sparse_table[i][j-1]][j-1];
		}
	}

}

int lca(int a, int b){
	if(level[a] < level[b]){
		swap(a,b);
	}
	int d = level[a] - level[b];
	// cout << d << " ";
	while(d > 0){
		int i = log2(d);
		a = sparse_table[a][i];
		d -= (1<<i);
	}
	if(a == b){
		return a;
	}

	for (int i = 19; i >=0 ;i--){
		if(sparse_table[a][i] != -1 && (sparse_table[a][i] != sparse_table[b][i])){
			a = sparse_table[a][i], b = sparse_table[b][i];
		}
	}
	return sparse_table[a][0];
}
int kthparent(int a, int k){
	while(k>0){
		int i = log2(k);
		a = sparse_table[a][i];
		k -= (1<<i);
	}
	return a;
}
void solve()
{
	cin >> n;
	int a,b;
	for (int i = 0 ; i < n-1;i++){
		cin >> a >> b;
		adj[a].push_back(b);
		adj[b].push_back(a);
	}
	memset(sparse_table,-1,sizeof(sparse_table));
	init();

	int c;
	int q;
	cin >> q;
	while(q--){
		cin >> a >> b >> c;
		int x = lca(a,b);
		int dist = level[a] + level[b] - 2*level[x];
		// cout << x << "  ";
		if(dist <= c){
			cout << b;
		}
		else{
			int dist_a_lca = level[a] - level[x];
			int dist_b_lca = level[b] - level[x];
			if(dist_a_lca <= c){
				cout << kthparent(b,dist-c);
			}
			else{
				cout << kthparent(a,c);
			}


		}
		cout << endl;
	
	}




}


int32_t main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	solve();


	cerr << "time taken : " << (float)clock() / CLOCKS_PER_SEC << " secs" << endl;
	return 0;
}

