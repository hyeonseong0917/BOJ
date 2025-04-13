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
		ll n;
        cin>>n;
        // k=1 ~ k=n

		// k=2만족 -> 모두 짝수로? 짝홀 번갈아 안되나
		// k=3만족 -> 2 4 6 8 10
		for(ll i=1;i<=n;++i){
			cout<<i*2<<" ";
		}
	} 
	return 0;
}