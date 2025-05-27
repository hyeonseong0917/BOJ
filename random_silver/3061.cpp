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
	cin>>t;
	while(t--){
		// 1443
		ll n;
		cin>>n;
		vector<ll> v(n,0);
		vector<ll> p(n,0);
		for(ll i=0;i<n;++i){
			cin>>v[i];
			p[i]=i+1;
		}	
		ll ans=0;	
		for(ll i=0;i<n;++i){
			if(v[i]==p[i]) continue;
			ll idx=-1;
			for(ll j=i+1;j<n;++j){
				if(v[i]==p[j]){
					idx=j;
					break;
				}
			}
			ans+=idx-i;
			for(ll j=idx;j>=i+1;--j){
				ll tmp=p[j];
				p[j]=p[j-1];
				p[j-1]=tmp;
			}
		}
		cout<<ans<<"\n";

	} 
	return 0;
}