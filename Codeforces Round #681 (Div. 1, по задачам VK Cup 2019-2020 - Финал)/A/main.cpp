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

int T, n, a[N], b[N];

int main(){
	cin.tie(0);
	cout.tie(0);
	ios_base::sync_with_stdio(NULL);

	cin >> T;
	while(T--){
		cin >> n;
		for(int i = 1; i <= n; ++i){
			cin >> a[i];
			b[i - 1] = a[i - 1] - a[i];	
		}
		b[n] = 0;
		int bal = 0;
		for(int i = n - 1; i >= 1; --i){
			if(b[i] >= 0)
				bal += b[i];
			a[i] -= bal;
		}
		bal = 0;
		for(int i = 1; i <= n; ++i){
			a[i] -= bal;		
			if(b[i] < 0)
				bal -= b[i];
		}
		bool ok = 1;
		for(int i = 1; i < n; ++i)
			if(a[i] != a[i + 1] || a[i] < 0)
				ok = 0;
		if(ok)
			cout << "YES" << endl;
		else cout << "NO" << endl;
	}

	return 0;
}