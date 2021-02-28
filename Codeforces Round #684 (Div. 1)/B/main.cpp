#include <stdio.h>
#include <bits/stdc++.h>

#define f first
#define s second
#define pb push_back
#define mp make_pair
#define all(x) x.begin(), x.end()

typedef long long ll;

using namespace std;

const int N = (int)1e5 + 123, mod = (int)1e9 + 7, inf = (int)1e9;
const ll INF = (ll)1e18;

int n, m, k, num[N];
bool ga[5000][5000];         
set <int> g[N];
set <pair <int, int> > s;
vector <pair <int, int> > e;

void solve(){
	cin >> n >> m >> k;
	for(int i = 1; i <= n; ++i)
		g[i].clear(), num[i] = 0;
	s.clear();
	e.clear();
	for(int i = 1; i <= m; ++i){
		int x, y;
		cin >> x >> y;
		e.pb(mp(x, y));
		g[x].insert(y);
		g[y].insert(x);
	}
	for(int i = 1; i <= n; ++i)
		s.insert(mp(g[i].size(), i));
	while((int)s.size() > 0){
		int x = (*s.begin()).s;
		if((int)g[x].size() >= k)
			break;
		s.erase(s.begin());
		for(int j : g[x]){
			s.erase(mp(g[j].size(), j));
			g[j].erase(x);
			s.insert(mp(g[j].size(), j));
		}
	}
	if((int)s.size() > 0){
		cout << 1 << " " << (int)s.size() << endl;
		for(auto i : s)
			cout << i.s << " ";
		cout << endl;
		return;
	}
	for(int i = 1; i <= n; ++i)
		g[i].clear();
	for(int i = 1; i <= m; ++i){
		int x = e[i - 1].f, y = e[i - 1].s;
		g[x].insert(y);
		g[y].insert(x);
	}
	for(int i = 1; i <= n; ++i)
		s.insert(mp(g[i].size(), i));
	while((int)s.size() > 0){
		int x = (*s.begin()).s;
		if((int)g[x].size() >= k - 1)
			break;   
		s.erase(s.begin());
		for(int j : g[x]){
			s.erase(mp(g[j].size(), j));
			g[j].erase(x);
			s.insert(mp(g[j].size(), j));
		}
		g[x].clear();
	}
	int numn = 0;
	if(k >= 100){
	for(auto i : s)
		num[i.s] = ++numn;
	for(int j = 0; j <= numn; ++j)
	for(int i = 0; i <= numn; ++i)
		ga[i][j] = 0;
	for(int i = 1; i <= m; ++i)
		ga[num[e[i - 1].f]][num[e[i - 1].s]] = ga[num[e[i - 1].s]][num[e[i - 1].f]] = 1;
	}
	while((int)s.size() > 0){
		int i = (*s.begin()).s;
		if((int)g[i].size() > k - 1)
			break;
		s.erase(s.begin());
		vector <int> v;
		v.pb(i);
		for(int j : g[i])
			v.pb(j);
		bool ok = 1;
		for(int x = 0; x < (int)v.size() && ok; ++x)
		for(int y = x + 1; y < (int)v.size() && ok; ++y){
			if(k >= 100){
			if(!ga[num[v[x]]][num[v[y]]]){
				ok = 0;
				break;
			}
			}else{
				if(g[v[x]].find(v[y]) == g[v[x]].end()){
					ok = 0;
					break;
				}
			}
		}
		if(ok && (int)v.size() == k){
			cout << 2 << endl;
			for(int j : v)
				cout << j << " ";
			cout << endl;
			return;
		}
		for(int j : g[i]){
			s.erase(mp(g[j].size(), j));
			g[j].erase(i);
			s.insert(mp(g[j].size(), j));
		}
		g[i].clear();
	}
	cout << -1 << endl;
}

int main(){
	cin.tie(0);
	cout.tie(0);
	ios_base::sync_with_stdio(NULL);

	int T;
	cin >> T;
	while(T--)
		solve();

	return 0;
}