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

int n, d, a[N];

void solve(){
	cin >> n >> d;
	for(int i = 1; i <= n; ++i){
		cin >> a[i];
	}
	for(int i = 2; i <= n; ++i){
		int x = min(a[i], d / (i - 1));
		a[i] -= x;
		a[1] += x;
		d -= (i - 1) * x;
	}
	cout << a[1] << endl;
}

int main(){
	cin.tie(0);
	cout.tie(0);
	ios_base::sync_with_stdio(NULL);

	int t;
	cin >> t;
	while(t--)
		solve();

	return 0;
}