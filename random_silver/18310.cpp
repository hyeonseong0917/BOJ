#include <iostream>
#include <algorithm>
#include <vector>
#include <cstring>
using namespace std;

#define ll long long


int main() {
	ios_base :: sync_with_stdio(false); 
	cin.tie(NULL); 
	cout.tie(NULL);
	ll n;
	ll o=1;
	while(o--){
		cin>>n;
		vector<ll> v(n,0),psum(n,0);
		for(ll i=0;i<n;++i){
			cin>>v[i];
		}
		sort(v.begin(),v.end());
		psum[0]=v[0];
		for(ll i=1;i<n;++i){
			psum[i]=psum[i-1]+v[i];
		}
		ll ans=psum[n-1]-psum[0]-v[0]*(n-1);
		ll pos=v[0];
		// cout<<ans<<endl;
		for(ll i=1;i<n;++i){
			if(i==n-1){
				ll cur_ans=v[i]*i-psum[i-1];
				if(cur_ans<ans){
					ans=cur_ans;
					pos=v[i];
				}
				// cout<<cur_ans<<endl;
			}else{
				ll cur_ans=psum[n-1]-psum[i]-v[i]*(n-1-i)+v[i]*i-psum[i-1];
				// cout<<i<<" "<<cur_ans<<endl;
				if(cur_ans<ans){
					ans=cur_ans;
					pos=v[i];
				}
			}
		}
		cout<<pos;
	}
	return 0;
}