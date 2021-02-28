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

int n, A, B, z;
vector <int> a, b;

int main(){
	cin.tie(0);
	cout.tie(0);
	ios_base::sync_with_stdio(NULL);

	int T;
	cin >> T;
	while(T--){
		cin >> n;
		a.clear();
		b.clear();
		A = B = z = 0;	
		for(int i = 1; i <= n; ++i){
			int x;
			cin >> x;
			if(x > 0){
				a.pb(x);
				A += x;
			}else if(x < 0){
				b.pb(x);
				B += abs(x);
			}else z++;
		}
		if(A == B){
			cout << "NO" << endl;
			continue;
		}
		if(A > B)
			swap(a, b);
		cout << "YES" << endl;
		for(int i : b)
			cout << i << " ";
		for(int i : a)
			cout << i << " ";
		for(int i = 0; i < z; ++i)
			cout << 0 << " ";
		cout << endl;
	}

	return 0;
}