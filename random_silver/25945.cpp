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
		ll ans=0;
		ll idx=-1;
		for(ll i=0;i<n-mod;++i){
			ans+=avg-v[i];
		}
		// cout<<ans<<endl;
		// for(ll i=n-mod;i<n;++i){
		// 	ans+=v[i]-(avg+1);
		// }
		cout<<ans;
		
	}
	return 0;
}