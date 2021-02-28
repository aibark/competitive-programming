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

int T, n, a[N], l, r;

int main(){
	cin.tie(0);
	cout.tie(0);
	ios_base::sync_with_stdio(NULL);

	cin >> T;
	while(T--){
		cin >> n;
		for(int i = 1; i <= n; ++i){
			int x;
			cin >> x;
			a[x] = i;
		}
		l = n, r = 0;
		for(int i = 1; i <= n; ++i){
			l = min(l, a[i]);
			r = max(r, a[i]);
			if(r - l + 1 == i)
				cout << 1;
			else cout << 0;
		}
		cout << endl;
	}

	return 0;
}