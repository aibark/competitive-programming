#include <stdio.h>
#include <bits/stdc++.h>

#define f first
#define s second
#define pb push_back
#define mp make_pair
#define all(x) x.begin(), x.end()

typedef long long ll;

using namespace std;

const int N = (int)5e3 + 123, mod = (int)1e9 + 7, inf = (int)1e9;
const ll INF = (ll)1e18;

int t, n;
string s[N];

int main(){
	cin.tie(0);
	cout.tie(0);
	ios_base::sync_with_stdio(NULL);

	cin >> t;
	while(t--){
		cin >> n >> s[0];
		for(int i = 1; i < n; ++i)
			s[i] = s[i - 1].substr(1, n - 1) + s[i - 1][0];
		int mn = 0;
		for(int i = 1; i < n; ++i){
			if((i + 1) % 2 == n % 2)
				reverse(s[i].begin() + n - i, s[i].end());
			if(s[mn] > s[i])
				mn = i;
		}
		cout << s[mn] << endl << mn + 1 << endl;
	}

	return 0;
}