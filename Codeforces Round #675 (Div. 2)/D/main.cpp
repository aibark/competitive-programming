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

int n, m, sx, sy, fx, fy, d[N], x[N], y[N], k, p[N], xa[N], ya[N];
set <int> zx, zy;                         
queue <int> q;
map <int, int> numx, numy;
vector <pair <int, int> > g[N];

int main(){
	cin.tie(0);
	cout.tie(0);
	ios_base::sync_with_stdio(NULL);

	cin >> n >> m;
	cin >> sx >> sy >> fx >> fy;
	g[0].pb(mp(m + 1, abs(sx - fx) + abs(sy - fy)));
	zx.insert(sx);
	zy.insert(sy);

	for(int i = 1; i <= m; ++i){
		cin >> x[i] >> y[i];
		zx.insert(x[i]);
		zy.insert(y[i]);
	}
	int z = 0;
	for(int i : zx){
		numx[i] = ++z;
		xa[z] = i;
	}
	k = z;
	z = 0;
	for(int i : zy){
		numy[i] = ++z;
	    ya[z] = i;
	}

	k = max(k, z);
	for(int i = 1; i <= m; ++i){
		g[i].pb(mp(m + 1 + numx[x[i]], 0));
		g[i].pb(mp(m + 1 + k + numy[y[i]], 0));
		g[m + 1 + numx[x[i]]].pb(mp(i, 0));
		g[m + 1 + k + numy[y[i]]].pb(mp(i, 0));
		g[i].pb(mp(m + 1, abs(x[i] - fx) + abs(y[i] - fy)));
	}
	g[0].pb(mp(m + 1 + numx[sx], 0));
	g[0].pb(mp(m + 1 + k + numy[sy], 0));

	for(int i = 1; i < k; ++i){
		if(i < zx.size()){
			g[m + 1 + i].pb(mp(m + 1 + i + 1, xa[i + 1] - xa[i]));
			g[m + 1 + i + 1].pb(mp(m + 1 + i, xa[i + 1] - xa[i]));
        }
        if(i < zy.size()){
			g[m + 1 + k + i].pb(mp(m + 1 + k + i + 1, ya[i + 1] - ya[i]));
			g[m + 1 + k + i + 1].pb(mp(m + 1 + k + i, ya[i + 1] - ya[i]));
		}
	}
	for(int i = 1; i <= m + 1 + k + k; ++i)
		d[i] = 2 * inf;

	q.push(0);
	while(!q.empty()){
		int x = q.front();
		q.pop();
		for(auto to : g[x]){
			if(d[to.f] > d[x] + to.s){
				d[to.f] = d[x] + to.s;
				p[to.f] = x;
				q.push(to.f);
			}
		}
	}

	cout << d[m + 1] << endl;

	return 0;
}