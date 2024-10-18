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
		ll n;
		cin>>n;
		vector<ll> v(n,0);
		ll sum=0;
		for(ll i=0;i<n;++i){
			cin>>v[i];
			sum+=v[i];
		}
		if(n==1){
			cout<<0;
			break;
		}
		sort(v.begin(),v.end());
		ll avg=sum/n;
		ll mod=sum%n;
		ll q=0;
		ll ans=0;
		// cout<<mod<<endl;
		for(ll i=0;i<n-mod;++i){
			if(v[i]<avg){
				q+=avg-v[i];
				ans+=avg-v[i];
			}else if(v[i]>=avg){
				ll diff=v[i]-(avg);
				if(diff<=q){
					q-=diff;
				}else if(diff>q){
					ans+=diff-q;
					q=0;
				}
			}
		}
		for(ll i=n-mod;i<n;++i){
			// avg+1로 만들어야 함
			if(v[i]<avg+1){
				q+=avg+1-v[i];
				ans+=avg+1-v[i];
			}else if(v[i]>=avg+1){
				ll diff=v[i]-(avg+1);
				if(diff<=q){
					q-=diff;
				}else if(diff>q){
					ans+=diff-q;
					q=0;
				}
			}
		}
		cout<<ans;
		
	}
	return 0;
}