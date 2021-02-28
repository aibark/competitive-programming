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

int n, a[N], m[N * 30][2], ver; 
ll ans[30], revans[30];
vector <int> v[N * 30];

void dfs(int x, int lvl = 29){
	int A = 0, B = 0;
	ll ansa = 0;
	for(int i = v[x].size() - 1; i >= 0; --i){
		if(((a[v[x][i]] >> lvl) & 1)){
			B++;
			ansa += A;
		}else{
			A++;
		}
	}
	ans[lvl] += ansa;
	revans[lvl] += 1LL * A * B - ansa;
	if(m[x][0] != 0)
		dfs(m[x][0], lvl - 1);
	if(m[x][1] != 0)
		dfs(m[x][1], lvl - 1);
}

int main(){
	cin.tie(0);
	cout.tie(0);
	ios_base::sync_with_stdio(NULL);

	cin >> n;
	for(int i = 1; i <= n; ++i){
		cin >> a[i];
		int k = 0;
		for(int j = 29; j > 0; --j){
			int bit = ((a[i] >> j) & 1);
			if(m[k][bit] == 0)
				m[k][bit] = ++ver;
			v[k].pb(i);
			k = m[k][bit];
		}
		v[k].pb(i);
	}
	dfs(0);
	int ansx = 0;
	ll sum = 0;
	for(int i = 0; i <= 29; ++i)
		if(revans[i] < ans[i])
			ansx ^= (1 << i), sum += revans[i];
		else sum += ans[i];
	cout << sum << " " << ansx;


	return 0;
}