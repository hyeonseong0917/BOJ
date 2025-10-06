#include <iostream>
#include <algorithm>
#include <vector>
#include <cstring>
#include <map>
#include <cmath>
using namespace std;

#define ll long long


int main() {
	ios_base :: sync_with_stdio(false); 
	cin.tie(NULL); 
	cout.tie(NULL);
	ll o=1;
	cin>>o;
	while(o--){
		ll n;
		cin>>n;
		vector<ll> v(n,0);
		for(ll i=0;i<n;++i){
			cin>>v[i];
		}
		sort(v.begin(),v.end());
		vector<ll> psum(n,0);
		psum[0]=v[0];
		for(ll i=1;i<n;++i){
			psum[i]=psum[i-1]+v[i];
		}
		ll ans=v[n-1]*n-psum[n-1];
		// ll ans=0;
		for(ll i=1;i<n;++i){
			// i개를 골랐을 때 최솟값
			ll tmp=0;
			for(ll j=i-1;j<n;++j){
				// j번째 인덱스를 최댓값으로 할 때
				if(j==i-1){
					tmp=v[j]*i-psum[j];
				}else{
					tmp=min(tmp,v[j]*i-(psum[j]-psum[j-i+1]+v[j-i+1]));
				}
				// tmp=max(0ll,tmp);
				// cout<<i<<" "<<j<<" "<<tmp<<endl;
			}
			ans+=tmp;
		}
		cout<<ans<<"\n";
	}
	return 0;
}