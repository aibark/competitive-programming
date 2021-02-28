#include <stdio.h>
#include <bits/stdc++.h>

#define f first
#define s second
#define pb push_back
#define mp make_pair
#define all(x) x.begin(), x.end()

typedef long long ll;

using namespace std;

const int N = (int)5e3 + 123, mod = (int)1e9 + 7, inf = (int)1e9;
const ll INF = (ll)1e18;

int n, m, pref[N][N], d[N][N], a[N], cnt[N];
ll ansa, ansb;
vector <int> v[N];

int main(){
	cin.tie(0);
	cout.tie(0);
	ios_base::sync_with_stdio(NULL);

	cin >> n >> m;
	for(int i = 1; i <= n; ++i){
		cin >> a[i];
		cnt[a[i]]++;
		for(int j = 1; j <= n; ++j)
			pref[j][i] = pref[j][i - 1];
		pref[a[i]][i]++;
	}
	
	for(int i = 1; i <= m; ++i){
		int f, h;
		cin >> f >> h;
		v[f].pb(h);
	}	

	for(int i = 1; i <= n; ++i){
		sort(all(v[i]));
		for(int j : v[i])
			d[i][j]++;
		for(int j = 1; j <= n; ++j){
			d[i][j] += d[i][j - 1];
		}
	}

	for(int i = 0; i <= n; ++i){
		int cnta = 0;
		ll ans = 1;
		for(int j = 1; j <= n; ++j){
			if(j == a[i]){ 
				bool ok = 0;
				int r = 0;
				for(int k : v[j]){
					if(k == pref[j][i])
						ok = 1;		
					else if(k <= cnt[j] - pref[j][i])
						r++;
				}	
				if(!ok)
					ans = 0;
				else{
					if(r == 0)
						cnta++;
					else cnta += 2, ans *= r;
				} 
			}else{
				int l = pref[j][i];
				int r = cnt[j] - l;
				if(d[j][l] * d[j][r] - d[j][min(l, r)] > 0){
					cnta += 2;
					ans *= 1LL * d[j][l] * d[j][r] - d[j][min(l, r)];
				}else if(d[j][l] > 0 || d[j][r] > 0){
					cnta++;
					ans *= d[j][l] + d[j][r];
				}
			}
			ans %= mod;
		}
		if(ansa < cnta)
			ansa = cnta, ansb = ans;
		else if(ansa == cnta)
			ansb = (ansb + ans) % mod;
	}
	                       
	cout << ansa << " " << ansb << endl;

	return 0;
}