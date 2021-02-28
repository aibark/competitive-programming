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

int n, Q, l[N], r[N], ans[N];
pair <int, int> a[N], q[N];
set <int> sl, sr;
set <pair <int, int> > s;
vector <int> add[N], ADD[N];

int main(){
	cin.tie(0);
	cout.tie(0);
	ios_base::sync_with_stdio(NULL);

	cin >> n >> Q;

	for(int i = 1; i <= n; ++i)
		cin >> a[i].f, a[i].s = i;

	for(int i = 1; i <= Q; ++i){
		cin >> q[i].f >> q[i].s;
		ADD[q[i].s].pb(i);
	}

	sort(a + 1, a + n + 1);

	for(int i = 1; i <= n; ++i){
		int R = i;
		while(R < n && a[R + 1].f == a[i].f)
			R++;
		for(int j = i; j <= R; ++j){
			auto it = sl.lower_bound(-a[j].s);
			if(it != sl.end())
				l[a[j].s] = -(*it);
			it = sr.lower_bound(a[j].s);
			if(it != sr.end())
				r[a[j].s] = *it;	
		}
		for(int j = i; j <= R; ++j)
			sl.insert(-a[j].s), sr.insert(a[j].s);
		i = R;
	}
	sl.clear(), sr.clear();
	reverse(a + 1, a + n + 1);

	for(int i = 1; i <= n; ++i){
		int R = i;
		while(R < n && a[R + 1].f == a[i].f)
			R++;
		for(int j = i; j <= R; ++j){
			auto it = sl.lower_bound(-a[j].s);
			if(it != sl.end())
				l[a[j].s + n] = -(*it);
			it = sr.lower_bound(a[j].s);
			if(it != sr.end())
				r[a[j].s + n] = *it;	
		}
		for(int j = i; j <= R; ++j)
			sl.insert(-a[j].s), sr.insert(a[j].s);
		i = R;
	}
	sl.clear(), sr.clear();

	for(int i = 1; i <= n + n; ++i){
		if(l[i] && r[i])
			add[r[i]].pb(i);
	}
		

	for(int i = 1; i <= n; ++i){
		for(int j : add[i])
			s.insert(mp(l[j], j));
		for(int j : ADD[i]){
			auto it = s.lower_bound(mp(q[j].f, 0));
			if(it != s.end())
				ans[j] = (*it).s;
		}
	}

	for(int i = 1; i <= Q; ++i)
		if(ans[i]){
			cout << 3 << endl;
			int x = ans[i];
			if(ans[i] > n)
				x -= n;
			cout << l[ans[i]] << " " << x << " " << r[ans[i]] << endl;
		}else{
			cout << 0 << endl;
		}

	return 0;
}