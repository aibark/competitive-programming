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

int n, m, k, a[N], d[N], mn, mx;
queue <int> q;

vector <int> g[N], gr[N];

int main(){
	cin.tie(0);
	cout.tie(0);
	ios_base::sync_with_stdio(NULL);

	cin >> n >> m;
	
	for(int i = 0; i < m; ++i){
		int x, y;
		cin >> x >> y;
		g[x].pb(y);
		gr[y].pb(x);
	}
	cin >> k;

	for(int i = 1; i <= k; ++i)
		cin >> a[i];

	for(int i = 1; i <= n; ++i)
		d[i] = m;

	d[a[k]] = 0;
	q.push(a[k]);
	while(!q.empty()){
		int x = q.front();
		q.pop();
		for(int to : gr[x]){
			if(d[to] > d[x] + 1){
				d[to] = d[x] + 1;
				q.push(to);
			}
		}
	}

	for(int i = 1; i < k; ++i){
		if(d[a[i + 1]] + 1 != d[a[i]])
			mn++;
		bool ok = 0;
		for(int to : g[a[i]]){
			if(to == a[i + 1])
				continue;
			if(d[to] + 1 == d[a[i]])
				ok = 1;
		}
		mx += ok;
	}

	cout << mn << " " << mx << endl;

	return 0;
}