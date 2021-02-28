#include <stdio.h>
#include <bits/stdc++.h>

#define f first   	
#define s second
#define pb push_back
#define mp make_pair
#define all(x) x.begin(), x.end()

typedef long long ll;

using namespace std;

const int N = (int)1e6 + 123, mod = (int)1e9 + 7, inf = (int)1e9;
const ll INF = (ll)1e18;

int n;
ll dp[N][3][3][3], a[N], r1, r2, r3, d;
bool used[N][3][3][3];

ll get(int i, int A, int B, int C){
	if(i == n && A == 0 && B == 0)
		return 0;
	if(i == n - 1 && B == 0 && C == 0)
		return 0;
	if(used[i][A][B][C])
		return dp[i][A][B][C];
	used[i][A][B][C] = 1;
	dp[i][A][B][C] = INF;
	if(B == 0){
		if(A != 0)
			dp[i][A][B][C] = get(i - 1, 0, A, B) + d;
		else dp[i][A][B][C] = get(i + 1, B, C, 2) + d;	
	}else if(B == 1){
	    dp[i][A][B][C] = get(i, A, 0, C) + min(r1, min(r2, r3));
	}else{
		ll d1 = INF, d2 = INF;
		if(A != 0 || i == n)
			d1 = get(i - 1, 0, A, 1) + min(r2, a[i] * min(r1, r3) + r1) + d;
		else d1 = get(i + 1, 1, C, 2) + min(r2, a[i] * min(r1, r3) + r1) + d;
		d2 = get(i, A, 0, C) + min(r1, r3) * a[i] + r3;
		dp[i][A][B][C] = min(d1, d2);
	}
	return dp[i][A][B][C];
}

int main(){
	cin.tie(0);
	cout.tie(0);
	ios_base::sync_with_stdio(NULL);

	cin >> n >> r1 >> r2 >> r3 >> d;
	for(int i = 1; i <= n; ++i)
		cin >> a[i];

	cout << get(1, 0, 2, 2);

	return 0;
}