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

	cin >> s;
	v.pb(mp(0, 1));
	sum = 0;
	for(int i = s.size() - 1; i >= 0; --i){
		if(s[i] - 'a' + 1 == v.back().f){
			v.back().s++;
			sum++;
		}else{
			v.pb(mp(s[i] - 'a' + 1, 1));
			sum++:
		}	
		if(v.back().f > v[v.size() - 2].f){
			sum -= v.back().s - v.back().s % 2;
			v.back().s %= 2;
		}
		if(v.back().s == 0)
			v.pop_back();
		if(sum > 10){
			string ans = "";
			for(int j = 0; j < 5; ++j)
			for(int k = 0; k < v[v.size() - j - 1].s && ans.size() < 5; ++k)
				ans += (char)(v[v.size() - j - 1].f - 1 + 'a');
			ans += "...";
			
		}else{
			string ans = "";
			for(int j = 0; j < 5; ++j)
			for(int k = 0; k < v[v.size() - j - 1].s; ++k)
				ans += (char)(v[v.size() - j - 1].f - 1 + 'a')
		}
	}
	
	return 0;
}