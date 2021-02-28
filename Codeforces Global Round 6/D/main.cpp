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

int n, m;
ll a[N], b[N];
vector <pair <pair <int, int>, ll> > g;
vector <pair <ll, int> > A, B;

int main(){
	cin.tie(0);
	cout.tie(0);
	ios_base::sync_with_stdio(NULL);

	cin >> n >> m;
	for(int i = 1; i <= m; ++i){
		int x, y, cost;
		cin >> x >> y >> cost;
		if(x == 1){
			a[y] += cost;
		}else if(y == 1){
			b[x] += cost;
		}else{
		    a[y] += cost;
		    b[x] += cost;
		}
	}
	for(int i = 1; i <= n; ++i){
		ll mn = min(a[i], b[i]);
		a[i] -= mn;
		b[i] -= mn;
		if(a[i]){
			A.pb(mp(a[i], i));
		}else if(b[i]){
			B.pb(mp(b[i], i));
		}
	}
	int i = 0, j = 0;
	while(i < A.size() && j < B.size()){
		ll mn = min(A[i].f, B[j].f);
		A[i].f -= mn;
		B[j].f -= mn;
		g.pb(mp(mp(B[j].s, A[i].s), mn));
		if(A[i].f == 0)
			i++;
		if(B[j].f == 0)
			j++;
	}
	while(i < A.size()){
		g.pb(mp(mp(1, A[i].s), A[i].f));
		i++;
	}
	while(j < B.size()){
		g.pb(mp(mp(B[j].s, 1), B[j].f));
		j++;
	}
	cout << g.size() << endl;
	for(auto i : g){
		cout << i.f.f << " " << i.f.s << " " << i.s << endl;
	}

	return 0;
}