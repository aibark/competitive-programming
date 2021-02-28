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

int n, m, k, cur;
vector <pair <int, string> > ans, ansa;

int main(){
	cin.tie(0);
	cout.tie(0);
	ios_base::sync_with_stdio(NULL);

	cin >> n >> m >> k;

	if(k > 4 * n * m - 2 * n - 2 * m){
		cout << "NO";
		return 0;
	}

	cout << "YES" << endl;

	if(m > 1){
		ans.pb(mp(m - 1, "R"));
		ans.pb(mp(m - 1, "L"));
	}

	for(int i = 2; i <= n; ++i){
		ans.pb(mp(1, "D"));
		if(m > 1){
		ans.pb(mp(m - 1, "RUD"));
		ans.pb(mp(m - 1, "L"));
		}
	}
	
	if(n > 1)
	ans.pb(mp(n - 1, "U"));

	for(auto j : ans){
		if(cur == k)
			break;
		if(cur + j.f * j.s.size() > k){
			k -= cur;
			if(k >= j.s.size()){
				ansa.pb(mp(k / j.s.size(), j.s));
				k %= j.s.size();
			}
			if(k > 0)
				ansa.pb(mp(1, j.s.substr(0, k)));
			break;
		}
		ansa.pb(j);
		cur += j.f * j.s.size();
	}

	cout << ansa.size() << endl;
	for(auto i : ansa)
		cout << i.f << " " << i.s << endl;

	return 0;
}