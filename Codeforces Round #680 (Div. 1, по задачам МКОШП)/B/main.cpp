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

int n, a[N], b[N], ans;

void rec(int na, vector <int> x, vector <int> y){
	if(na == n){
		for(int i = 0; i < n / 2; ++i){
			if(x[i] > y[i])
				a[x[i]]++, a[y[i]]--;
			else a[x[i]]--, a[y[i]]++;
		}
		return;
	}
	if(x.size() < n / 2){
		x.pb(na + 1);
		rec(na + 1, x, y);
		x.pop_back();
	}
	if(y.size() < n / 2){
		y.pb(na + 1);
		rec(na + 1, x, y);
		y.pop_back();
	}
}

int main(){
	cin.tie(0);
	cout.tie(0);
	ios_base::sync_with_stdio(NULL);

	cin >> n;
	for(int i = 1; i <= n; ++i)
		cin >> b[i];
	sort(b + 1, b + n + 1);

	rec(0, {}, {});
	for(int i = 1; i <= n; ++i)
		ans += b[i] * a[i];
	cout << ans << endl;
	return 0;
	int k = 1;
	for(int i = 1; i < n / 2; ++i)
		k *= 2;

	int g = 0;
	for(int i = 1; i < n; ++i)
		cout << a[i] << " ", g = __gcd(g, a[i]);
	cout << endl;
	cout << "GCD: " << g << endl;
	for(int i = 1; i < n; ++i)
		cout << a[i] / g << " ";	

	return 0;
}