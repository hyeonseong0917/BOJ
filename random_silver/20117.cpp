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
		vector<ll> v(n,0);
		for(ll i=0;i<n;++i){
			cin>>v[i];
		}
		// 2 4 8 9
		// 3 200 201
		sort(v.begin(),v.end());
		ll ans=0;
		ll L=0, R=n-1;
		while(L<=R){
			if(L==R){
				ans+=v[L];
				break;
			}
			ans+=v[R]*2;
			--R;
			++L;
		}
		cout<<ans;
		
	} 
	return 0;
}