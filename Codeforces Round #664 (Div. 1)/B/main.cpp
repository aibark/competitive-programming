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

int n, m, ans, a[10], k;
vector <pair <int, int> > g[N], s[N];
bool ok[10][10];
int used[10][10][10][10];

void rec(int x){
	if(x == k){
		bool OK = 1;
		for(int i = 1; i <= k; ++i)
		for(int j = i + 1; j <= k; ++j)
			if(used[i][a[i]][j][a[j]])
				OK = 0;
		for(int i = 1; i <= k; ++i)
			if(ok[i][a[i]])
				OK = 0;
		ans += OK;
		return;
	}
	for(int i = 1; i <= x + 1; ++i){
		a[x + 1] = i;
		rec(x + 1);
	}
}

int main(){
	cin.tie(0);
	cout.tie(0);
	ios_base::sync_with_stdio(NULL);

	cin >> n >> m >> k;

	for(int i = 1; i <= m; ++i){
		int x, y, z;
		cin >> x >> y >> z;
		g[x].pb(mp(z, y));
	}
	for(int i = 1; i <= n; ++i){
		sort(all(g[i]));
		for(int j = 0; j < (int)g[i].size(); ++j)
			s[g[i][j].s].pb(mp(g[i].size(), j + 1));
	}
	for(int i = 1; i <= n; ++i){
		sort(all(s[i]));
		vector <pair <int, int> > u;
		if(s[i].size() == 0)
			continue;
		u.pb(s[i][0]);
		for(int j = 1; j < (int)s[i].size(); ++j)
			if(s[i][j] == s[i][j - 1])
				ok[s[i][j].f][s[i][j].s] = 1;
			else u.pb(s[i][j]);
		for(int x = 0; x < (int)u.size(); ++x)
		for(int y = 0; y < (int)u.size(); ++y)
			if(x != y)
				used[u[x].f][u[x].s][u[y].f][u[y].s] = 1;
	}

	rec(0);
	cout << ans;

	return 0;
}