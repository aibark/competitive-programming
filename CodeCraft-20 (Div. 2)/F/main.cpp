#include <stdio.h>
#include <bits/stdc++.h>

#define f first
#define s second
#define pb push_back
#define mp make_pair
#define all(x) x.begin(), x.end()

typedef long long ll;

using namespace std;

const int N = (int)6e5 + 123, mod = (int)1e9 + 7, inf = (int)1e9;
const ll INF = (ll)1e18;

int n, lastpos[N], z[N], q;
pair <ll, int> a[N];
ll ans, t[4 * N], add[4 * N];

ll bp(ll x, ll y){
	ll z = 1;
	while(y){
		if(y & 1)
			z = z * x % mod;
		x = x * x % mod;
		y >>= 1;
	}
	return z;
}

void push(int v){
	t[v + v] += t[v];
	t[v + v + 1] += t[v];
	sum[0][v + v] = sum[0][v + v] * two[t[v]] % mod;
	sum[0][v + v + 1] = sum[0][v + v + 1] * two[t[v]] % mod;
	sum[1][v + v] = sum[1][v + v] * o[t[v]] % mod;
	sum[1][v + v] = sum[1][v + v] * o[t[v]] % mod;
	t[v] = 0;
}

void updpos(int v, int tl, int tr, int pos, bool OK){
	if(tl == tr){
		if(OK)
			sum[0][v] = 1LL * two[t[v]] * a[pos].f % mod, sum[1][v] = 1LL * o[t[v]] * a[pos].f % mod;
		else sum[0][v] = sum[1][v] = 0; 
		return;
	}
	int tm = (tl + tr) >> 1;
	push(v);
	if(pos <= tm)
		upd(v + v, tl, tm, pos, OK);
	else upd(v + v + 1, tm + 1, tr, pos, OK);
	sum[0][v] = sum[0][v + v] + sum[0][v + v + 1];
	sum[1][v] = sum[1][v + v] + sum[1][v + v + 1];
}

void upd(int x){
	if(ok[x]){
		
	}else{
		upd(1, 1, n + q, x, n + q);
		updpos(1, 1, n + q, x, 1);
	}
	ok[x] ^= 1;
}

int main(){
	int O = bp(2, mod - 2);
	two[0] = o[1] = 1;
	for(int i = 1; i <= 600000; ++i)
		two[0] = 
	cin.tie(0);
	cout.tie(0);
	ios_base::sync_with_stdio(NULL);

	cin >> n;
	for(int i = 1; i <= n; ++i){
		cin >> a[i].f >> a[i].s;
	}
	cin >> q;
	for(int i = n + 1; i <= n + q; ++i){
		cin >> a[i].s >> a[i].f;
		z[i - n] = a[i].s;
		a[i].s = i;
	}

	sort(a + 1, a + n + q + 1);

	for(int i = 1; i <= n + q; ++i){
		lastpos[a[i].s] = i;
		if(a[i].s <= n)
			upd(i);
	}

	cout << ans * 2 % mod << endl;

	for(int i = 1; i <= q; ++i){
		int x = lastpos[z[i]];
		upd(x);
		upd(lastpos[i + n]);
		lastpos[z[i]] = lastpos[i + n];

		cout << ans * 2 % mod << endl;
	}

	return 0;
}