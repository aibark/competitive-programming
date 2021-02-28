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

	int n;
	cin >> n;
	set <pair <int, int> > s;
	for(int i = 1; i <= n + 1; ++i){
		s.insert(mp(i, i));
		s.insert(mp(i - 1, i - 1));
		s.insert(mp(i - 1, i));
		s.insert(mp(i, i - 1));
	}
	cout << s.size() << endl;
	for(auto i : s)
		cout << i.f << " " << i.s << endl;

	return 0;
}