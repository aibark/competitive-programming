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

int n[4], p[4];
set <ll> s[4];
ll ans;

int main(){
	cin.tie(0);
	cout.tie(0);
	ios_base::sync_with_stdio(NULL);

	int T;
	cin >> T;
	while(T--){
		cin >> n[1] >> n[2] >> n[3];
		s[1].clear(), s[2].clear(), s[3].clear();
		for(int i = 1; i <= 3; ++i)
		for(int j = 1; j <= n[i]; ++j){
			ll x;
			cin >> x;
			s[i].insert(x);
		}	
		p[1] = 1, p[2] = 2, p[3] = 3;
		ans = 4LL * INF;
		do{
			for(ll x : s[p[2]]){
				auto it = s[p[1]].upper_bound(x);
				if(it != s[p[1]].begin()){
					it--;
					ll y = *it;
					it = s[p[3]].lower_bound(x);
					if(it != s[p[3]].end()){
						ll z = *it;
						ans = min(ans, (x - y) * (x - y) + (y - z) * (y - z) + (x - z) * (x - z));
					}
				}
			}
		}while(next_permutation(p + 1, p + 4));
		cout << ans << endl;
	}

	return 0;
}