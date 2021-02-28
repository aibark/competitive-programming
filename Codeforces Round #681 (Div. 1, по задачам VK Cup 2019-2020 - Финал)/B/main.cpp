#include <stdio.h>
#include <bits/stdc++.h>

#define f first
#define s second
#define pb push_back
#define mp make_pair
#define all(x) x.begin(), x.end()

typedef long long ll;

using namespace std;

const int N = (int)3e5 + 123, mod = (int)998244353, inf = (int)1e9;
const ll INF = (ll)1e18;

int n, k, a[N], b[N], numa[N], numb[N];
set <pair <int, int> > s;
ll ans;

void solve(){
	cin >> n >> k;
	for(int i = 1; i <= n; ++i)	
		cin >> a[i];
	a[0] = 0, a[n + 1] = n + 1;
	for(int i = 0; i <= n + 1; ++i){
		numa[a[i]] = i;
		s.insert(mp(i, a[i]));
	}
	numb[0] = numb[n + 1] = k + 1;
	
	for(int i = 1; i <= k; ++i){
		cin >> b[i];
		numb[b[i]] = i;
	}
	ans = 1;
	for(int i = 1; i <= k; ++i){
		auto itr = s.upper_bound(mp(numa[b[i]], b[i]));
		auto itl = itr;
		itl--, itl--;
		int l = (*itl).s, r = (*itr).s;
		if(numb[l] <= i && numb[r] <= i){
			ans *= 2;
			ans %= mod;
			s.erase(mp(numa[l], l));
		}else if(numb[l] > i && numb[r] > i){
			ans = 0;
			break;
		}else{
			if(numb[l] > i)
				swap(l, r);
			s.erase(mp(numa[l], l));
		}
	}
	cout << ans << endl;
	for(int i = 0; i <= n + 1; ++i)
		numa[i] = numb[i] = 0;
	s.clear();
}

int main(){
	cin.tie(0);
	cout.tie(0);
	ios_base::sync_with_stdio(NULL);

	int T;
	cin >> T;
	while(T--)
		solve();  

	return 0;
}