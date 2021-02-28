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

int n, a[N], b[N], ansx, ansy;

bool check(int d){
	int xa = -inf, ya = -inf, xb = inf, yb = inf;
	int mx = inf, mn = -inf;
	for(int i = 1; i <= n; ++i){
		xa = max(xa, a[i] - d);
		ya = max(ya, b[i] - d);
		xb = min(xb, a[i] + d);
		yb = min(yb, b[i] + d);
		mx = min(mx, a[i] + b[i] + d);
		mn = max(mn, a[i] + b[i] - d);
	}
	if(xa > xb || ya > yb || mn > mx)
		return 0;
	for(int x = xa; x <= xb; ++x){      	
		int y = max(mn - x, ya);
		if(y > yb || x + y > mx)
			continue; 	
		if(x < 0 || y > 2000000)
			continue;
		if(x == 0 && y == 2000000)          	
			continue;
		ansx = x, ansy = 2000000 - y;
		return 1;
	}
	return 0;
}

int main(){
	cin.tie(0);
	cout.tie(0);
	ios_base::sync_with_stdio(NULL);

	cin >> n;
	for(int i = 1; i <= n; ++i){
		string s;
		cin >> s;
		for(int j = 0; j < (int)s.size(); ++j)
			if(s[j] == 'B')
				a[i]++;
			else b[i]++;
		b[i] = 2000000 - b[i];
	}
	int l = 0, r = 1000000; 
	while(l <= r){
		int md = (l + r) >> 1;
		if(check(md))
			r = md - 1;
		else l = md + 1;
	}

	cout << r + 1 << endl;
	for(int i = 1; i <= ansx; ++i)
		cout << 'B';
	for(int i = 1; i <= ansy; ++i)
		cout << 'N';

	return 0;
}