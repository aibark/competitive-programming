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

int n, x, a[N];

void solve(){
	cin >> n >> x;
	for(int i = 1; i <= n; ++i)
		cin >> a[i];
	sort(a + 1, a + n + 1);
	int ans = 2 * inf;    	
	for(int i = 1; i <= n; ++i)
		if(a[i] == x)
			ans = 1;
		else ans = min(ans, max(2, (x + a[n] - 1) / a[n]));
	cout << ans << endl;
}

int main(){
	cin.tie(0);
	cout.tie(0);
	ios_base::sync_with_stdio(NULL);

	int t;
	cin >> t;
	while(t--)
		solve();

	return 0;
}