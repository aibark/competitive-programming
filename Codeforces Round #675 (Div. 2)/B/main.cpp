#include <stdio.h>
#include <bits/stdc++.h>

#define f first
#define s second
#define pb push_back
#define mp make_pair
#define all(x) x.begin(), x.end()

typedef long long ll;

using namespace std;

const int N = 123, mod = (int)1e9 + 7, inf = (int)1e9;
const ll INF = (ll)1e18;

int n, m;
ll ans;
vector <int> a[N][N];

int main(){
	cin.tie(0);
	cout.tie(0);
	ios_base::sync_with_stdio(NULL);

	int T;
	cin >> T;
	while(T--){
		cin >> n >> m;
		for(int i = 1; i <= n; ++i)
		for(int j = 1; j <= m; ++j)
			a[i][j].clear();
		ans = 0;
		for(int i = 1; i <= n; ++i)
		for(int j = 1; j <= m; ++j){
			int x = min(i, n - i + 1), y = min(j, m - j + 1);
			int z;
			cin >> z;
			a[x][y].pb(z);
		}
		for(int i = 1; i <= n; ++i)
		for(int j = 1; j <= m; ++j)
			if(a[i][j].size() > 0){
				sort(all(a[i][j]));
				int md = a[i][j][a[i][j].size() / 2];
				for(int k : a[i][j])	
					ans += abs(k - md);
			}
		cout << ans << endl;
	}

	return 0;
}