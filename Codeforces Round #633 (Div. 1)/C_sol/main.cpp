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

ll ko[] = {0, 2, 3, 1};

ll fa(ll n){
	n /= 3;
	n -= 5;
	for(int i = 4; i <= 60; i += 2){
		if(n < (1LL << i)){
			return (1LL << i) + n;
		}else n -= (1LL << i);
	}
	return 0;
}

ll fb(ll n){
	n /= 3;
	n -= 5;
	for(int i = 4; i <= 60; i += 2){
		if(n < (1LL << i)){
			ll x = (1LL << i) * 2LL;
			for(int j = i - 2; j >= 0; j -= 2){
				int k = n / (1LL << j);
				x += (1LL << j) * ko[k];
				n %= (1LL << j);
			}
			return x;
		}else n -= (1LL << i);
	}
	return 0;
}

int main(){
	cin.tie(0);
	cout.tie(0);
	ios_base::sync_with_stdio(NULL);

	set <int> s;
	vector <int> v;
	for(int i = 1; i <= 5; ++i){
		int a = 1;
		while(s.find(a) != s.end())
			a++;
		for(int b = a + 1; b <= 100000; ++b)
			if(s.find(b) == s.end() && s.find((a ^ b)) == s.end()){
				v.pb(a);
				v.pb(b);
				v.pb((a ^ b));
				s.insert(a);
				s.insert(b);
				s.insert((a ^ b));
				break;
			}
	}

	int T;
	cin >> T;
	while(T--){
		ll n;
		cin >> n; 
		if(n <= 15){
			cout << v[n - 1] << endl;
			continue;
		}
		if(n % 3 == 1)
			cout << fa(n) << endl;
		else if(n % 3 == 2)
			cout << fb(n) << endl;
		else cout << (fa(n - 2) ^ fb(n - 1)) << endl;
	}



	return 0;
}