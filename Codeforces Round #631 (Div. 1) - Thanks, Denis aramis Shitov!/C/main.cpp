#include <stdio.h>
#include <bits/stdc++.h>

#define f first
#define s second
#define pb push_back
#define mp make_pair
#define all(x) x.begin(), x.end()

typedef long long ll;

using namespace std;

const int N = (int)3e6 + 123, mod = (int)1e9 + 7, inf = (int)1e9;
const ll INF = (ll)1e18;

int n, g, a[N];
ll ans;
vector <int> ansv;

int get(int i){
	if(a[i + i] == 0 && a[i + i + 1] == 0)
		return i;
	if(a[i + i] > a[i + i + 1])
		return get(i + i);
	return get(i + i + 1);
}

void rec(int i){
	if(a[i + i] == 0 && a[i + i + 1] == 0){
		a[i] = 0;
		return;
	}
	if(a[i + i] > a[i + i + 1]){
		a[i] = a[i + i];
		rec(i + i);
	}else{
		a[i] = a[i + i + 1];
		rec(i + i + 1);
	}
}

void solve(){
	cin >> n >> g;
	n = (1 << n) - 1;
	g = (1 << g) - 1;
	ansv.clear();
	ans = 0;
	for(int i = 1; i <= n; ++i)
		cin >> a[i];
	for(int i = 1; i <= g; ++i){
		while(true){
			int j = get(i);
			if(j <= g)
				break;
			ansv.pb(i);
			rec(i);
		}
		ans += a[i];
	}
	cout << ans << endl;
	for(int i : ansv)
		cout << i << " ";
	cout << endl;	
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