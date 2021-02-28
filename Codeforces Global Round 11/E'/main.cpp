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

void raz(int x){
	for(int i = 0; i < 10; ++i)
		cout << ((x >> i) & 1);
	cout << endl;
}

int main(){
	cin.tie(0);
	cout.tie(0);
	ios_base::sync_with_stdio(NULL);

	int n;
	cin >> n;
	raz(n);
	raz((n * 2));
	raz((n ^ (n * 2)) + n);
	raz((n * 2) + (n ^ (n * 2)) + n);

	return 0;
}