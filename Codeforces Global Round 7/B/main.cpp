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
ll b[N], a[N], x[N];

int main(){
	cin.tie(0);
	cout.tie(0);
	ios_base::sync_with_stdio(NULL);

	cin >> n;
	for(int i = 1; i <= n; ++i)
		cin >> b[i];

	a[1] = b[1];
	for(int i = 2; i <= n; ++i){
		x[i] = max(x[i - 1], a[i - 1]);
		a[i] = b[i] + x[i];	
	}

	for(int i = 1; i <= n; ++i)
		cout << a[i] << " ";

	return 0;
}