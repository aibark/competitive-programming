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

bool used[101][101][101][3], g[101][101][101][3];
int n, cnt[N];

bool rec(int a, int b, int c, int d){
	if(used[a][b][c][d])
		return g[a][b][c][d];
	used[a][b][c][d] = 1;
	if(a > 1 || (a == 1 && d != 0))
		g[a][b][c][d] |= (1 ^ rec(a - 1, b, c, 2));
	if(b > 1 || (b == 1 && d != 1))
		g[a][b][c][d] |= (1 ^ rec(a + 1, b - 1, c, 0));
	if(c > 0 )
		g[a][b][c][d] |= (1 ^ rec(a, b + 1, c - 1, 1));
	return g[a][b][c][d];
}

int main(){
	cin.tie(0);
	cout.tie(0);
	ios_base::sync_with_stdio(NULL);

	int T;
	cin >> T;

	used[0][0][0][1] = used[0][0][0][0] = used[0][0][0][2] = 1;
	while(T--){
	memset(cnt, 0, sizeof cnt);
	cin >> n;                                                  
	for(int i = 1; i <= n; ++i){
		int x;
		cin >> x;
		cnt[x % 4]++;
	}
	int A = cnt[1], B = cnt[2], C = cnt[3];
	bool ok = 0;
	if(A > 0 && !rec(A - 1, B, C, 2))
		ok = 1;
	if(B > 0 && !rec(A + 1, B - 1, C, 0))
		ok = 1;
	if(C > 0 && !rec(A, B + 1, C - 1, 1))
		ok = 1;
	if(ok)
		cout << "T" << endl;
	else cout << "HL" << endl;
	}

	return 0;
}