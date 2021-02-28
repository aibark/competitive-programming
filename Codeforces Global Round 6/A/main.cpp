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

int t, n, cnt[10], ok[2], sum;
string s;

int main(){
	cin.tie(0);
	cout.tie(0);
	ios_base::sync_with_stdio(NULL);

	cin >> t;
	while(t--){
		memset(cnt, 0, sizeof cnt);
		ok[0] = ok[1] = 0;
		sum = 0;	
		cin >> s;
		n = s.size();
		for(int i = 0; i < n; ++i)
			cnt[s[i] - '0']++;
		bool OK = 0;
		if(cnt[0]){
			OK = 1;
			cnt[0]--;
		}
		for(int i = 0; i < 10; ++i)
			sum += cnt[i] * i, ok[i % 2] |= (cnt[i] > 0);
		if(OK && ok[0] && sum % 3 == 0)
			cout << "red" << endl;
		else cout << "cyan" << endl;
	}

	return 0;
}