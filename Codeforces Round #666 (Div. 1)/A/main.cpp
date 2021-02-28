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

int n;
ll a[N], b[N], d[N];

int main(){
	cin.tie(0);
	cout.tie(0);
	ios_base::sync_with_stdio(NULL);

	cin >> n;
	for(int i = 1; i <= n - 1; ++i){
		cin >> d[i];
		b[i] = d[i] * (n - 1);
		a[i] = -(b[i] + d[i]); 
	}
	cin >> d[n];

	if(n == 1){
		cout << 1 << " " << 1 << endl << 0 << endl;
		cout << 1 << " " << 1 << endl << 0 << endl;
		cout << 1 << " " << 1 << endl << -d[n] << endl;
	}else{
		cout << 1 << " " << n << endl;
		for(int i = 1; i <= n; ++i)
			cout << a[i] << " ";
		cout << endl;
		cout << 1 << " " << n - 1 << endl;
		for(int i = 1; i < n; ++i)
			cout << b[i] << " ";
		cout << endl;
		cout << n << " " << n << endl << -d[n] << endl;
	}

	return 0;
}