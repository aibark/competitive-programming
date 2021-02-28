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
char dc[] = {'D', 'R', 'L', 'U'};

int n;
pair <int, int> a[N][N];
char c[N][N];
queue <pair <int, int> > q;

int main(){
	cin.tie(0);
	cout.tie(0);
	ios_base::sync_with_stdio(NULL);

	cin >> n;
	for(int i = 1; i <= n; ++i)
	for(int j = 1; j <= n; ++j){
		cin >> a[i][j].f >> a[i][j].s;
		if(a[i][j] == mp(i, j)){
			c[i][j] = 'X';
			q.push(mp(i, j));
		}else c[i][j] = '#';
		if(i > 1 && a[i][j] == mp(-1, -1) && a[i][j] == a[i - 1][j]){
			c[i][j] = 'U';
			c[i - 1][j] = 'D';
			q.push(mp(i, j));
			q.push(mp(i - 1, j));
		}else if(j > 1 && a[i][j] == mp(-1, -1) && a[i][j] == a[i][j - 1]){
			c[i][j] = 'L';
			c[i][j - 1] = 'R';
			q.push(mp(i, j));
			q.push(mp(i, j - 1));
		}

	}
	while(!q.empty()){
		int x = q.front().f, y = q.front().s;
		q.pop();
		for(int i = 0; i < 4; ++i){
			int xa = x + dx[i], ya = y + dy[i];
			if(xa >= 1 && xa <= n && ya >= 1 && ya <= n && c[xa][ya] == '#' && a[xa][ya] == a[x][y]){
				c[xa][ya] = dc[i];
				q.push(mp(xa, ya));
			}
		}
	}
	for(int i = 1; i <= n; ++i)
	for(int j = 1; j <= n; ++j){
		if(c[i][j] == '#'){
			cout << "INVALID";
			return 0;
		}
	}
	cout << "VALID" << endl;
	for(int i = 1; i <= n; ++i, cout << endl)
	for(int j = 1; j <= n; ++j)
		cout << c[i][j];


	return 0;
}