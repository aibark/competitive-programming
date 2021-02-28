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



int main(){
	cin.tie(0);
	cout.tie(0);
	ios_base::sync_with_stdio(NULL);

	int T;
	cin >> T;
	while(T--){
		int n;
		cin >> n;
		if(n == 1){
			cout << -1 << endl;
			continue;
		}
		cout << 2;
		for(int i = 1; i < n; ++i)
			cout << 3;
		cout << endl;
	}

	return 0;
}