#include <stdio.h>
#include <bits/stdc++.h>

#define f first
#define s second
#define pb push_back
#define mp make_pair
#define all(x) x.begin(), x.end()

typedef long long ll;

using namespace std;

const int N = 14, mod = (int)1e9 + 7, inf = (int)1e9;
const ll INF = (ll)1e18;

int n, a[N][N];
ll ans[(1 << N)];
map <int, ll> dp[(1 << N)][N];

int main(){
	cin.tie(0);
	cout.tie(0);
	ios_base::sync_with_stdio(NULL);

	cin >> n;
	for(int i = 0; i < n; ++i)
	for(int j = 0; j < n; ++j){
		char c;
		//cin >> c;
		a[i][j] = rand() % 2;
	}

	for(int i = 0; i < n; ++i)
		dp[(1 << i)][i][0] = 1;

	for(int i = 1; i < (1 << n); ++i)
		v[__builtin_popcount(i)].pb(i);
	for(int i = 1; i <= 14; ++i)
	for(int j = 0; j < v[i].size(); ++j)
			

	for(int mask = 1; mask < (1 << n); ++mask)
	for(int last = 0; last < n; ++last){
		if(!((mask >> last) & 1))
			continue;
		for(auto s : dp[mask][last]){
			for(int nw = 0; nw < n; ++nw)
				if(!((mask >> nw) & 1))
					dp[mask | (1 << nw)][nw][s.f * 2 + a[last][nw]] += s.s;
		}	
		if(mask == (1 << n) - 1){
			for(auto s : dp[mask][last])
				ans[s.f] += s.s;
		}
	}	

	                     
	for(int i = 0; i < (1 << (n - 1)); ++i)
		cout << ans[i] << " ";

	return 0;
}