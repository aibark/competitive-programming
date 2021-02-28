#include <stdio.h>
#include <bits/stdc++.h>

#define f first
#define s second
#define pb push_back
#define mp make_pair
#define all(x) x.begin(), x.end()

typedef long long ll;

using namespace std;

const int N = (int)1e3 + 123, mod = (int)1e9 + 7, inf = (int)1e9;
const ll INF = (ll)1e18;

int dx[] = {-1, 0, 0, 1};
int dy[] = {0, -1, 1, 0};

int n, m, ans;
vector <pair <int, int> > v;
char s[N][N];
string S[N];
bool used[N][N], usedx[N], usedy[N], wx[N], wy[N];

void dfs(int x, int y){
	used[x][y] = 1;
	v.pb(mp(x, y));
	for(int i = 0; i < 4; ++i){
		int xa = x + dx[i], ya = y + dy[i];
		if(!used[xa][ya] && s[xa][ya] == '#')
			dfs(xa, ya);
	}
}

int main(){
	cin.tie(0);
	cout.tie(0);
	ios_base::sync_with_stdio(NULL);

	cin >> n >> m;
	for(int i = 1; i <= n; ++i){
		cin >> S[i];
		for(int j = 0; j < m; ++j)
			s[i][j + 1] = S[i][j];
	}

	for(int i = 1; i <= n; ++i)
	for(int j = 1; j <= m; ++j){
		if(s[i][j] == '#' && !used[i][j]){
			v.clear();
			dfs(i, j);
			for(auto k : v){
				if(usedx[k.f] || usedy[k.s]){
					cout << -1;
					return 0;
				}
			}
			for(auto k : v)
				usedx[k.f] = usedy[k.s] = 1;
			sort(all(v));
			for(int l = 0; l < v.size(); ++l){
				int r = l;
				while(r + 1 < v.size() && v[l].f == v[r + 1].f)
					r++;
				for(int k = l + 1; k <= r; ++k)
					if(v[k].s != v[k - 1].s + 1){
						cout << -1;
						return 0;
					}
				l = r;
			}
			for(int l = 0; l < v.size(); ++l)
				swap(v[l].f, v[l].s);
			sort(all(v));
			for(int l = 0; l < v.size(); ++l){
				int r = l;
				while(r + 1 < v.size() && v[l].f == v[r + 1].f)
					r++;
				for(int k = l + 1; k <= r; ++k)
					if(v[k].s != v[k - 1].s + 1){
						cout << -1;
						return 0;
					}
				l = r;
			}
			ans++;
		}
	}

	for(int i = 1; i <= n; ++i)
	for(int j = 1; j <= m; ++j)
		if(!usedx[i] && !usedy[j]){
			wx[i] = 1, wy[j] = 1;
		}
	for(int i = 1; i <= n; ++i)
		if(!usedx[i] && !wx[i]){
			cout << -1;
			return 0;
		}

	for(int i = 1; i <= m; ++i)
		if(!usedy[i] && !wy[i]){
			cout << -1;
			return 0;
		}
	cout << ans;

	return 0;
}