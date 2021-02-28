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

	set <int> s;
	for(int i = 1; i <= 30; ++i){
		int a = 1;
		while(s.find(a) != s.end())
			a++;
		for(int b = a + 1; b <= 100000; ++b)
			if(s.find(b) == s.end() && s.find((a ^ b)) == s.end()){
				int c = (a ^ b);
				cout << a << " " << b << " " << c << endl;
				s.insert(a);
				s.insert(b);
				s.insert((a ^ b));
				break;
			}
	}

	return 0;
}