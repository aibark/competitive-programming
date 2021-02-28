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

int T, n, ans[N];
vector <int> v[N];

int main(){
	cin.tie(0);
	cout.tie(0);
	ios_base::sync_with_stdio(NULL);

	cin >> T;
	while(T--){
		cin >> n;
		for(int i = 1; i <= n; ++i){
			int x;
			cin >> x;
			v[x].pb(i);
			ans[i] = n + 1;
		}
		for(int i = 1; i <= n; ++i){
			if(v[i].size() == 0)
				continue;
			int mx = max(v[i][0], n - v[i].back() + 1);
			for(int j = 1; j < (int)v[i].size(); ++j)
				mx = max(mx, v[i][j] - v[i][j - 1]);
			ans[mx] = min(ans[mx], i);
		}
		for(int i = 1; i < n; ++i)
			ans[i + 1] = min(ans[i + 1], ans[i]);
		for(int i = 1; i <= n; ++i)
			if(ans[i] == n + 1)
				cout << -1 << " ";
			else cout << ans[i] << " ";
		cout << endl;
		for(int i = 1; i <= n; ++i)
			v[i].clear();
	}

	return 0;
}