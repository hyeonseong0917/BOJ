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
		int T,S;
		cin >> T >> S;
		if (12 <= T && T <= 16 && S == 0) cout << 320;
		else cout << 280;
	} 
	return 0;
}