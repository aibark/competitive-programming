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

ll n, m;
set <ll> s;
vector <pair <int, pair <ll, ll> > > ans;

bool ok(ll x){
	while(x % 2 == 0)
		x /= 2;
	x++;
	while(x % 2 == 0)
		x /= 2;
	return (x == 1);
}
void add(ll x, ll y){
	s.insert(x + y);
	ans.pb(mp(0, mp(x, y)));
}

void hor(ll x, ll y){
	s.insert((x ^ y));
	ans.pb(mp(1, mp(x, y)));
}

int main(){
	cin.tie(0);
	cout.tie(0);
	ios_base::sync_with_stdio(NULL);

	cin >> n;
	m = n;
	s.insert(n);
	while(!ok(n)){
		add(n, n);
		hor(n, n * 2);
		add(n * 2, (n ^ (n * 2)));
		add(n, n * 2 + (n ^ (n * 2)));
		n = (n * 2) + (n ^ (n * 2)) + n;
	}
	add(n, n);
	hor(n, n * 2);
	add((n ^ (n * 2)), n);
	n = (n ^ (n * 2)) + n;
	int k = 0;
	while(n % 2 == 0)
		n /= 2, k++;
	while(k){
		ll x = m;
		for(ll i : s)
			if(i % (1LL << k) != 0)
				x = i;
		for(int i = 60; i >= k; --i)
			if(((x >> i) & 1)){
				hor(x, (1LL << i));
				x ^= (1LL << i);
			}
		while(x != (1LL << (k - 1))){
			if(x < (1LL << k)){
				add(x, x);
				x *= 2;
			}else{
				hor(x, (1LL << k));
				x ^= (1LL << k);	
			}
		}
		k--;
	}

	cout << ans.size() << endl;
	for(auto i : ans)
		if(i.f == 0)
			cout << i.s.f << " + " << i.s.s << endl;
		else cout << i.s.f << " ^ " << i.s.s << endl;
	return 0;
}