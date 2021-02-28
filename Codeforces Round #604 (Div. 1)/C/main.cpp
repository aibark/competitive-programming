#include <stdio.h>
#include <bits/stdc++.h>

#define f first
#define s second
#define pb push_back
#define mp make_pair
#define all(x) x.begin(), x.end()

typedef long long ll;

using namespace std;

const int N = (int)3e5 + 123, mod = 998244353, inf = (int)1e9;
const ll INF = (ll)1e18;

int n, q, ok[N];
ll p[N], suf[N], ans, sum[N];
set <int> s;

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

int main(){
	cin.tie(0);
	cout.tie(0);
	ios_base::sync_with_stdio(NULL);

	cin >> n >> q;

	for(int i = 1; i <= n; ++i)
		cin >> p[i], p[i] = bp(p[i] * bp(100, mod - 2) % mod, mod - 2);

	suf[n + 1] = 1;
	sum[n + 1] = 0;
	for(int i = n; i >= 1; --i)
		suf[i] = (suf[i + 1] * p[i]) % mod, sum[i] = (sum[i + 1] + suf[i]) % mod;

	ans = sum[1];
	s.insert(1);
	s.insert(n + 1);

	while(q--){
		int x;
		cin >> x;
		if(ok[x]){
			s.erase(x);
			auto it = s.lower_bound(x);
			int r = *it;
			it--;
			int l = *it;
			ans += ((sum[l] - sum[r] + mod) % mod) * bp(suf[r], mod - 2) % mod;
			ans %= mod;	
			ans = (ans - ((sum[l] - sum[x] + mod) % mod) * bp(suf[x], mod - 2) % mod + mod) % mod;
			ans = (ans - ((sum[x] - sum[r] + mod) % mod) * bp(suf[r], mod - 2) % mod + mod) % mod;
		}else{
			auto it = s.lower_bound(x);
			int r = *it;
			it--;
			int l = *it;
			ans -= ((sum[l] - sum[r] + mod) % mod) * bp(suf[r], mod - 2) % mod;
			if(ans < 0)
				ans += mod;
			s.insert(x);
			ans = (ans + ((sum[l] - sum[x] + mod) % mod) * bp(suf[x], mod - 2)) % mod;
			ans = (ans + ((sum[x] - sum[r] + mod) % mod) * bp(suf[r], mod - 2)) % mod;
		}
		cout << ans << endl;
		ok[x] ^= 1;
	}

	return 0;
}