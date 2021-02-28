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

void dfs(int v){
	used[v] = 1;
	if(g[0][x] && !used[g[0][x]])
		dfs(g[0][x]);
	if(g[1][x] && !used[g[1][x]])
		dfs(g[1][x]);
	p.pb(v);
}

void solve(){
	cin >> n >> m;
	for(int i = 1; i <= n; ++i){
		cin >> x >> y;
		if(g[0][x])
			g[1][x] = y;
		else g[0][x] = y;
	}
	for(int i = 1; i <= n; ++i)
		if(!used[i])
			dfs(i);
	reverse(all(p));
	for(int i = 1; i <= n; ++i)
		used[i] = 0;
	for(int i = 0; i < p.size(); ++i){
		if(used[p[i]])
			continue;
		ok[p[i]] = 1;
		vector <int> v;
		if(!used[g[0][p[i]]])
			v.pb(g[0][p[i]]);
		if(!used[g[1][p[i]]])
			v.pb(g[1][p[i]]);
		if(v.size() == 0)
			continue;
		if(v.size() == 1){
			ok[v[0]] = 1;
			used[v[0]] = 1;
			used[g[0][v[0]]] = 1;
			used[g[1][v[0]]] = 1;
		}else{
			if(get(v[0], v[1]) == 1){
			
			}else if(get(v[0], v[1]) == 1){
			
			}else{
				ok[v[0]] = ok[v[1]] = 1;
				used[v[0]] = used[v[1]] = 1;
				used[g[0][v[0]]] = used[g[1][v[0]]] = 1;
				used[g[0][v[1]]] = used[g[1][v[1]]] = 1;
			}
		}
	}
}

int main(){
	cin.tie(0);
	cout.tie(0);
	ios_base::sync_with_stdio(NULL);

	int T;
	cin >> T;
	while(T--){	
		solve();
	}

	return 0;
}