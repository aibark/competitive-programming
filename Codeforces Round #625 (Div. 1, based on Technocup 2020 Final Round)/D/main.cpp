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

map <string, int> m;

void dfs(string s){
	m[s]++;
	for(int i = 0; i + 2 < s.size(); ++i){
		string to = s;
		if(s[i] != s[i + 2] && s[i + 1] == '1'){
			swap(to[i], to[i + 2]);
			if(!m.count(to))
				dfs(to);
		}
	}
}

int main(){
	cin.tie(0);
	cout.tie(0);
	ios_base::sync_with_stdio(NULL);

	string t;
	cin >> t;
	dfs(t);

	for(auto i : m){
		cout << i.f << endl;
		return 0;
	}

	return 0;
}