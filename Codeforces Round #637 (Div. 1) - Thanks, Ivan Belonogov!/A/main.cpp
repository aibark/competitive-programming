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

int n, p[N], pos[N];

int main(){
	cin.tie(0);
	cout.tie(0);
	ios_base::sync_with_stdio(NULL);

	int t;
	cin >> t;
	while(t--){
		cin >> n;
		for(int i = 1; i <= n; ++i){
			cin >> p[i];
			pos[p[i]] = i;
		}
		int m = n + 1;
		bool ok = 1;
		for(int i = 1; i <= n; ++i){
			if(m + 1 < pos[i]){
				ok = 0;
			}
			m = pos[i];
		}
		if(ok)
			cout << "Yes" << endl;
		else cout << "No" << endl;
	}

	return 0;
}