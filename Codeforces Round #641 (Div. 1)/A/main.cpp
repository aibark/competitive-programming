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

int n, a[N];
ll ans = 1;

int main(){
	cin.tie(0);
	cout.tie(0);
	ios_base::sync_with_stdio(NULL);

	cin >> n;

	for(int i = 1; i <= n; ++i)
		cin >> a[i];

	for(int i = 2; i <= 200000; ++i){
		bool ok = 1;
		for(int j = 2; j * j <= i; ++j)
			if(i % j == 0){
				ok = 0;
				break;
			}
		if(!ok)
			continue;
		int mn1 = 200000, mn2 = 200000;
		for(int j = 1; j <= n; ++j){
			int k = 0;
			while(a[j] % i == 0){
				k++;
				a[j] /= i;
			}
			if(mn2 > k)
				mn2 = k;
			if(mn1 > mn2)
				swap(mn1, mn2);
			if(mn2 == 0)
				break;
		}
		for(int j = 0; j < mn2; ++j)
			ans *= i;
	}

	cout << ans;

	return 0;
}