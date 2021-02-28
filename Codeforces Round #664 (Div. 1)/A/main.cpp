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

int n, d, m;
ll A[N], B[N], suma, sumb, ans;
vector <ll> a, b;

int main(){
	cin.tie(0);
	cout.tie(0);
	ios_base::sync_with_stdio(NULL);

	cin >> n >> d >> m;
	for(int i = 1; i <= n; ++i){
		cin >> A[i];
		if(A[i] > m)
			a.pb(A[i]);
		else b.pb(A[i]), sumb += A[i];
	}

	sort(all(a));
	reverse(all(a));
	sort(all(b));
	for(int i = 1; i <= b.size(); ++i)
		B[i] = B[i - 1] + b[i - 1];
	ans = sumb;
	for(int i = 1; i <= a.size(); ++i){
		suma += a[i - 1];
		int k = a.size() - i;
		if(k < 1LL * (i - 1) * d && 1LL * (i - 1) * d - k <= b.size()){
			ans = max(ans, suma + sumb - B[(i - 1) * d - k]);
		}
		if(k >= 1LL * (i - 1) * d)
			ans = max(ans, suma + sumb);
	}

	cout << ans;

	return 0;
}