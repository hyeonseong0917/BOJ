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
        ll ans=0;
        for(ll i=0;i<n;++i){
            cin>>v[i];
            ans=max(ans,v[i]);
        }
        // 1 3 2 2
        // 0 4 1 2

        // 2 4 3 5 5
        
        for(ll i=1;i<n-1;++i){
            ans=max(ans,v[i]+min(v[i-1],v[i+1]));
        }
        cout<<ans;
        return 0;
	} 
	return 0;
}