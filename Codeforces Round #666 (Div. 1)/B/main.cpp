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

int n, a[N];

bool rec(int last){
	for(int i = 1; i <= n; ++i){
		if(i == last || a[i] == 0)
			continue;
		a[i]--;
		bool ok = rec(i);
		a[i]++;
		if(!ok)
			return 1;
	}
	return 0;
} 

int main(){
	cin.tie(0);
	cout.tie(0);
	ios_base::sync_with_stdio(NULL);

	cin >> n;
	int s = 0;
	for(int i = 1; i <= n; ++i)
		cin >> a[i], s ^= a[i];

	if(rec(0))
		cout << "T" << endl;
	else cout << "HL" << endl;

	return 0;
}