#include <stdio.h>
#include <bits/stdc++.h>

#define f first
#define s second
#define pb push_back
#define mp make_pair
#define all(x) x.begin(), x.end()

typedef long long ll;

using namespace std;

const int N = (int)2e3 + 123, mod = (int)1e9 + 7, inf = (int)1e9;
const ll INF = (ll)1e18;

int n, k, b[N][10];
bool dp[N][N];

string t[] = {
"1110111",
"0010010",
"1011101",
"1011011",
"0111010",
"1101011",
"1101111",
"1010010",
"1111111",
"1111011"
};

int main(){
	cin.tie(0);
	cout.tie(0);
	ios_base::sync_with_stdio(NULL);
	
	cin >> n >> k;

	for(int i = 1; i <= n; ++i){
		string s;
		cin >> s;
		for(int j = 0; j < 10; ++j){
			for(int e = 0; e < 7; ++e)
				if(s[e] != t[j][e]){
					if(s[e] == '0')
						b[i][j]++;
					else b[i][j] = 2001;
				}
		}
	}
	for(int i = 1, j = n; i < j; ++i, --j)
	for(int e = 0; e < 10; ++e)
		swap(b[i][e], b[j][e]);
	dp[0][0] = 1;
	for(int i = 1; i <= n; ++i)
	for(int sum = 0; sum <= k; ++sum)
	for(int j = 0; j < 10; ++j)
		if(b[i][j] + sum <= k)
			dp[i][b[i][j] + sum] |= dp[i - 1][sum];

	if(dp[n][k] == 0){
		cout << -1;
		return 0;
	}

	for(int i = n; i >= 1; --i){
		for(int j = 9; j >= 0; --j)
			if(k >= b[i][j] && dp[i - 1][k - b[i][j]] == 1){
				cout << j;
				k -= b[i][j];
				break;
			}
	}

	return 0;
}