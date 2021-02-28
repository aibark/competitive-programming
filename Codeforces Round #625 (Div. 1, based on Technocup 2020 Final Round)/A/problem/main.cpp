#include <stdio.h>
#include <bits/stdc++.h>

#define f first
#define s second
#define pb push_back
#define mp make_pair
#define all(x) x.begin(), x.end()

typedef long long ll;

using namespace std;

const int N = (int)3e6 + 123, mod = (int)1e9 + 7, inf = (int)1e9;
const ll INF = (ll)1e18;

ll n, b[N], a[N], ans;

int main(){
	cin.tie(0);
	cout.tie(0);
	ios_base::sync_with_stdio(NULL);

	cin >> n;
	for(int i = 1; i <= n; ++i){
		cin >> b[i];
		a[1000000 + i - b[i]] += b[i];
	}

	for(int i = 1; i <= 2000000; ++i)
		ans = max(ans, a[i]);


	cout << ans;
	return 0;
}