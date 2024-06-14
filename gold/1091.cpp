#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <queue>
using namespace std;

#define ll long long


int main() {
	// your code goes here
	ll t=1;
	while(t--){
		ll n;
		cin>>n;
		vector<ll> p(n,0), s(n,0);
		for(ll i=0;i<n;++i){
			cin>>p[i];
		}
		for(ll i=0;i<n;++i){
			cin>>s[i];
		}
		vector<ll> d(n,0);
		for(ll i=0;i<n;++i){
			d[i]=i;
		}
		ll ans=0;
		bool is_origin=0;
		while(!is_origin){
			// 확인
			vector<ll> check(n,0);
			for(ll i=0;i<n;++i){
				check[d[i]]=i;
			}
			bool flag=0;
			for(ll i=0;i<n;++i){
				if(p[i]!=check[i]%3){
					flag=1;
					break;
				}
			}
			if(!flag) break;
			// 셔플
			vector<ll> tmp(n,0);
			for(ll i=0;i<n;++i){
				tmp[s[i]]=d[i];
			}
			++ans;
			for(ll i=0;i<n;++i){
				d[i]=tmp[i];
			}
			is_origin=1;
			for(ll i=0;i<n;++i){
				if(d[i]!=i){
					is_origin=0;
					break;
				}
			}
		}
		if(is_origin){
			cout<<-1;
		}else{
			cout<<ans;
		}
	}

	return 0;
}