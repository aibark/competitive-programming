#include <stdio.h>
#include <bits/stdc++.h>

#define f first
#define s second
#define pb push_back
#define mp make_pair
#define all(x) x.begin(), x.end()

typedef long long ll;

using namespace std;

const int N = (int)1e6 + 123, mod = (int)1e9 + 7, inf = (int)1e9;
const ll INF = (ll)1e18;

int n, mx[N];
vector <int> del[N];
multiset <int> S;

pair <int, int> solve(string s){
	n = s.size();
	int L = 0, R = n - 1;
	while(L < R && s[L] == s[R])
		L++, R--;
	int ansl = L - 1, ansr = R + 1;
	vector<int> d1 (n, 0);
	int l=0, r=-1, k;
	for(int i = 0; i < n; i++){
		if(i > r) k = 1;
		else k = min(d1[l + r - i], r - i);
		while(0 <= i-k && i+k < n && s[i - k] == s[i + k]) k++;
		d1[i] = k;
		if(i + k - 1 > r)
			r = i + k - 1, l = i - k + 1;
	}              
	for(int i = 0; i < n; ++i)
		del[i + d1[i] - 1].pb(i);
	for(int i = 0; i < n; ++i){
		S.insert(-i);
		auto it = S.lower_bound(-((L + i) / 2));
		if(it == S.end())
			it = S.begin();
		mx[i + 1] = 2 * (-(*it)) - i;
		if(mx[i + 1] - 1 < L){
			int ra = n - (mx[i + 1] - 1) - 1;
			if(ansr - ansl > ra - i && i < ra)
				ansr = ra, ansl = i;
		}
		for(int j : del[i])
			S.erase(S.find(-j));
	}
	for(int i = 0; i < n; ++i)
		del[i].clear();
	vector<int> d2 (n, 0);
	l=0, r=-1;
	for(int i = 0; i < n; i++){
		if(i > r) k = 0;
		else k = min(d2[l + r - i + 1], r - i + 1);
		while(i + k < n && i - k - 1 >= 0 && s[i+k] == s[i - k - 1]) k++;
		d2[i] = k;
		if(i + k - 1 > r)
			l = i - k, r = i + k - 1;
	}
	for(int i = 0; i < n; ++i)
		if(d2[i] > 0)
			del[i + d2[i] - 1].pb(i);
	for(int i = 0; i < n; ++i){
		if(d2[i] > 0)
		S.insert(-i);
		if(S.size() > 0){
			auto it = S.lower_bound(-((L + i + 1) / 2));
			if(it == S.end())
				it = S.begin();
			mx[i + 1] = 2 * (-(*it)) - i - 1;
			if(mx[i + 1] - 1 < L){
				int ra = n - (mx[i + 1] - 1) - 1;
				if(ansr - ansl > ra - i && i < ra)
					ansr = ra, ansl = i;
			}
		}	
		for(int j : del[i])
			S.erase(S.find(-j));
	}
	for(int i = 0; i < n; ++i)
		del[i].clear();
	return mp(ansl, ansr);
}

int main(){
	cin.tie(0);
	cout.tie(0);
	ios_base::sync_with_stdio(NULL);

	int t;
	cin >> t;
	while(t--){
		string s;
		cin >> s;
		pair <int, int> ans1 = solve(s);
		reverse(all(s));
		pair <int, int> ans2 = solve(s);
		reverse(all(s));
		n = s.size();
		ans2.f = n - ans2.f - 1;
		ans2.s = n - ans2.s - 1;
		swap(ans2.f, ans2.s);
		if(ans2.s - ans2.f < ans1.s - ans1.f)
			swap(ans2, ans1);
		cout << s.substr(0, ans1.f + 1) + s.substr(ans1.s, n - ans1.s) << endl;
	}

	return 0;
}