#include <iostream>
#include <algorithm>
#include <vector>
#include <cstring>
#include <map>
#include <deque>
#include <cmath>
using namespace std;

#define ll long long
#define pb push_back

int main() {
	ios_base :: sync_with_stdio(false); 
	cin.tie(NULL); 
	cout.tie(NULL);
	ll t=1;
	// cin>>t;
	while(t--){
		int ans = 1;

		ll N; cin >> N;
		while (N != 1) {
			ans++;
			if (N & 1) N = 3 * N + 1;
			else N /= 2;
		}
	
		cout << ans;
	}
} 