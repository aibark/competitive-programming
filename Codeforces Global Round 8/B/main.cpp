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



int main(){
	cin.tie(0);
	cout.tie(0);
	ios_base::sync_with_stdio(NULL);

	ll k, cnt = 1;
	multiset <ll> s;
	for(int i = 1; i <= 10; ++i)
		s.insert(1);
	cin >> k;
	while(cnt < k){
		ll x = *s.begin();
		s.erase(s.begin());
		cnt /= x;
		x++;
		cnt *= x;
		s.insert(x);
	}
	string t = "codeforces";
	for(int i = 0; i < 10; ++i){
		ll x = *s.begin();
		s.erase(s.begin());
		while(x){
			cout << t[i];
			x--;
		}
	}

	return 0;
}