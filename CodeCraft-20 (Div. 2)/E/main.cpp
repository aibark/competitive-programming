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

int n, p, k;
ll b[N][7], dp[N][(1 << 7)], suf[N][(1 << 7)], ans;
pair <int, int> a[N];

int main(){
	cin.tie(0);
	cout.tie(0);
	ios_base::sync_with_stdio(NULL);

	cin >> n >> p >> k;
	for(int i = 1; i <= n; ++i)
		cin >> a[i].f, a[i].s = i;

	for(int i = 1; i <= n; ++i)
	for(int j = 0; j < p; ++j)
		cin >> b[i][j];

	sort(a + 1, a + n + 1);
	reverse(a + 1, a + n + 1);

	for(int mask = 0; mask < (1 << p); ++mask)
		dp[0][mask] = -INF;
	dp[0][0] = 0;

	for(int i = 1; i <= p + k; ++i){
		for(int mask = 0; mask < (1 << p); ++mask)
			dp[i][mask] = dp[i - 1][mask] + a[i].f;
		for(int mask = 0; mask < (1 << p); ++mask)
		for(int j = 0; j < p; ++j)
			if(!(mask & (1 << j)))
				dp[i][mask | (1 << j)] = max(dp[i][mask | (1 << j)], dp[i - 1][mask] + b[a[i].s][j]); 
	}


	for(int i = n; i >= 1; --i){
		for(int mask = 0; mask < (1 << p); ++mask)
			suf[i][mask] = suf[i + 1][mask];
		for(int mask = 0; mask < (1 << p); ++mask)
		for(int j = 0; j < p; ++j)
			if(!(mask & (1 << j)))
				suf[i][mask | (1 << j)] = max(suf[i][mask | (1 << j)], suf[i + 1][mask] + b[a[i].s][j]); 
	}


	for(int i = k; i <= p + k; ++i){
		for(int mask = 0; mask < (1 << p); ++mask){
			if(i - __builtin_popcount(mask) == k){
				ans = max(ans, dp[i][mask] + suf[i + 1][((1 << p) - 1) ^ mask]);
			}
		}
	}

	cout << ans << endl;
			
	return 0;
}