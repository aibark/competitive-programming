#include <stdio.h>
#include <bits/stdc++.h>

#define f first
#define s second
#define pb push_back
#define mp make_pair
#define all(x) x.begin(), x.end()

typedef long long ll;

using namespace std;

const int N = (int)3e5 + 123, mod = (int)1e9 + 7, inf = (int)1e9;
const ll INF = (ll)1e18;

void dfs(int v, int pr = -1){
	dp[v] = 1;
	for(int to : g[v]){
		if(to == pr)
			continue;
		dfs(to, v);
		dp[v] += dp[to];
	}
	ans += min(dp[v], n - dp[v]);
} 

int main(){
	cin.tie(0);
	cout.tie(0);
	ios_base::sync_with_stdio(NULL);

	cin >> n >> k;
	for(int i = 1; i < n; ++i){
		int x, y;
		cin >> x >> y;
		g[x].pb(y);
		g[y].pb(x);
	}
	if(n == 2){
		if(k == 1)
			cout << "YES" << endl << 1 << " " << 2 << endl;
		else cout << "NO";
		return 0;
	}
	int root = 1;
	while(g[root].size() == 1)
		root++;

	dfs(root);

	return 0;
}