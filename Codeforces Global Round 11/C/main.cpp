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

int r, n, ans, t[N], x[N], y[N], dp[N], mx[N];

int main(){
	cin.tie(0);
	cout.tie(0);
	ios_base::sync_with_stdio(NULL);

	cin >> r >> n;

	mx[0] = -inf;
	for(int i = 1; i <= n; ++i)
		cin >> t[i] >> x[i] >> y[i], dp[i] = -inf, mx[i] = -inf;

	for(int i = 1; i <= n; ++i){
		if(x[i] - 1 + y[i] - 1 <= t[i])
			dp[i] = 1;
		
		for(int j = max(1, i - 2 * r); j < i; ++j)
			if(t[i] - t[j] >= abs(x[i] - x[j]) + abs(y[i] - y[j]))
				dp[i] = max(dp[i], dp[j] + 1);
		
		dp[i] = max(dp[i], mx[max(0, i - 2 * r - 1)]);
		
		mx[i] = max(dp[i], mx[i - 1]);
		
		ans = max(ans, dp[i]);
	}

	cout << ans;

	return 0;
}