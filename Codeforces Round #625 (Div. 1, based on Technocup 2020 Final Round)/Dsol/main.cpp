#include <stdio.h>
#include <bits/stdc++.h>

#define f first
#define s second
#define pb push_back
#define mp make_pair
#define all(x) x.begin(), x.end()

typedef long long ll;

using namespace std;

const int N = (int)3e5 + 123, inf = (int)1e9, hsz = 4;
const ll INF = (ll)1e18;

ll mod[] = {(ll)1e9 + 7, (ll)1e9 + 9, (ll)1e9 + 7, (ll)1e9 + 9};
ll base[] = {3, 7, 29, 13331};

ll a[hsz][N], pref[N];
int n, q;
string s;

struct item{
	int pref, suf;
	ll item[hsz];
	int len;
}zer, t[4 * N];

item merge(item x, item y){
	item z = zer;
	if(x.len == 0 && y.len == 0){
		z.pref = z.suf = x.pref + y.pref;
	}else if(x.len == 0){
		z = y;
		z.pref = x.pref + y.pref;
	}else if(y.len == 0){
		z = x;
		z.suf = x.suf + y.suf;
	}else{
		z.pref = x.pref;
		z.suf = y.suf;
		z.len = x.len + y.len + (x.suf + y.pref) % 2;
		for(int i = 0; i < hsz; ++i){
			if((x.suf + y.pref) % 2 == 1){
			    z.item[i] = x.item[i] * a[i][y.len + 1] + 2LL * a[i][y.len] + y.item[i];
				z.item[i] %= mod[i];
			}else{
				z.item[i] = x.item[i] * a[i][y.len] + y.item[i];
				z.item[i] %= mod[i];
			}
		}
	}
	return z;
}

bool ok(item x, item y){
	if(!(x.pref % 2 == y.pref % 2 && x.suf % 2 == y.suf % 2 && x.len == y.len))
		return 0;
	for(int i = 0; i < hsz; ++i)
		if(x.item[i] != y.item[i])
			return 0;
	return 1;
}

void build(int v, int tl, int tr){
	if(tl == tr){
		t[v] = zer;
		if(s[tl] == '0'){
			t[v].pref = t[v].suf = 0;
			t[v].len = 1;
			for(int i = 0; i < hsz; ++i)
				t[v].item[i] = 1;
		}else{
			t[v].pref = t[v].suf = 1;
			t[v].len = 0;
		}
		return;
	}
	int tm = (tl + tr) >> 1;
	build(v + v, tl, tm);
	build(v + v + 1, tm + 1, tr);
	t[v] = merge(t[v + v], t[v + v + 1]);
}

item get(int v, int tl, int tr, int l, int r){
	if(r < tl || tr < l)
		return zer;
	if(l <= tl && tr <= r)
		return t[v];
	int tm = (tl + tr) >> 1;
	item x = get(v + v, tl, tm, l, r);
	item y = get(v + v + 1, tm + 1, tr, l, r);
	return merge(x, y);
}

int main(){
	for(int i = 0; i < hsz; ++i){
		a[i][0] = 1;
		for(int j = 1; j <= 200000; ++j)
			a[i][j] = a[i][j - 1] * base[i] % mod[i];
	}
	zer.pref = 0, zer.suf = 0, zer.len = 0;
	for(int i = 0; i < hsz; ++i)
		zer.item[i] = 0;
	cin.tie(0);
	cout.tie(0);
	ios_base::sync_with_stdio(NULL);

	cin >> n;
	cin >> s;
	s = '#' + s;

	build(1, 1, n);
	for(int i = 1; i <= n; ++i){
		pref[i] = pref[i - 1] + (s[i] == '1');
	}

	cin >> q;
	while(q--){
		int la, lb, ra, rb;
		cin >> la >> lb >> ra;
		rb = lb + ra - 1;
		ra = la + ra - 1;
		if(pref[ra] - pref[la - 1] != pref[rb] - pref[lb - 1]){
			cout << "No";
			continue;
		}
		//cout << la << " " << ra << " " << lb << " " << rb << endl;
		item x = get(1, 1, n, la, ra);
		item y = get(1, 1, n, lb, rb);
		//cout << x.pref << " " << x.suf << " " << x.len << endl;
		//cout << y.pref << " " << y.suf << " " << y.len << endl;
		if(ok(x, y)){
			cout << "Yes" << endl;
		}else cout << "No" << endl;
	}

	return 0;
}