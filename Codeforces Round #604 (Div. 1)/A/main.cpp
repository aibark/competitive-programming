#include <stdio.h>
#include <bits/stdc++.h>

#define f first
#define s second
#define pb push_back
#define mp make_pair
#define all(x) x.begin(), x.end()

typedef long long ll;

using namespace std;

const int N = (int)1e6 + 123, mod = (int)1e9 + 7, inf = (int)1e9;
const ll INF = (ll)1e18;

int n, a[N];

void solve(){
	cin >> n;
	for(int i = 1; i <= n; ++i)
		cin >> a[i];	
	int g = 1;
	while(g < n && a[g + 1] == a[g])
		g++;
	int s = g + 1;
	while(true){
		while(s < n && a[s + 1] == a[s])
			s++;
		if(s - g > g)
			break;
		if(s == n){
			cout << 0 << " " << 0 << " " << 0 << endl;
			return;
		}
		s++;
	}
	int b = s + 1;
	while(true){
		while(b < n && a[b + 1] == a[b])
			b++;
		if(b - s > g)
			break;
		if(b == n){
			cout << 0 << " " << 0 << " " << 0 << endl;
			return;
		}
		b++;
	}
	if(b + b > n){
		cout << 0 << " " << 0 << " " << 0 << endl;
		return;
	}
	while(true){
		int B = b + 1;
		while(B < n && a[B + 1] == a[B])
			B++;
		if(B + B > n)
			break;
		b = B;
	}
	cout << g << " " << s - g << " " << b - s << endl;
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