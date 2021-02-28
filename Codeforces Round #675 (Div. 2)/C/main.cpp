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
ll suf[N], ans;
       
int main(){
	cin.tie(0);
	cout.tie(0);
	ios_base::sync_with_stdio(NULL);

	cin >> s;

	ll t = 1, x = 0;
	for(int i = s.size() - 1; i > 0; --i){
		x = (x + t * (s[i] - '0')) % mod;
		t *= 10;
		t %= mod;
		ans = (ans + i * x % mod) % mod;		
	} 	
	
	t = 1;
	x = 0;
	for(int i = s.size() - 1; i >= 0; --i){
		suf[i] = (suf[i + 1] + t % mod) % mod;
		t *= 10;
		t %= mod;
	}
	for(int i = 0; i < s.size(); ++i){
		x = (x * 10 + s[i] - '0') % mod;
		ans = (ans + x * suf[i + 1]) % mod;
	}

	cout << ans;

	return 0;
}