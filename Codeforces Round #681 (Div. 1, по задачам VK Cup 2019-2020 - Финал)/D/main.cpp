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

int n, a[N], b[N], dp2[N], prefa[N], prefb[N];

int main(){
	cin.tie(0);
	cout.tie(0);
	ios_base::sync_with_stdio(NULL);
	srand(time(NULL));

	cin >> n;
	for(int i = 1; i <= n; ++i)
		a[i] = rand() % 100, b[i] = rand() % 100;

	sort(a + 1, a + n + 1);
	sort(b + 1, b + n + 1);
	for(int i = 1; i <= n; ++i)
		cout << a[i] << " ";
	cout << endl;
	for(int j = 1; j <= n; ++j)	
		cout << b[j] << " ";
	cout << endl;
	for(int i = 1; i <= n; ++i)
		prefa[i] = prefa[i - 1] + a[i], prefb[i] = prefb[i - 1] + b[i];
	for(int i = 0; i <= n + n; ++i)
		dp2[i] = -inf;

	for(int j = 0; j <= n; ++j){
		for(int i = 0; i <= n; ++i)
			dp2[i + j] = max(dp2[i + j], prefa[i] + prefb[j]);
		for(int i = 1; i <= n + n; ++i)
			cout << dp2[i] - dp2[i - 1] << " ";
		cout << endl;
	}

	for(int i = 1; i <= n; ++i)
		cout << prefa[i] - prefa[i - 1] << " ";
	cout << endl;

	return 0;
}