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

int n, k;
string s;

void solve(){
	cin >> n >> k;
	cin >> s;
	s = 'L' + s;
	int ans = 0, A = 0, B = 0;
	vector <int> a;
	for(int i = 1; i <= n; ++i){
		if(s[i] == 'W'){
			if(s[i - 1] == 'W')
				ans += 2;
			else ans++;
		}else{
			int r = i;
			while(r < n && s[r + 1] == 'L')
				r++;
			if(i == 1)
				A = r - i + 1;
			else if(r == n)
				B = r - i + 1;
			else a.pb(r - i + 1);
			i = r;
		}
	}
	if(A == n){
		cout << max(0, k * 2 - 1) << endl;
		return;
	}
	sort(all(a));
	for(int i : a){
		if(i <= k){
			ans += i * 2 + 1;
			k -= i;
		}else{
			ans += k * 2;
			k = 0;
			break;
		}
	}
	ans += min(k, A + B) * 2;
	cout << ans << endl;
}

int main(){
	cin.tie(0);
	cout.tie(0);
	ios_base::sync_with_stdio(NULL);
	
	int T;
	cin >> T;
	while(T--)
		solve();

	return 0;
}