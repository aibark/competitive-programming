#include <stdio.h>
#include <bits/stdc++.h>

#define f first
#define s second
#define pb push_back
#define mp make_pair
#define all(x) x.begin(), x.end()

typedef long long ll;

using namespace std;

const int N = (int)3000 + 123, mod = 998244353 , inf = (int)1e9;
const ll INF = (ll)1e18;

ll dp[N][N], dp2[N][N], ans;
bool ok[N][N];
string s, t;
int n, m;
vector <pair <int, int> > v;

int main(){
	cin.tie(0);
	cout.tie(0);
	ios_base::sync_with_stdio(NULL);

	cin >> s >> t;
	n = s.size(), m = t.size();
	s = '#' + s;
	t = '#' + t;

	for(int i = 1; i <= m; ++i)
		if(s[1] == t[i])
			dp[i][i] = 2, v.pb(mp(i, i)); 

	dp[m + 1][m] = 2;
	v.pb(mp(m + 1, m));
	ans += dp[1][m];

	for(int i = 1; i < n; ++i){
		vector <pair <int, int> > nw;
		for(auto j : v){
			if(j.s == m){
			    if(!ok[j.f][j.s])
			    	nw.pb(j), ok[j.f][j.s] = 1;
				dp2[j.f][j.s] += dp[j.f][j.s];
				if(j.f == m + 1)
					dp2[j.f][j.s] += dp[j.f][j.s];
				if(s[i + 1] == t[j.f - 1]){
					if(!ok[j.f - 1][j.s])
						nw.pb(mp(j.f - 1, j.s)), ok[j.f - 1][j.s] = 1;
					dp2[j.f - 1][j.s] += dp[j.f][j.s];
				}
			}else{
				if(s[i + 1] == t[j.f - 1]){
				    if(!ok[j.f - 1][j.s])
						nw.pb(mp(j.f - 1, j.s)), ok[j.f - 1][j.s] = 1;
					dp2[j.f - 1][j.s] += dp[j.f][j.s];
				}
				if(s[i + 1] == t[j.s + 1]){
					if(!ok[j.f][j.s + 1])
						nw.pb(mp(j.f, j.s + 1)), ok[j.f][j.s + 1] = 1;
					dp2[j.f][j.s + 1] += dp[j.f][j.s];
				}
			}
		}
		for(auto j : nw){
			ok[j.f][j.s] = 0;
			dp[j.f][j.s] = dp2[j.f][j.s] % mod;
			dp2[j.f][j.s] = 0;
		}
		v = nw;
		ans += dp[1][m] % mod;
		ans %= mod;
	}

	cout << ans;

	return 0;
}