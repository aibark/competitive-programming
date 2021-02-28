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

int n;
set <int> s;

int main(){
	cin.tie(0);
	cout.tie(0);
	ios_base::sync_with_stdio(NULL);

	int m;
	cin >> n >> m;
	s.insert(n);
	while(true){
		int a = -1, b = -1;
		for(int i : s)
			if(s.find((i ^ 8)) != s.end()){
				cout << i << " " << (i ^ 8) << endl;
				return 0;
			}
		for(int i : s)
		for(int j : s){
			if((s.find(i + j) == s.end() && i + j < m) || (s.find((i ^ j)) == s.end() && (i ^ j) < m))
				a = i, b = j;
		}
		if(a == -1 && b == -1)
			break;
		if(a + b < m && s.find(a + b) == s.end())
			s.insert(a + b), cout << a << " + " << b << "  = " << a + b << endl; 
		if((a ^ b) < m && s.find(a ^ b) == s.end())
			s.insert(a ^ b), cout << a << " ^ " << b << " = " << (a ^ b) << endl;
	}
	for(int i : s)
		cout << i << " ";

	return 0;
}