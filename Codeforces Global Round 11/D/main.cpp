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

vector <vector <int> > a, ans;
int n, A[N];

int main(){
	cin.tie(0);
	cout.tie(0);
	ios_base::sync_with_stdio(NULL);

	cin >> n;

	for(int i = 1; i <= n; ++i){
		cin >> A[i];
	}

	for(int i = 1; i <= n; ++i){
		int j = i;
		while(j < n && A[j + 1] == A[j] + 1)
			j++;
		vector <int> v;
		for(int ii = i; ii <= j; ii++)
			v.pb(A[ii]);
		a.pb(v);
		i = j;
	}

	while(true){
		int x = -1, y = -1;
		for(int i = 0; i < (int)a.size(); ++i)
		for(int j = i + 1; j < (int)a.size(); ++j)
			if(a[i][0] - 1 == a[j].back())
				x = i, y = j;
		if(x == -1 && y == -1)
			break;
		vector <int> d;
		if(x > 0){
			int z = 0;
			for(int i = 0; i < x; ++i)
				z += a[i].size();
			d.pb(z);
	
		}
		{
			int z = 0;
			for(int i = x; i < y; ++i)
				z += a[i].size();
			d.pb(z);
		}
		{
			d.pb(a[y].size());
		}
		if(y + 1 < (int)a.size()){
			int z = 0;
			for(int i = y + 1; i < (int)a.size(); ++i)
				z += a[i].size();
			d.pb(z);
		}
		vector <vector <int> > nw;
		for(int i = y + 1; i < (int)a.size(); ++i)
			nw.pb(a[i]);
		nw.pb(a[y]);
		for(int j : a[x])
			nw.back().pb(j);
		for(int i = x + 1; i < y; ++i)
			nw.pb(a[i]);
		for(int i = 0; i < x; ++i)	
			nw.pb(a[i]);
		ans.pb(d);
		a = nw;
	}

	cout << ans.size() << endl;
	for(auto i : ans){
		cout << i.size() << " ";
		for(int j : i)
			cout << j << " ";
		cout << endl;
	}

	return 0;
}