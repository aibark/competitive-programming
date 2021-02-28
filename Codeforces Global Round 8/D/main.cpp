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

int n, a[100];
ll ans;

int main(){
	cin.tie(0);
	cout.tie(0);
	ios_base::sync_with_stdio(NULL);

	cin >> n;
	for(int i = 1; i <= n; ++i){
		int x;
		cin >> x;
		for(int j = 0; j < 20; ++j)
			if((x >> j) & 1)
				a[j]++;
	}
	for(int i = 0; i < 20; ++i){
		ll x = 0;
		ll mn = n;
		for(int j = 0; j < 20; ++j){
			if(a[j] == 0)
				continue;
			x ^= (1LL << j);
			mn = min(mn, (ll)a[j]);
		}
		if(x == 0)
			break;
		for(int j = 0; j < 20; ++j)
			if(a[j] > 0)
				a[j] -= mn;
		ans += x * x * mn;
	}
	cout << ans;
	
	return 0;
}