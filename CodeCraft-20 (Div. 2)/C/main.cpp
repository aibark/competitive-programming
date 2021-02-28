#include <stdio.h>
#include <bits/stdc++.h>

#define f first
#define s second
#define pb push_back
#define mp make_pair
#define all(x) x.begin(), x.end()

typedef long long ll;

using namespace std;

const int N = (int)1e6 + 123, mod = (int)1e9 + 7, inf = (int)1e9;
const ll INF = (ll)1e18;

int n, m, p, a[N], b[N];

int main(){
	cin.tie(0);
	cout.tie(0);
	ios_base::sync_with_stdio(NULL);

	cin >> n >> m >> p;
	for(int i = 0; i < n; ++i)
		cin >> a[i];
	for(int i = 0; i < m; ++i)
		cin >> b[i];
	if(true){
		int i = 0;
		while(a[i] % p == 0)
			i++;
		int j = 0;
		while(b[j] % p == 0)
			j++;
		cout << i + j << endl;
		return 0;
	}
	for(int j = 0; j <= n + m - 2; ++j){
		ll x = 0;
		for(int i = 0; i <= j; ++i){
			if(i < n && j - i < m)
				x += 1LL * a[i] * b[j - i] % p;
		}
		if(x % p != 0){
			cout << j << endl;
			return 0;
		}
	}

	return 0;
}