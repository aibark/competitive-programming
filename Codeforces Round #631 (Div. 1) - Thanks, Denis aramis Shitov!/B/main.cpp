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

ll ans, c[N];

int main(){
	cin.tie(0);
	cout.tie(0);
	ios_base::sync_with_stdio(NULL);

	int T;
	cin >> T;
	while(T--){
		ll d, m;
		cin >> d >> m;
		ans = 1;
		for(int i = 0; i <= 30; ++i){
			c[i] = min((1LL << i), d - (1LL << i) + 1);
			c[i] = max(0LL, c[i]);
			ans = (c[i] + 1) * ans % m;
		}
		ans = (ans - 1 + m) % m;
		cout << ans << endl;
	}

	return 0;
}