#include <iostream>
#include <algorithm>
#include <vector>
#include <cstring>
#include <map>
#include <queue>
using namespace std;

#define ll long long
#define pb push_back

int main() {
	ios_base :: sync_with_stdio(false); 
	cin.tie(NULL); 
	cout.tie(NULL);
	ll o=1;
	while(o--){
		ll n,k;
		cin>>n>>k;
		map<ll,ll> m;
		vector<ll> g(1000000+1,0), x(1000000+1,0);
		for(ll i=0;i<n;++i){
			ll a,b;
			cin>>a>>b;
			g[b]=a;
		}
		ll L=0, R=2*k;
		ll ans=0;
		if(R>=1000000){
			for(ll i=0;i<1000000+1;++i){
				if(g[i]){
					ans+=g[i];
				}
			}
		}else{
			ll sum=0;
			for(ll i=L;i<=R;++i){
				if(g[i]){
					sum+=g[i];
				}
			}
			ans=sum;
			while(L<=R && R<1000000){
				
				if(g[L]){
					sum-=g[L];
				}
				++L;
				if(g[R+1]){
					sum+=g[R+1];
				}
				++R;
				ans=max(ans,sum);

			}
		}
		cout<<ans;
		
	}
	return 0;
}