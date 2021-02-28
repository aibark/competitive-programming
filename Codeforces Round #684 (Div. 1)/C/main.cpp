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

ll a[N], t[4 * N], mn[4 * N], add[4 * N];
int n, q;

void build(int v, int tl, int tr){
	if(tl == tr){
		t[v] = a[tl]; 
		mn[v] = a[tl];
		return;
	}
	int tm = (tl + tr) >> 1;
	build(v + v, tl, tm);
	build(v + v + 1, tm + 1, tr);
	t[v] = t[v + v] + t[v + v + 1];
	mn[v] = min(mn[v + v], mn[v + v + 1]);
}

void push(int v, int tl, int tr){
	if(!add[v])
		return;
	int tm = (tl + tr) >> 1;
	t[v + v] = add[v] * (tm - tl + 1);
	t[v + v + 1] = add[v] * (tr - tm);
	mn[v + v] = mn[v + v + 1] = add[v];
	add[v + v] = add[v + v + 1] = add[v];
	add[v] = 0;
}

ll get(int v, int tl, int tr, int l, int r){
	if(tr < l || r < tl)
		return 0;
	if(l <= tl && tr <= r)
		return t[v];  	
	int tm = (tl + tr) >> 1;
	push(v, tl, tr);
	ll res = get(v + v, tl, tm, l, r) + get(v + v + 1, tm + 1, tr, l, r);
	t[v] = t[v + v] + t[v + v + 1];
	mn[v] = min(mn[v + v], mn[v + v + 1]);
	return res;
}

void upd(int v, int tl, int tr, int l, int r, ll x){
	if(tr < l || r < tl)
		return;
	if(l <= tl && tr <= r){
		add[v] = x;
		t[v] = 1LL * (tr - tl + 1) * x;
		mn[v] = x;
		return;
	}	
	int tm = (tl + tr) >> 1;
	push(v, tl, tr);
	upd(v + v, tl, tm, l, r, x);
	upd(v + v + 1, tm + 1, tr, l, r, x);
	t[v] = t[v + v] + t[v + v + 1];
	mn[v] = min(mn[v + v], mn[v + v + 1]);
}              

pair <ll, ll> spusk(int v, int tl, int tr, int l, int r, ll x){
	if(tr < l || r < tl)
		return mp(0, 0);
	if(t[v] <= x && l <= tl && tr <= r)
		return mp(t[v], tr - tl + 1);
	if(mn[v] > x)
		return mp(0, 0);
	push(v, tl, tr);
	int tm = (tl + tr) >> 1;
	pair <ll, ll> res = spusk(v + v, tl, tm, l, r, x);
	pair <ll, ll> res2 = spusk(v + v + 1, tm + 1, tr, l, r, x - res.f);
	return mp(res.f + res2.f, res.s + res2.s);
}

int main(){
	cin.tie(0);
	cout.tie(0);
	ios_base::sync_with_stdio(NULL);

	cin >> n >> q;
	for(int i = 1; i <= n; ++i)
		cin >> a[i];

	build(1, 1, n);
	while(q--){
		int type;
		ll x, y;
		cin >> type >> x >> y;
		if(type == 1){
			int l = 1, r = x;
			while(l <= r){
				int md = (l + r) >> 1;
				if(get(1, 1, n, md, md) < y)
					r = md - 1;
				else l = md + 1;
			}
			r++;
			upd(1, 1, n, r, x, y);
		}else{
			pair <ll, ll> pr = spusk(1, 1, n, x, n, y);
			cout << pr.s << endl;
		}
	}

	return 0;
}