#include <iostream>
#include <algorithm>
#include <vector>
#include <cstring>
#include <map>
#include <cmath>
#include <unordered_map>
using namespace std;

#define ll long long


int main() {
	ios_base :: sync_with_stdio(false); 
	cin.tie(NULL); 
	cout.tie(NULL);
	ll o=1;
	while(o--){
		ll n,c;
		cin>>n>>c;
		vector<ll> v(n,0);
		for(ll i=0;i<n;++i){
			cin>>v[i];
		}
		ll ans=0;
		sort(v.begin(),v.end());
		for(ll i=0;i<n;++i){
			if(v[i]==c){
				ans=1;
				break;
			}
			for(ll j=i+1;j<n;++j){
				if(v[i]+v[j]==c){
					ans=1;
					break;
				}
			}
		}
		for(ll i=0;i<n;++i){
			ll L=i+1, R=n-1;
			ll sum=v[i];
			while(L<R){
				ll cur_sum=sum+v[L]+v[R];
				if(cur_sum>c){
					--R;
				}else if(cur_sum<c){
					++L;
				}else{
					ans=1;
					break;
				}
			}
		}
		cout<<ans;
	}
	return 0;
}