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



int main(){
	cin.tie(0);
	cout.tie(0);
	ios_base::sync_with_stdio(NULL);

	int t;
	cin >> t;
	while(t--){
		string a, b, c;
		cin >> a >> b >> c;
		int n = a.size();
		for(int i = 0; i < n; ++i){
			if(c[i] == a[i])
				swap(c[i], b[i]);
			else swap(c[i], a[i]);	
		}
		if(a == b){
			cout << "YES" << endl;
		}else cout << "NO" << endl;
	}

	return 0;
}