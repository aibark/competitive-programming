#include <stdio.h>
#include <bits/stdc++.h>

#define f first
#define s second
#define pb push_back
#define mp make_pair
#define all(x) x.begin(), x.end()

typedef long long ll;

using namespace std;

const int N = (int)5e2 + 123, mod = (int)1e9 + 7, inf = (int)1e9;
const ll INF = (ll)1e18;

int n, m, a[N][N];

int main(){
	cin.tie(0);
	cout.tie(0);
	ios_base::sync_with_stdio(NULL);

	cin >> n >> m;
	if(n == m && m == 1){
		cout << 0;
		return 0;
	}
	if(m == 1){
		for(int i = 1; i <= n; ++i)
			cout << i + 1 << endl;
		return 0;
	}
	for(int i = 1; i <= n; ++i, cout << endl)
	for(int j = 1; j <= m; ++j)
		cout << i * (j + n) << " ";
	/*
	for(int i = 1; i <= n; ++i){
		int gcd = 0;
		for(int j = 1; j <= m; ++j)
			gcd = __gcd(gcd, a[i][j]);
		cout << gcd << " ";
	}	
	cout << endl;
	for(int j = 1; j <= m; ++j){
		int gcd = 0;
		for(int i = 1; i <= n; ++i)
			gcd = __gcd(gcd, a[i][j]);
		cout << gcd << " ";
	}  */

	return 0;
}