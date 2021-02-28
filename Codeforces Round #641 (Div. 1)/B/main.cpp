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

int n, k, a[N];

void solve(){
	cin >> n >> k;
	for(int i = 1; i <= n; ++i)
		cin >> a[i];
	if(n == 1){
		if(a[1] == k)
			cout << "yes" << endl;
		else cout << "no" << endl;
		return;
	}
	bool ok = 0;              	
	for(int i = 1; i <= n; ++i)
		if(a[i] == k)
			ok = 1;
	if(!ok){
		cout << "no" << endl;
		return;
	}
	for(int i = 1; i < n; ++i)
		if(a[i] == k && a[i + 1] >= k){
			cout << "yes" << endl;
			return;
		}
	for(int i = 1; i < n; ++i)
		if(a[i] >= k && a[i + 1] == k){
			cout << "yes" << endl;
			return;
		}	
	for(int i = 1; i <= n; ++i){
		if(a[i] == k){
			int bal = 0;
			for(int j = i + 1; j <= n; ++j){
				if(a[j] >= k)
					bal++;
				else bal--;
				if(bal >= 0){
					cout << "yes" << endl;
					return;
				}
				if(a[j] == k)
					break;
			}
			bal = 0;
			for(int j = i - 1; j >= 1; --j){
				if(a[j] >= k)
					bal++;
				else bal--;
				if(bal >= 0){
					cout << "yes" << endl;
					return;
				}
				if(a[j] == k)
					break;
			}
		}
	}
	cout << "no" << endl;
}

int main(){
	cin.tie(0);
	cout.tie(0);
	ios_base::sync_with_stdio(NULL);

	int T;
	cin >> T;
	while(T--)
		solve();

	return 0;
}