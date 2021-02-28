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

int n, a[N], b[N], q;
ll ans;
map <int, int> m[N];

int main(){
	cin.tie(0);
	cout.tie(0);
	ios_base::sync_with_stdio(NULL);

	cin >> n;
	for(int i = 1; i <= n; ++i){
		cin >> a[i];
		ans += a[i];
	}

	cin >> q;
	while(q--){
		int s, t, u;
		cin >> s >> t >> u;
		if(m[s][t] != 0){
			ans -= max(0, a[m[s][t]] - b[m[s][t]]);
			b[m[s][t]]--;
			ans += max(0, a[m[s][t]] - b[m[s][t]]); 
		}
		if(u != 0){
			m[s][t] = u;
			ans -= max(0, a[m[s][t]] - b[m[s][t]]);
			b[m[s][t]]++;
			ans += max(0, a[m[s][t]] - b[m[s][t]]); 
		}
		cout << ans << endl;
	}

	return 0;
}