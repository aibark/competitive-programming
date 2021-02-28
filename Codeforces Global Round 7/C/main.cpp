#include <stdio.h>
#include <bits/stdc++.h>

#define f first
#define s second
#define pb push_back
#define mp make_pair
#define all(x) x.begin(), x.end()

typedef long long ll;

using namespace std;

const int N = (int)3e5 + 123, mod = 998244353, inf = (int)1e9;
const ll INF = (ll)1e18;

int n, k;
vector <int> v;
ll sum, ans = 1;

int main(){
	cin.tie(0);
	cout.tie(0);
	ios_base::sync_with_stdio(NULL);

	cin >> n >> k;

	for(int i = 1; i <= n; ++i){
		int x;
		cin >> x;
		if(n - k + 1 <= x)
			v.pb(i), sum += x;
	}

	for(int i = 1; i < v.size(); ++i)
		ans = ans * (v[i] - v[i - 1]) % mod;

	cout << sum << " " << ans << endl;

	return 0;
}