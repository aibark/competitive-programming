#include <stdio.h>
#include <bits/stdc++.h>

#define f first
#define s second
#define pb push_back
#define mp make_pair
#define all(x) x.begin(), x.end()

typedef long long ll;

using namespace std;

const int N = (int)5e5 + 123, mod = (int)1e9 + 7, inf = (int)1e9, bl = 2000;
const ll INF = (ll)1e18;

struct query{
	int t, i;
}q[N];

int n, m, Q, a[N], p[N], sz[N], pa[N], sza[N], del[N], xa[N], ya[N], used[N], ustim, curtim, ans, ansnum;
pair <int, int> b[N];
vector <pair <int, int> > g[N];
vector <int> c[N];

int get(int x){
	if(x == p[x])
		return x;
	return p[x] = get(p[x]);
}

void merge(int x, int y){
	x = get(x);
	y = get(y);
	if(x == y)
		return;
	if(sz[x] < sz[y])
		swap(x, y);
	p[y] = x;
	sz[x] += sz[y];
}

void dfs(int v){
	used[v] = ustim;
	if(c[v].size() > 0 && c[v].back() > ans)
		ansnum = v, ans = c[v].back();
	for(int i = 0; i < (int)g[v].size(); ++i){
		if(g[v][i].s <= curtim || used[g[v][i].f] == ustim)
			continue;
		dfs(g[v][i].f);
	}
}

int main(){
	cin.tie(0);
	cout.tie(0);
	ios_base::sync_with_stdio(NULL);

	cin >> n >> m >> Q;

	for(int i = 1; i <= n; ++i)
		cin >> a[i], b[i].f = a[i], b[i].s = i;
	sort(b + 1, b + n + 1);
	
	for(int i = 1; i <= m; ++i)
		cin >> xa[i] >> ya[i];

	for(int i = 1; i <= Q; ++i){
		cin >> q[i].t >> q[i].i;
		if(q[i].t == 2)
			del[q[i].i] = 1;
	}

	for(int i = 1; i <= n; ++i)
		p[i] = i, sz[i] = 1;

	for(int i = 1; i <= m; ++i)
		if(!del[i]){
			merge(xa[i], ya[i]);
		}

	for(int i = 1; i <= n; ++i)
		pa[i] = get(i), sza[i] = sz[i];

	for(int l = 1; l <= Q; ){
		int r = l, cnt = (q[l].t == 2);
		while(r < Q && cnt <= bl){
			r++;
			cnt += (q[r].t == 2);
		}
		for(int i = 1; i <= n; ++i)
			p[i] = pa[i], sz[i] = sza[i];
		for(int i = Q; i > r; --i)
			if(q[i].t == 2)
				merge(xa[q[i].i], ya[q[i].i]);
		for(int i = 1; i <= n; ++i)
			p[i] = get(p[i]);
		for(int i = l; i <= r; ++i)
			if(q[i].t == 2)
				g[p[xa[q[i].i]]].pb(mp(p[ya[q[i].i]], i)), g[p[ya[q[i].i]]].pb(mp(p[xa[q[i].i]], i));
		for(int i = 1; i <= n; ++i){
			c[p[b[i].s]].pb(a[b[i].s]);
		}
		for(int i = l; i <= r; ++i)
			if(q[i].t == 1){
				ustim++;
				curtim = i;
				ansnum = 0, ans = 0;
				dfs(p[q[i].i]);
				cout << ans << endl;
				if(ansnum > 0)
					c[ansnum].pop_back();
			}
		for(int i = 1; i <= n; ++i)
			c[i].clear(), g[i].clear();
		cout << l << " " << r << endl;
		l = r + 1;
	}

	return 0;
}