#include <stdio.h>
#include <bits/stdc++.h>

#define f first
#define s second
#define pb push_back
#define mp make_pair
#define all(x) x.begin(), x.end()

typedef long long ll;

using namespace std;

const int N = (int)1e6 + 123, mod = (int)1e9 + 7, inf = (int)1e9;
const ll INF = (ll)1e18;

int n, ans, D[N];
vector <int> p;
vector <pair <int, int> > v;
bool used[N];
vector <int> g[N], ver;
set <int> s[N];
vector <pair <int, int> > gr[N];
queue <pair <int, pair <int, int> > > q;
vector <pair <pair <int, int>, int> > G;
pair <int, int> d[2][N];
set <pair <int, int> > S;

int main(){
	cin.tie(0);
	cout.tie(0);
	ios_base::sync_with_stdio(NULL);

	cin >> n;
	for(int i = 1; i <= n; ++i){
		int x;
		cin >> x;
		int y = sqrt(x);
		if(y * y == x){
			cout << 1;
			return 0;
		}
		int p1 = 0, p2 = 0;
		for(int j = 2; j * j <= x; ++j){
			if(x % j != 0)
				continue;
			int y = 0;
			while(x % j == 0){
				y++;
				x /= j;
			}
			if(y & 1){
				if(p1)
					p2 = j;
				else p1 = j;
			}
		}
		if(x > 1){
			if(p1)
				p2 = x;
			else p1 = x;
		}
		if(p2 == 0){
			p.pb(p1);
		}else{
			v.pb(mp(p1, p2));
		}
	}

	for(int i = 0; i < v.size(); ++i){
		if(used[v[i].f * v[i].s]){
			cout << 2 << endl;
			return 0;
		}
		used[v[i].f * v[i].s] = 1;
	}
	for(int i = 0; i < p.size(); ++i){
		if(used[p[i]]){
			cout << 2;
			return 0;
		}
		used[p[i]] = 1;
	}

	for(int i = 0; i < v.size(); ++i){
		if(v[i].f > v[i].s)
			swap(v[i].f, v[i].s);
		g[v[i].f].pb(v[i].s);
		g[v[i].s].pb(v[i].f);
		if(v[i].s > 1000){
			s[v[i].f].insert(v[i].s);
		}else G.pb(mp(mp(v[i].f, v[i].s), 1));
	}

	for(int i = 1; i <= 1000000; ++i){
		d[0][i] = d[1][i] = mp(inf, 0);
	}

	for(int i = 0; i < p.size(); ++i){
		d[0][p[i]] = mp(1, p[i]);
		q.push(mp(1, mp(p[i], p[i])));
	}

	while(!q.empty()){
		int x = q.front().s.f;
		int y = q.front().s.s;
		int z = q.front().f;
		q.pop();
		for(int to : g[x]){   	
			if(d[0][to].s == y || d[1][to].s == y)
				continue;	
			if(d[0][to].f > z + 1){
				swap(d[0][to], d[1][to]);
				d[0][to].f = z + 1;
				d[0][to].s = y;
				q.push(mp(z + 1, mp(to, y)));
			}else if(d[1][to].f > z + 1){
				d[1][to].f = z + 1;
				d[1][to].s = y;
				q.push(mp(z + 1, mp(to, y)));
			}
		}
	}
	ans = inf;
	for(int i = 1; i <= n; ++i)
		ans = min(ans, max(3, d[0][i].f + d[1][i].f));

	p.clear();
                      
	for(int i = 2; i <= 1000; ++i){
		bool ok = 1;
		for(int j = 2; j * j <= i; ++j)
			if(i % j == 0)
				ok = 0;
		if(ok)
			p.pb(i);
	}

	for(int i = 0; i < p.size(); ++i)
	for(int j = i + 1; j < p.size(); ++j){
		int cnt = 0;
		for(int x : s[p[i]]){
			if(s[p[j]].find(x) != s[p[j]].end()){
				ver.pb(x);
				G.pb(mp(mp(p[i], x), 1));
				G.pb(mp(mp(p[j], x), 1));
				if(cnt == 1)
					break;
				cnt++;
			}
		}
	}

	for(int i = 0; i < G.size(); ++i){
		int x = G[i].f.f, y = G[i].f.s;
		for(int j = 1; j <= 1000; ++j)
			D[j] = inf, gr[j].clear();
		for(int j : ver)
			D[j] = inf, gr[j].clear();
		for(int j = 0; j < G.size(); ++j){
			if(i == j)
				continue;
			gr[G[j].f.f].pb(mp(G[j].f.s, G[j].s));
			gr[G[j].f.s].pb(mp(G[j].f.f, G[j].s));
		}
		D[x] = 0;
		S.insert(mp(0, x));
		while(!S.empty()){
			int xa = (*S.begin()).s, ya = (*S.begin()).f;
			S.erase(S.begin());
			for(auto to : gr[xa]){
				if(D[to.f] > to.s + ya){
					D[to.f] = to.s + ya;
					S.insert(mp(D[to.f], to.f));
				}
			}	
		}
		ans = min(ans, max(3, D[y] + G[i].s));
	} 

	if(ans == inf)
		ans = -1;
	cout << ans;

	return 0;
}