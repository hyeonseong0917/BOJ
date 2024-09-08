#include <iostream>
#include <algorithm>
#include <vector>
#include <math.h>
#include <map>
#include <set>
#include <queue>
using namespace std;

#define ll long long


int main() {
	// your code goes here
	ios_base :: sync_with_stdio(false); 
	cin.tie(NULL); 
	cout.tie(NULL);
	ll x,n;
	while(cin>>x>>n){
		if(n==0){
			cout<<"danger"<<"\n";
			continue;
		}
		vector<ll> v(n,0);
		for(ll i=0;i<n;++i){
			cin>>v[i];
		}
		sort(v.begin(),v.end());
		if(n<2){
			cout<<"danger"<<"\n";
			continue;
		}
		for(ll i=0;i<7;++i){
			x*=10;
		}
		ll L=0, R=n-1;
		vector<ll> ans(2,-1);
		while(L<R){
			if(v[L]+v[R]>x){
				--R;
			}else if(v[L]+v[R]<x){
				++L;
			}else{
				ans[0]=v[L];
				ans[1]=v[R];
				break;
			}
		}
		if(ans[0]==-1){
			cout<<"danger"<<"\n";
		}else{
			cout<<"yes"<<" "<<ans[0]<<" "<<ans[1]<<"\n";
		}
	}
	return 0;
}