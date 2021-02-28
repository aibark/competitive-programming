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

int n, m, k, d[N], d1[N], mx[N], ans;
queue <int> q;
vector <int> g[N];
bool ok[N], used[N];;

void upd(int pos, int x){
	pos = n - pos;
	for(; pos <= n; pos |= (pos + 1))
		mx[pos] = max(mx[pos], x); 
}

int get(int pos){
	pos = max(pos, 0);
	pos = n - pos;
	ans = -n;
	for(; pos >= 0; pos = (pos & (pos + 1)) - 1)
		ans = max(ans, mx[pos]);
	return ans;
}

int main(){
	cin.tie(0);
	cout.tie(0);
	ios_base::sync_with_stdio(NULL);

	cin >> n >> m >> k;
	for(int i = 1; i <= k; ++i){
		int x;
		cin >> x;
		ok[x] = 1;
	}

	for(int i = 1; i <= m; ++i){
		int x, y;
		cin >> x >> y;
		g[x].pb(y);
		g[y].pb(x);
	}
	
	used[n] = 1;
	q.push(n);
	while(!q.empty()){
		int x = q.front();
		q.pop();
		for(int to : g[x]){
			if(!used[to]){
				used[to] = 1;
				d[to] = d[x] + 1;
				q.push(to);
			}
		}
	}

	memset(used, 0, sizeof used);
	q.push(1);
	used[1]  = 1;
	while(!q.empty()){
		int x = q.front();
		q.pop();
		for(int to : g[x]){
			if(!used[to]){
				used[to] = 1;
				d1[to] = d1[x] + 1;
				q.push(to);
			}
		}
	}

	int l = 1, r = n;

	while(l <= r){
		int md = (l + r) >> 1;
		for(int i = 0; i <= n; ++i)
			mx[i] = -n;
		bool oka = 0;
		for(int i = 1; i <= n; ++i){
			if(!ok[i])
				continue;
			if(get(md - d1[i]) >= md - d[i]){
				oka = 1;
				break;
			}
			upd(d[i], d1[i]);
		}
		if(oka)
			l = md + 1;
		else r = md - 1;
	}

	cout << min(l, d[1]);

	return 0;
}