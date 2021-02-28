#include <stdio.h>
#include <bits/stdc++.h>

#define f first
#define s second
#define pb push_back
#define mp make_pair
#define all(x) x.begin(), x.end()

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

const int N = (int)2e5 + 123, mod = (int)998244353, inf = (int)1e9;
const ll INF = (ll)1e18;

ll bp(ll x, ll y){
	ll z = 1;
	while(y){
		if(y & 1)
			z = z * x % mod;
		x = x * x % mod;
		y >>= 1;
	}
	return z;
}

int n, m, dp[2][21][N];
pair <int, int> dp1[2][N];
set <pair <pii, pii> > st;
vector <pair <int, int> > g[N];
queue <pair <int, int> > q;

int main(){
	cin.tie(0);
	cout.tie(0);
	ios_base::sync_with_stdio(NULL);
	
	cin >> n >> m;
	for(int i = 1; i <= m; ++i){
		int x, y;
		cin >> x >> y;
		g[x].pb(mp(y, 0));
		g[y].pb(mp(x, 1));
	}
	for(int i = 0; i <= 20; ++i)
	for(int j = 1; j <= n; ++j)
		dp[0][i][j] = inf, dp[1][i][j] = inf;

	dp[0][0][1] = 0;
	q.push(mp(0, 1));
	while(!q.empty()){
		int x = q.front().f % 2, y = q.front().f / 2, v = q.front().s;
		q.pop();
		for(auto i : g[v]){
			int to = i.f, z = i.s;
			int xto, yto;
			if(z != x && y == 20)
				continue;
			if(z == x)
				xto = x, yto = y;
			else xto = 1 - x, yto = y + 1;
			if(dp[xto][yto][to] > dp[x][y][v] + 1){
				dp[xto][yto][to] = dp[x][y][v] + 1;
				q.push(mp(yto * 2 + xto, to));
			}
		}
	}
	int ans = (int)1e9;
	for(int i = 0; i <= 20; ++i)
		if(min(dp[0][i][n], dp[1][i][n]) != inf)
			ans = min(ans, min(dp[0][i][n], dp[1][i][n]) + (1 << i) - 1);

	if(ans != (int)1e9){
		cout << ans << endl;
		return 0;
	}

	for(int i = 1; i <= n; ++i)
		dp1[0][i] = dp1[1][i] = mp((int)1e9, 0);
	dp1[0][1] = mp(0, 0);
	st.insert(mp(dp1[0][1], mp(0, 1)));
	while(!st.empty()){
		pair <int, int> dp2 = (*st.begin()).f;
		int x = (*st.begin()).s.f, v = (*st.begin()).s.s;
		st.erase(st.begin());
		if(dp2 != dp1[x][v])
			continue;
		for(auto i : g[v]){
		    int to = i.f, z = i.s, xto;
		    pair <int, int> dpto = dp1[x][v];
		    if(z == x)
		    	xto = x, dpto.s++;
			else xto = 1 - x, dpto.f++, dpto.s++;
			if(dp1[xto][to] > dpto){
				dp1[xto][to] = dpto;
				st.insert(mp(dp1[xto][to], mp(xto, to)));
			}
		}
	}   	
	pair <int, int> ansp = min(dp1[0][n], dp1[1][n]);
	cout << (bp(2, ansp.f) - 1LL + mod + (ll)ansp.s) % mod;

	return 0;
}             