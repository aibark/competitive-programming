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

ll n, m, l[N], sum;

int main(){
	cin.tie(0);
	cout.tie(0);
	ios_base::sync_with_stdio(NULL);

	cin >> m >> n;

	for(int i = 1; i <= n; ++i)
		cin >> l[i];

	ll z = 0;
	for(int i = 1; i <= n; ++i){
		z = max(z, l[i] + i - 1);
		if(l[i] + i - 1 > m){
			cout << -1;
			return 0;
		}
		sum += l[i];
	}
	if(sum < m){
		cout << -1;
		return 0;
	}

	z = m - z;

	cout << 1 << " ";
	ll last = 1;

	for(int i = 2; i <= n; ++i){
		ll sdv = min(z, l[i - 1] - 1);
		z -= sdv;
		last += sdv + 1;
		cout << last << " ";
	}

	return 0;
}