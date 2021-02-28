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

int ans;

int main(){
	cin.tie(0);
	cout.tie(0);
	ios_base::sync_with_stdio(NULL);

	int n;
	cin >> n;
	for(int i = 2; i <= n; ++i){
		bool ok = 1;
		for(int j = 2; j * j <= i; ++j)
			if(i % j == 0)
				ok = 0;
		if(ok)
			ans++;
	}
	cout << ans;

	return 0;
}