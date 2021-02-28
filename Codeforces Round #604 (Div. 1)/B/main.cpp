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

int a[5], cnt[5];
vector <int> v;

void dfs(int last){
	cnt[last]--;
	v.pb(last);
	if(cnt[last + 1]){
		dfs(last + 1);
	}else{
		if(last > 0 && cnt[last - 1]){
			dfs(last - 1);
		}
	}
}

int main(){
	cin.tie(0);
	cout.tie(0);
	ios_base::sync_with_stdio(NULL);

	cin >> a[0] >> a[1] >> a[2] >> a[3];

	for(int beg = 0; beg <= 3; beg++){
		for(int i = 0; i <= 3; ++i)
			cnt[i] = a[i];
		v.clear();
		if(cnt[beg])
			dfs(beg);
		if(v.size() == a[0] + a[1] + a[2] + a[3]){
			cout << "YES" << endl;
			for(int i : v)
				cout << i << " ";
			return 0;
		}
	}

	cout << "NO";

	return 0;
}