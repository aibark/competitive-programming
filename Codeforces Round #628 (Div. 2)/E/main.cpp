#include <stdio.h>
#include <bits/stdc++.h>

#define f first
#define s second
#define pb push_back
#define mp make_pair
#define all(x) x.begin(), x.end()

typedef long long ll;

using namespace std;

const int N = (int)2e6 + 123, mod = (int)1e9 + 7, inf = (int)1e9;
const ll INF = (ll)1e18;

int n, ans, ok[N];
vector <int> v;

int main(){
	cin.tie(0);
	cout.tie(0);
	ios_base::sync_with_stdio(NULL);

	cin >> n;
	for(int i = 2; i <= n; i++){
		if(ok[i])
			continue;
		v.pb(i);
		for(int j = i + i; j <= n; j += i)
			ok[j] = 1;
	}
	

	cout << v.size() << endl;
	int j = v.size() - 1;
	for(int i = 0; i < v.size(); ++i){
		while(j >= 0 && v[i] * v[j] > n)
			j--;
		ans += j + 1;
	}

	cout << ans;

	return 0;
}