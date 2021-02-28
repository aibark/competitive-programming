#include <stdio.h>
#include <bits/stdc++.h>

#define f first
#define s second
#define pb push_back
#define mp make_pair
#define all(x) x.begin(), x.end()

typedef long long ll;

using namespace std;

const int N = 501, mod = (int)1e9 + 7, inf = (int)1e9;
const ll INF = (ll)1e18;

int d[N][N][N], a[4][N][N], n, m, q, r[N][N];
string s[N];

int get(int i, int x, int y, int z){
	x--, y--;
	int xa = x + z, ya = y + z;
	return a[i][xa][ya] + a[i][x][y] - a[i][xa][y] - a[i][x][ya];
}

int getd(int z, int xa, int ya, int xb, int yb){
	xa--, ya--;
	return d[z][xb][yb] + d[z][xa][ya] - d[z][xa][yb] - d[z][xb][ya];
}

int main(){
	cin.tie(0);
	cout.tie(0);
	ios_base::sync_with_stdio(NULL);

	cin >> n >> m >> q;

	for(int i = 1; i <= n; ++i){
		cin >> s[i];
		s[i] = '#' + s[i];
		for(int j = 1; j <= m; ++j){
			for(int k = 0; k < 4; ++k)
				a[k][i][j] = a[k][i - 1][j] + a[k][i][j - 1] - a[k][i - 1][j - 1];
			if(s[i][j] == 'R'){
			    a[0][i][j]++;      	
			}else if(s[i][j] == 'G'){
				a[1][i][j]++;
			}else if(s[i][j] == 'B'){
				a[3][i][j]++;
			}else a[2][i][j]++;
		}
	}

	for(int i = 1; i <= n; ++i)
	for(int j = m; j >= 1; --j){
		if(s[i][j] == 'R'){
			if(j + 1 <= m && s[i][j + 1] == 'R')
				r[i][j] = r[i][j + 1] + 1;
			else r[i][j] = 1;
			if(i + r[i][j] * 2 - 1 <= n && j + r[i][j] * 2 - 1 <= m){                                                   
				if(get(0, i, j, r[i][j]) == r[i][j] * r[i][j] && get(1, i, j + r[i][j], r[i][j]) == r[i][j] * r[i][j] && 
					get(2, i + r[i][j], j, r[i][j]) == r[i][j] * r[i][j] && get(3, i + r[i][j], j + r[i][j], r[i][j]) == r[i][j] * r[i][j]){
						d[r[i][j]][i][j]++;
					}
			}
		}
	}
	for(int k = 1; k <= min(n, m); ++k)
	for(int i = 1; i <= n; ++i)
	for(int j = 1; j <= m; ++j)
		d[k][i][j] = d[k][i][j] - d[k][i - 1][j - 1] + d[k][i][j - 1] + d[k][i - 1][j];

	while(q--){
		int xa, ya, xb, yb;
		cin >> xa >> ya >> xb >> yb;
		int l = 1, r = min(xb - xa + 1, yb - ya + 1) / 2;
		while(l <= r){
			int md = (l + r) >> 1;
			if(getd(md, xa, ya, xb - md - md + 1, yb - md - md + 1) > 0)
				l = md + 1;
			else r = md - 1;
		}
		l--;
		l += l;
		l *= l;
		cout << l << endl;
	} 

	return 0;
}