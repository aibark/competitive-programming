#include <stdio.h>
#include <bits/stdc++.h>

#define f first
#define s second
#define pb push_back
#define mp make_pair
#define all(x) x.begin(), x.end()

typedef long long ll;

using namespace std;

const int N = (int)1020, mod = (int)1e9 + 7, inf = (int)1e9;
const ll INF = (ll)1e18;

int n, m, k, d[N * N + 41], ans, Q;
short dp[41][N][N];
deque <int> q;
vector <pair <int, int> > g[N * N + 41];
vector <int> v[41];

int num(int x, int y){
	return (x - 1) * m + y - 1;
}

int main(){
	scanf("%d%d%d", &n, &m, &k);

	for(int i = 1; i <= n; ++i)
	for(int j = 1; j <= m; ++j){
		int x;
		scanf("%d", &x);
		v[x].pb(num(i, j));
		if(i < n)
			g[num(i, j)].pb(mp(num(i + 1, j), 1));
		if(i > 1)
			g[num(i, j)].pb(mp(num(i - 1, j), 1));
		if(j < m)
			g[num(i, j)].pb(mp(num(i, j + 1), 1));	
		if(j > 1)
			g[num(i, j)].pb(mp(num(i, j - 1), 1));
	}

	for(int i = 1; i <= k; ++i)
	for(int j : v[i]){
		g[j].pb(mp(n * m + i, 0));
		g[n * m + i].pb(mp(j, 1));
	}	

	for(int i = 1; i <= k; ++i){
		for(int j = 0; j <= n * m + k; ++j)
			d[j] = 5000;
		d[n * m + i] = 0;
		q.push_back(n * m + i);
		while(!q.empty()){
			int x = q.front();
			q.pop_front();
			for(auto to : g[x]){
				if(d[to.f] > d[x] + to.s){
					d[to.f] = d[x] + to.s;
					if(to.s == 0)
						q.push_front(to.f);
					else q.push_back(to.f);
				}
			}
		}
		for(int x = 1; x <= n; ++x)
		for(int y = 1; y <= m; ++y)
			dp[i][x][y] = d[num(x, y)];
	}

	cin >> Q;

	while(Q--){
		int xa, ya, xb, yb;
		cin >> xa >> ya >> xb >> yb;
		ans = abs(xa - xb) + abs(ya - yb);
		for(int i = 1; i <= k; ++i)
			ans = min(ans, (int)dp[i][xa][ya] + (int)dp[i][xb][yb] - 1);
		cout << ans << endl;
	}

	return 0;
}