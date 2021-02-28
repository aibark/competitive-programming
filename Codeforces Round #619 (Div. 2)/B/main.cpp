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

int t, n, a[N];

int main(){
	cin.tie(0);
	cout.tie(0);
	ios_base::sync_with_stdio(NULL);

	cin >> t;
	while(t--){
		cin >> n;
		for(int i = 1; i <= n; ++i){
			cin >> a[i];
		}
		int mn = (int)1e9, mx = -1;
		for(int i = 1; i < n; ++i){
			if(a[i] == -1 && a[i + 1] != -1){
				mn = min(mn, a[i + 1]);
				mx = max(mx, a[i + 1]);
			}
			if(a[i] != -1 && a[i + 1] == -1){
				mn = min(mn, a[i]);
				mx = max(mx, a[i]);
			}
		}
		if(mx == -1)
			mx = mn = 0;
		int x = (mx + mn) / 2;
		int ans = 0;
		for(int i = 1; i <= n; ++i){
			if(a[i] == -1)
				a[i] = x;
			if(1 < i)
				ans = max(ans, abs(a[i] - a[i - 1]));
		}
		cout << ans << " " << x << endl;
	}

	return 0;
}