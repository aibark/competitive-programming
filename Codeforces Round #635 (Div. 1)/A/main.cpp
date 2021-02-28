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

int n, k, d[N], dp[N], c[N], p[N];
vector <int> e, g[N];
ll ans;

void dfs(int v, int pr){
	p[v] = pr;
	for(int to : g[v])
		if(to != pr){
			d[to] = d[v] + 1;
			dfs(to, v);
			dp[v] += dp[to] + 1;
			c[v]++;
		}
	e.pb(d[v] - dp[v]);
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

	dfs(1, 0);

	sort(all(e));
	reverse(all(e));
	for(int i = 0; i < k; ++i)
		ans += e[i];

	cout << ans;

	return 0;
}