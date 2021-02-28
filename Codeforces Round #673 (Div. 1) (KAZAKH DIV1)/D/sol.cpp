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

struct query{
	int t, i;
}q[N * 2];

int n, m, Q, a[N], p[N], gu[N], gv[N], sz[N], cur[N];
vector <int> v[N];
bool used[N], ok[N];

bool cmp(int x, int y){
	return a[x] > a[y];
}

int get(int x){
	if(p[x] == x)
		return x;
	return p[x] = get(p[x]);
}

int main(){
	cin.tie(0);
	cout.tie(0);
	ios_base::sync_with_stdio(NULL);

	cin >> n >> m >> Q;
	for(int i = 1; i <= n; ++i)
		cin >> a[i], p[i] = i, sz[i] = 1;

	for(int i = 1; i <= m; ++i)
		cin >> gu[i] >> gv[i];
	for(int i = 1; i <= Q; ++i){
		cin >> q[i].t >> q[i].i;	
		if(q[i].t == 2)
			used[q[i].i] = 1;
	}

	for(int i = 1; i <= m; ++i){
		if(!used[i] && get(gu[i]) != get(gv[i])){
			sz[get(gu[i])] += sz[get(gv[i])];
			p[get(gu[i])] = get(gv[i]);
		}
	}
	
	for(int i = 1; i <= n; ++i)
		v[get(i)].pb(i);

	for(int i = Q; i >= 1; --i){
		if(q[i].t == 2){
			int x = gu[q[i].i], y = gv[q[i].i];
			x = get(x);
			y = get(y);
			if(x != y){
				used[q[i].i] = 0;
				if(sz[x] < sz[y])
					swap(x, y);
				gu[q[i].i] = x, gv[q[i].i] = y;
				for(int j : v[y])
					v[x].pb(j);	
				p[y] = x;
				sz[x] += sz[y];
			}                         
		}
	}
	for(int i = 1; i <= n; ++i)
		sort(all(v[i]), &cmp), p[i] = get(p[i]);

	for(int i = 1; i <= Q; ++i){
		if(q[i].t == 1){
		    int x = p[q[i].i];
		    while(cur[x] < (int)v[x].size() && (p[v[x][cur[x]]] != x || ok[v[x][cur[x]]]))
		    	cur[x]++;
			if(cur[x] == (int)v[x].size())
				cout << 0 << endl;
			else cout << a[v[x][cur[x]]] << endl, ok[v[x][cur[x]]] = 1;
		}else{
			if(used[q[i].i])
				continue;
			int y = gv[q[i].i];
			for(int j : v[y])
				p[j] = y;
		}
	}

	return 0;
}