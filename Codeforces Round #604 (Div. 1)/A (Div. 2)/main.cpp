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

	int n;
	cin >> n;

	while(n--){
		string s;
		cin >> s;
		for(int i = 0; i < s.size(); ++i){
			if(s[i] != '?')
				continue;
			char l = 'a';
			if(i > 0)
				l = s[i - 1];
			char r = 'a';
			if(i + 1 < s.size())
				r = s[i + 1];
			for(char c = 'a'; c <= 'c'; c++){
				if(c != l && c != r){
					s[i] = c;
					break;
				}
			}
		}
		bool ok = 1;
		for(int i = 1; i < (int)s.size(); i++)
			if(s[i] == s[i - 1])
				ok = 0;
		if(ok)
			cout << s << endl;
		else cout << "-1" << endl;
	}

	return 0;
}