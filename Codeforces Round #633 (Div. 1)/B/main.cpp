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

int n, mn, mx, col[N];
vector <int> g[N];

void dfs(int v, int pr = -1){
	for(int to : g[v]){
		if(to != pr){
			col[to] = 3 - col[v];
			dfs(to, v);
		}
	}
}

int main(){
	cin.tie(0);
	cout.tie(0);
	ios_base::sync_with_stdio(NULL);

	cin >> n;
	mx = n - 1;
	mn = 1;
	
	for(int i = 1; i < n; ++i){
		int x, y;
		cin >> x >> y;
		g[x].pb(y);
		g[y].pb(x);
	}

	for(int i = 1; i <= n; ++i){
		int x = 0;
		for(int j : g[i])
			if(g[j].size() == 1)
				x++;
		if(x)
			mx -= x - 1;
	}

	col[1] = 1;
	dfs(1);

	int c = 0;
	for(int i = 1; i <= n; ++i)
		if(g[i].size() == 1){
			if(c == 0)
				c = col[i];
			else{
				if(c != col[i])
					mn = 3;
			}
		}

	cout << mn << " " << mx << endl;

	return 0;
}