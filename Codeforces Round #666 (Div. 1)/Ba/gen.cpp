#include <bits/stdc++.h>
using namespace std;
int main(){
	srand(time(NULL));
	cout << 1 << endl;
	int n = rand() % 5 + 1;
	cout << n << endl;
	for(int i = 1; i <= n; ++i){
		int x = rand() % 6 + 1;
		cout << x << " ";
	}
	cout << endl;
	return 0;
}