#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define mod 1000000007
#define endl "\n"
#define all(x) (x).begin(),(x).end()
#define gg(...) [](const auto&...x){ char c='='; cerr<<#__VA_ARGS__<<" "; ((cerr<<exchange(c,',')<<" "<<x),...); cerr<<endl; }(__VA_ARGS__);

vector<int>children(100001);
vector<int>subtree(100001);
vector<int>leafnode(100001);
// int count;
void dfs(vector<vector<int>>adj, int currentNode, int parent){
	int cnt = 0;
	subtree[currentNode] = 1;
	

	for (auto child : adj[currentNode]){
		if(child != parent){
			cnt++;
			dfs(adj, child, currentNode);
			subtree[currentNode] += subtree[child];
			leafnode[currentNode] += leafnode[child];
		}
		if(adj[currentNode].size() == 1 && child == parent){
			leafnode[currentNode] = 1;
		}
		
	}
	children[currentNode] = cnt;
 }



void solve()
{
	int n;
	cin >> n;
	vector<vector<int>>adj(n+1);
	int a,b;
	for (int i = 0 ; i < n-1;i++){
		cin >> a >> b;
		adj[a].push_back(b);
		adj[b].push_back(a);
	}

	dfs(adj,1,-1);
	for(int i = 1; i <= n;i++){
		cout << children[i] << " ";
	}
	cout << endl;
	for (int i = 1; i <= n;i++){
		cout << subtree[i] << " ";
	}
	cout << endl;
	for (int i = 1; i <= n;i++){
		cout << leafnode[i] << " ";
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
