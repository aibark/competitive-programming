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

int n, ans;
ll a[N];

void solve(){
	cin >> n;
	for(int i = 1; i <= n; ++i)
		cin >> a[i];

	ans = 0;
	for(int i = 2; i <= n; ++i){
		if(a[i - 1] <= a[i])
			continue;
		ll x = a[i - 1] - a[i];
		for(int j = 0; j <= 60; ++j)
			if((x >> j) & 1)
				ans = max(ans, j + 1);
		a[i] = a[i - 1]; 
	}	

	cout << ans << endl;
}

int main(){
	cin.tie(0);
	cout.tie(0);
	ios_base::sync_with_stdio(NULL);

	int T;
	cin >> T;

	while(T--){
		solve();
	}

	return 0;
}