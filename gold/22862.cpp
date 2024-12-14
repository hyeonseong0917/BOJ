#include <iostream>
#include <algorithm>
#include <vector>
#include <stack>
#include <map>
using namespace std;

#define ll long long

int main() {
	ios_base :: sync_with_stdio(false); 
	cin.tie(NULL); 
	cout.tie(NULL);
	ll o=1;
	while(o--){
		ll n,k;
		cin>>n>>k;
		vector<ll> v(n,0);
		ll odd_num=0;
		for(ll i=0;i<n;++i){
			cin>>v[i];
			if(v[i]%2==1) ++odd_num;
		}
		if(odd_num<=k){
			cout<<n-odd_num;
		}else{
			ll ans=0;
			ll cnt=0;
			ll cur_len=0;
			ll L=0, R=0;
			while(L<=R && R<n){
				// cout<<L<<" "<<R<<" "<<ans<<"\n";
				
				if(R==n){
					break;
				}
				if(v[R]%2==1){
					++cnt;
					if(cnt>k){
						ans=max(ans,cur_len);
						while(L<R && cnt>k){
							if(v[L]%2==0){
								--cur_len;
							}else{
								--cnt;
							}
							++L;
						}
					}
					++R;
				}else{
					++cur_len;
					++R;
					ans=max(ans,cur_len);
				}
			}
			ans=max(ans,cur_len);
			cout<<ans;
		}
		
	}
	return 0;
}