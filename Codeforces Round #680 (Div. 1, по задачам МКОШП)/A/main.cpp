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



int main(){
	cin.tie(0);
	cout.tie(0);
	ios_base::sync_with_stdio(NULL);

	int t;
	cin >> t;
	while(t--){
		ll p, q;
		cin >> p >> q;
		if(p % q != 0){
			cout << p << endl;
			continue;
		}
		ll ans = 1;
		for(ll i = 2; i * i <= q; ++i){
			if(q % i != 0)
				continue;
			ll qi = 1;
			while(q % i == 0){
				q /= i;
				qi *= i;
			}
			ll P = p;
			ll qj = 1;
			while(P % i == 0){
				P /= i;
				qj *= i;
			}
			ans = max(ans, p / qj * qi / i);
		}
		if(q > 1){
			ll qj = 1;
			ll P = p;
			while(P % q == 0){
				P /= q;
				qj *= q;
			}
			ans = max(ans, p / qj);
		}
		cout << ans << endl;
	}

	return 0;
}