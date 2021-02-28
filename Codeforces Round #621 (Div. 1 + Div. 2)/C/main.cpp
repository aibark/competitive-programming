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

string s;            
ll ans, a[26][26], cnt[26];
int n;

int main(){
	cin.tie(0);
	cout.tie(0);
	ios_base::sync_with_stdio(NULL);

	cin >> s;
	s = '#' + s;
	n = s.size() - 1;

	for(int i = 1; i <= n; ++i){
		int x = s[i] - 'a';
		for(int j = 0; j < 26; ++j)
			a[j][x] += cnt[j], ans = max(ans, a[j][x]);
		cnt[x]++;
		ans = max(cnt[x], ans);
	}

	cout << ans << endl;

	return 0;
}