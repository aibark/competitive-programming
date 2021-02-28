#include <bits/stdc++.h>
using namespace std;
int main(){
	int n, m;
	set <int> s, t;
	cin >> n >> m;
	for(int mask = 0; mask < (1 << m); ++mask){
		int x = 0;
		for(int i = 0; i < m; ++i)
			if((mask >> i) & 1)
				x ^= (n << i);
		s.insert(x);
	}
	for(int i : s)
		cout << i << " ";
	for(int i : s){
		for(int j = 0; j < 256; j += n)
			t.insert((i ^ j));
	}
	cout << endl;
	for(int i : t)
		cout << i << " ";
}