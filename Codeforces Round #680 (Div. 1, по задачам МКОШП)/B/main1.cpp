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

ll n, a[N], ans;

ll fact(int j){
	ll f = 1;
	for(int i = 1; i <= j; ++i)
		f = f * i % mod;
	return f;
}

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

	cin >> n;
	n += n;
	for(int i = 1; i <= n; ++i)
		cin >> a[i];
	sort(a + 1, a + n + 1);

	ll A = fact(n) * bp(bp(fact(n / 2), mod - 2), 2) % mod;
	ll B = 0;
	for(int i = 1; i < n; ++i){
		if(i <= n / 2)
			B += A;
		else B = B - A + mod;
		B %= mod;
		ans = (ans + (a[i + 1] - a[i]) * B % mod) % mod;
	}

	cout << ans;
	return 0;
}