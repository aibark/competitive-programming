#include <stdio.h>
#include <bits/stdc++.h>

#define f first
#define s second
#define pb push_back
#define mp make_pair
#define all(x) x.begin(), x.end()

typedef long long ll;

using namespace std;

const int N = (int)2000 + 123, mod = 998244353 , inf = (int)1e9;
const ll INF = (ll)1e18;

ll n, cnk[N][N], pre[N], suf[N], a[N], b[N];
ll ans, A[N];
string s;

ll c(int x, int y){
	if(x < y || y < 0)
		return 0;
	return cnk[x][y];
}

int main(){
	cin.tie(0);
	cout.tie(0);
	ios_base::sync_with_stdio(NULL);

	cin >> s;
	n = s.size();
	s = '#' + s;

	for(int i = 0; i <= 2000; i++){
		cnk[i][0] = cnk[i][i] = 1;
		for(int j = 1; j < i; j++)
			cnk[i][j] = (cnk[i - 1][j - 1] + cnk[i - 1][j]) % mod;
	}

	for(int i = 1; i <= n; ++i){
		pre[i] = pre[i - 1];
		if(s[i] == '(')
			pre[i]++;
		a[i] = a[i - 1];
		if(s[i] == '?')
			a[i]++;
	}
	for(int i = n; i >= 1; --i){
		suf[i] = suf[i + 1];
		if(s[i] == ')')
			suf[i]++;
		b[i] = b[i + 1];
		if(s[i] == '?')
			b[i]++;
	}

	for(int i = 1; i <= n; i++){
		for(int y = n; y >= 1; --y)
			A[y] = (A[y + 1] + c(b[i + 1], y - suf[i + 1])) % mod;
		if(s[i] == '('){
			for(int x = 1; x <= i; x++){	
				ans += c(a[i], x - pre[i]) * A[x] % mod;
				ans %= mod;
			}	
		}else if(s[i] == '?'){
			for(int x = 1; x <= i; x++){
				ans += c(a[i] - 1, x - pre[i] - 1) * A[x] % mod;
				ans %= mod;
			}
		}
	}
	cout << ans;
	return 0;
}