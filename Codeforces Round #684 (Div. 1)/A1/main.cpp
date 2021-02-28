#include <stdio.h>
#include <bits/stdc++.h>

#define f first
#define s second
#define pb push_back
#define mp make_pair
#define all(x) x.begin(), x.end()

typedef long long ll;

using namespace std;

const int N = (int)123, mod = (int)1e9 + 7, inf = (int)1e9;
const ll INF = (ll)1e18;

int dx[] = {0, 0, 1, 1};
int dy[] = {0, 1, 0, 1};

vector <pair <pair <int, int>, int> > ansv;
int a[N][N], n, m;

void get(int x, int y, int z){
	for(int i = 0; i < 4; ++i)
		if(i != z)
			a[x + dx[i]][y + dy[i]] ^= 1;
}

int main(){
	cin.tie(0);
	cout.tie(0);
	ios_base::sync_with_stdio(NULL);

	int T;
	cin >> T;
	while(T--){
		ansv.clear();
		cin >> n >> m;
		for(int i = 1; i <= n; ++i)
		for(int j = 1; j <= m; ++j){
			char c;
			cin >> c;
			a[i][j] = c - '0';
		}
		for(int i = n; i >= 3; --i){
			for(int j = 1; j < m; ++j)
				if(a[i][j]){
					get(i - 1, j, 1);
					ansv.pb(mp(mp(i - 1, j), 1));
				}
			if(a[i][m]){
				get(i - 1, m - 1, 2);
				ansv.pb(mp(mp(i - 1, m - 1), 2));
			}	
		}
		for(int j = m; j >= 3; --j){
			if(a[1][j]){
				get(1, j - 1, 0);
				ansv.pb(mp(mp(1, j - 1), 0));
			}
			if(a[2][j]){
				get(1, j - 1, 1);
				ansv.pb(mp(mp(1, j - 1), 1));
			}
		}
		int mn = 127;
		for(int mask = 0; mask < (1 << 4); ++mask){
			for(int i = 0; i < 4; ++i)
				if((mask >> i) & 1)
					get(1, 1, i);
			bool ok = 1;
			for(int i = 1; i <= 2; ++i)
			for(int j = 1; j <= 2; ++j)	
				if(a[i][j] == 1)
					ok = 0;
			if(ok && __builtin_popcount(mask) < __builtin_popcount(mn))
				mn = mask;
			for(int i = 0; i < 4; ++i)
				if((mask >> i) & 1)
					get(1, 1, i);
		}
		for(int i = 0; i < 4; ++i)
			if((mn >> i) & 1)
				ansv.pb(mp(mp(1, 1), i)), get(1, 1, i);
		cout << ansv.size() << endl;
		for(auto i : ansv){
			for(int j = 0; j < 4; ++j)	
				if(j != i.s)
					cout << i.f.f + dx[j] << " " << i.f.s + dy[j] << " ";
			cout << endl;
		}
	}

	return 0;
}