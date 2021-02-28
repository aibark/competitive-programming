#include <stdio.h>
#include <bits/stdc++.h>

#define f first
#define s second
#define pb push_back
#define mp make_pair
#define all(x) x.begin(), x.end()

typedef long long ll;

using namespace std;

const int N = (int)1e4 + 123, mod = (int)1e9 + 7, inf = (int)1e9;
const ll INF = (ll)1e18;

int n, m, d[N], g, r, dp[N][1011];;
deque <pair <int, int> > s;

int main(){
	cin.tie(0);
	cout.tie(0);
	ios_base::sync_with_stdio(NULL);

	cin >> n >> m;

	for(int i = 1; i <= m; ++i)
		cin >> d[i];

	sort(d + 1, d + m + 1);

	cin >> g >> r;

	for(int i = 1; i <= m; ++i)
	for(int j = 0; j < g; ++j)
		dp[i][j] = inf;

	dp[1][0] = 0;
	s.push_back(mp(1, 0));

	while(!s.empty()){
		int x = s.front().f, y = s.front().s;
		//cout << x << " " << y << " " << dp[x][y] << endl;
		s.pop_front(); 
		int DP = dp[x][y];
		if(y == 0)
			y = g;
		if(x > 1 && y - (d[x] - d[x - 1]) >= 0){
			if(y - (d[x] - d[x - 1]) > 0 && dp[x - 1][y - (d[x] - d[x - 1])] > DP){
				dp[x - 1][y - (d[x] - d[x - 1])] = DP;
				s.push_front(mp(x - 1, y - (d[x] - d[x - 1])));
			}else if(y - (d[x] - d[x - 1]) == 0 && dp[x - 1][0] > DP + 1){
				dp[x - 1][0] = DP + 1;
				s.push_back(mp(x - 1, 0));
			}
		}
		if(x < m && y - (d[x + 1] - d[x]) >= 0){
			if(y - (d[x + 1] - d[x]) > 0 && dp[x + 1][y - (d[x + 1] - d[x])] > DP){
				dp[x + 1][y - (d[x + 1] - d[x])] = DP;
				s.push_back(mp(x + 1, y - (d[x + 1] - d[x])));	
			}else if(y - (d[x + 1] - d[x]) == 0 && dp[x + 1][0] > DP + 1){
				dp[x + 1][0] = DP + 1;
				s.push_back(mp(x + 1, 0));
			}
		}
	}

	int ans = 2 * inf;
	for(int i = 1; i < g; ++i){
		if(dp[m][i] != inf)
			ans = min(ans, dp[m][i] * g + dp[m][i] * r + g - i);
	}

	if(dp[m][0] != inf)
		ans = min(ans, dp[m][0] * g + (dp[m][0] - 1) * r);

	if(ans == 2 * inf)
		cout << -1;
	else cout << ans;

	return 0;
}