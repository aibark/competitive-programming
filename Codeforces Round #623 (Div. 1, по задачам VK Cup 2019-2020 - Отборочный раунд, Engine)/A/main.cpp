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

int n, last;
pair <int, int> a[N];
ll sum, ans;
multiset <int> s;

int main(){
	cin.tie(0);
	cout.tie(0);
	ios_base::sync_with_stdio(NULL);

	cin >> n;
	for(int i = 1; i <= n; ++i){
		cin >> a[i].f;
	}
	for(int i = 1; i <= n; ++i)
		cin >> a[i].s;
	sort(a + 1, a + n + 1);

	for(int i = 1; i <= n; ++i){
		while(last < a[i].f && s.size() > 0){
			sum -= *s.rbegin();	
			s.erase(s.find(*s.rbegin()));
			ans += sum;
			last++;
		}
		int r = i;
		while(r + 1 <= n && a[r + 1].f == a[i].f)
			r++;
		for(int j = i; j <= r; ++j)
			s.insert(a[j].s), sum += a[j].s;
		sum -= *s.rbegin();
		s.erase(s.find(*s.rbegin()));
		last = a[r].f + 1;
		ans += sum;
		i = r;
	}
	while(s.size() > 0){
		sum -= *s.rbegin();	
		s.erase(s.find(*s.rbegin()));
		ans += sum;
	}
	
	cout << ans << endl;

	return 0;
}