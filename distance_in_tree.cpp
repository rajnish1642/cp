//https://codeforces.com/contest/161/problem/D
// realy good question on dp on tree
#include <bits/stdc++.h>
using namespace std;
#define int long long int
#define mod 1000000007
#define endl "\n"
#define all(x) (x).begin(),(x).end()
#define gg(...) [](const auto&...x){ char c='='; cerr<<#__VA_ARGS__<<" "; ((cerr<<exchange(c,',')<<" "<<x),...); cerr<<endl; }(__VA_ARGS__);
int n,k;
vector<vector<int>>adj(50001);
//dp[i][x] == Numver of node at distace x from ith node
//dp[i][x] = dp[child[i]][x-1]

int dp1[50001][501];
int dp2[50001][501];
void dfs(int current, int par){

	dp1[current][0] = 1;
	for (auto child : adj[current]){
		if(child != par){
			dfs(child,current);

			for (int i = 1; i <= k; i++){
				dp1[current][i] += dp1[child][i-1];
			}
		}
	}
}

void dfs2(int current, int parent){
	for (int i = 0 ; i <= k ; i++){
				dp2[current][i] = dp1[current][i];
		}

	if(parent != 0){
		dp2[current][1] += dp2[parent][0];
		for (int i = 2; i <= k; i++){
			dp2[current][i] += (dp2[parent][i-1] - dp1[current][i-2]);
		}
	}

	for (auto child : adj[current]){
		if(child != parent){
			dfs2(child, current);
		}
	}
}


void solve()
{
	cin >> n >> k;
	for (int i = 0; i < n-1; i++){
		int a,b;
		cin >> a >> b;
		adj[a].push_back(b);
		adj[b].push_back(a);
	}

	dfs(1,0);

	// for (int i = 1; i <= n;i++){
	// 	for (int j = 0 ; j <= k ;j++){
	// 		cout << dp1[i][j] << " ";
	// 	}
	// 	cout << endl;
	// }
	// cout << endl;

	dfs2(1,0);

	// for (int i = 1; i <= n;i++){
	// 	for (int j = 0 ; j <= k ;j++){
	// 		cout << dp2[i][j] << " ";
	// 	}
	// 	cout << endl;
	// }

	int ans =0 ;
	for (int i = 1; i <= n; i++){
		ans += dp2[i][k];
	}
	cout << ans/2;
}


int32_t main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	solve();


	cerr << "time taken : " << (float)clock() / CLOCKS_PER_SEC << " secs" << endl;
	return 0;
}



