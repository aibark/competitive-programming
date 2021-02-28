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

int t;
ll n;

int main(){
	cin.tie(0);
	cout.tie(0);
	ios_base::sync_with_stdio(NULL);

	cin >> t;
	while(t--){
		cin >> n;
		if(n % 7 > 0 && (n / 7) % 2 == 0 && n >= 15)
			cout << "YES" << endl;
		else cout << "NO" << endl;	
	}                               	

	return 0;
}