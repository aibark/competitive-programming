#include <stdio.h>
#include <bits/stdc++.h>

#define f first
#define s second
#define pb push_back
#define mp make_pair
#define all(x) x.begin(), x.end()

typedef long long ll;

using namespace std;

const int N = (int)5e5 + 123, mod = (int)1e9 + 7, inf = (int)1e9;
const ll INF = (ll)1e18;

ll ans;
bool ok[N], used[N];
int n, m, k, norma, c[N], col[N], comp[N], compn, a[N];
map <pair <int, int>, int> num;
vector <int> g[N], gr[N];
set <int> s[N];
vector <pair <int, int> > gs[N], ga[N];

void dfs(int v){
	for(int to : g[v]){
		if(c[to] != c[v] || col[to])
			continue;
		comp[to] = comp[v];
		col[to] = 3 - col[v];
		dfs(to);
	}
}

void dfs2(int v){
	used[v] = 1;
	for(auto to : ga[v]){
		if(used[to.f])
			continue;
		a[to.f] = (a[v] ^ to.s);
		dfs2(to.f);
	}
}

int main(){
	cin.tie(0);
	cout.tie(0);
	ios_base::sync_with_stdio(NULL);

	cin >> n >> m >> k;
	for(int i = 1; i <= n; ++i)
		cin >> c[i], gr[c[i]].pb(i);

	for(int i = 1; i <= m; ++i){
		int x, y;
		cin >> x >> y;
		if(c[x] > c[y])
			swap(x, y);
		if(c[x] == c[y])
			g[x].pb(y), g[y].pb(x);
		else{
			s[c[x]].insert(c[y]);
			if(!num.count(mp(c[x], c[y])))
				num[mp(c[x], c[y])] = i;
			gs[num[mp(c[x], c[y])]].pb(mp(x, y));
			s[c[y]].insert(c[x]);
		}
	}

	for(int i = 1; i <= k; ++i){
		for(int j : gr[i])
			if(!col[j]){
				col[j] = 1;
				comp[j] = ++compn;
				dfs(j);
			}
		ok[i] = 1;
		for(int j : gr[i])
		for(int to : g[j])
			if(c[to] == c[j] && col[to] == col[j])
				ok[i] = 0;
		norma += ok[i];
		//cout << i << " " << ok[i] << endl;
	}
	for(int i = 1; i <= k; ++i){
		if(!ok[i])
			continue;
		int mynorm = 0;
		for(int j : s[i]){
			if(!ok[j])
				continue;
			//cout << i << " " << j << endl;
			mynorm++;
			bool okok = 1;
			int nu = 0;
			if(i < j)
				nu = num[mp(i, j)];
			else nu = num[mp(j, i)];
			for(auto ij : gs[nu]){                        
				int x = comp[ij.f], y = comp[ij.s], z = (col[ij.f] == col[ij.s]);
				//cout << x << " " << y << " " << z << endl;
				ga[x].pb(mp(y, z));
				ga[y].pb(mp(x, z));
			}
			for(auto ij : gs[nu]){
				int x = comp[ij.f];
				if(!used[x]){
					a[x] = 0;
					dfs2(x);
				}
			}
			for(auto ij : gs[nu]){
				int x = comp[ij.f], y = comp[ij.s], z = (col[ij.f] == col[ij.s]);
				if((a[x] ^ z) != a[y])
					okok = 0;
			}
			//cout << okok << endl;
			ans += okok;
			for(auto ij : gs[nu]){
				int x = comp[ij.f], y = comp[ij.s];
				ga[x].clear(), ga[y].clear(), a[x] = a[y] = 0, used[x] = used[y] = 0;
			} 
		}
		ans += norma - mynorm - 1;
	}

	cout << ans / 2;

	return 0;
}