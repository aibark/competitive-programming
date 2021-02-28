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

vector <pair <int, int> > ij;
vector <int> x;
int n, a[N], sum, T;

int main(){
	cin.tie(0);
	cout.tie(0);
	ios_base::sync_with_stdio(NULL);

	cin >> T;
	while(T--){
		cin >> n;
		for(int i = 1; i <= n; ++i)
			cin >> a[i], sum += a[i];
		if(sum % n != 0){
			sum = 0;
			cout << "-1" << endl;
			continue;
		}
		for(int i = 2; i <= n; ++i){
			if(a[i] % i == 0){
			    ij.pb(mp(i, 1));
			    x.pb(a[i] / i);
			}else{
				ij.pb(mp(1, i));
				x.pb(i - a[i] % i);
				ij.pb(mp(i, 1));
				x.pb(a[i] / i + 1);
			}	         	
			a[1] += a[i];
			a[i] = 0;
		}
		for(int i = 2; i <= n; ++i){
			ij.pb(mp(1, i));
			x.pb(sum / n);
		}
		cout << ij.size() << endl;
		for(int i = 0; i < (int)ij.size(); ++i)	
			cout << ij[i].f << " " << ij[i].s << " " << x[i] << endl;
		ij.clear(), x.clear(), sum = 0;
	}
	
	return 0;
}