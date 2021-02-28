#include <stdio.h>
#include <bits/stdc++.h>

#define f first
#define s second
#define pb push_back
#define mp make_pair
#define all(x) x.begin(), x.end()

typedef long long ll;

using namespace std;

const int N = (int)1e6 + 123, mod = (int)1e9 + 7, inf = (int)1e9, M = (int)1e6;
const ll INF = (ll)1e18;

struct item{
	int x, y, z;
}e[N];

int n, m, p;
vector <int> g[N], gr[N];
ll a[N], ca[N], cb[N], ans = -(ll)1e10, mn[4 * N], add[4 * N];

void push(int v){
	mn[v + v] += add[v];
	mn[v + v + 1] += add[v];
	add[v + v] += add[v];
	add[v + v + 1] += add[v];
	add[v] = 0;
}

void upd(int v, int tl, int tr, int l, int r, ll x){
	if(r < tl || tr < l)
		return;
	if(l <= tl && tr <= r){
		mn[v] += x;
		add[v] += x;
		return;
	}
	int tm = (tl + tr) >> 1;
	push(v);
	upd(v + v, tl, tm, l, r, x);
	upd(v + v + 1, tm + 1, tr, l, r, x);
	mn[v] = max(mn[v + v], mn[v + v + 1]);
}

int main(){
	cin.tie(0);
	cout.tie(0);
	ios_base::sync_with_stdio(NULL);

	cin >> n >> m >> p;

	for(int i = 1; i <= n; ++i){
		cin >> a[i] >> ca[i];
		g[a[i]].pb(i);
	}

	for(int i = 1; i <= m; ++i){
		int x, y;
		cin >> x >> y;
		if(cb[x])
			cb[x] = min(cb[x], (ll)y);
		else cb[x] = y;
	}
	ll MN = (ll)1e10;
	for(int i = M; i >= 1; --i){
		if(cb[i])
			MN = min(MN, cb[i]);
		upd(1, 1, M, i, i, -MN);
	}

	for(int i = 1; i <= p; ++i){
		cin >> e[i].x >> e[i].y >> e[i].z;
		e[i].x++;
		e[i].y++;
		gr[e[i].x].pb(i);
	}

	for(int i = 1; i <= M; ++i){
		for(int j : gr[i]){
			upd(1, 1, M, e[j].y, M, e[j].z); 
		}
		for(int j : g[i]){
			ans = max(ans, mn[1] - ca[j]);
		}
	}

	cout << ans << endl;
	
	return 0;
}