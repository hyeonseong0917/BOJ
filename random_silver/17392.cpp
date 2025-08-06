#include <iostream>
#include <algorithm>
#include <vector>
#include <cstring>
#include <map>
#include <deque>
#include <cmath>
#include <queue>
using namespace std;

#define ll long long
#define pb push_back


int main() {
	ios_base :: sync_with_stdio(false); 
	cin.tie(NULL); 
	cout.tie(NULL);
	ll o=1;
	// cin>>t;
	while(o--){
		ll n,m;
		cin>>n>>m;
		vector<ll> v(n,0);
		ll sum=0;
		for(ll i=0;i<n;++i){
			cin>>v[i];
			++v[i];
			sum+=v[i];
		}
		if(sum>=m){
			cout<<0;
		}else{
			ll diff=m-sum;
			vector<ll> p(n+1,0);
			ll idx=0;
			while(idx<diff){
				++p[idx%(n+1)];
				++idx;
			}
			ll ans=0;
			for(ll i=0;i<n+1;++i){
				for(ll j=1;j<=p[i];++j){
					ans+=j*j;
				}
			}
			cout<<ans;
		}

	} 
	return 0;
}