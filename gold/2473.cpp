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
	int o=1;
	while(o--){
		ll n;
		cin>>n;
		vector<ll> v(n,0);
		for(ll i=0;i<n;++i){
			cin>>v[i];
		}
		sort(v.begin(),v.end());
		ll ans=abs(v[n-1]+v[n-2]+v[n-3]);
		vector<ll> c;
		c.push_back(v[n-3]);
		c.push_back(v[n-2]);
		c.push_back(v[n-1]);
		if(ans>abs(v[0]+v[1]+v[2])){
			ans=abs(v[0]+v[1]+v[2]);
			c[0]=v[0];
			c[1]=v[1];
			c[2]=v[2];
		}
		for(ll i=0;i<=n-3;++i){
			if(v[i]>0) break;
			ll L=i+1;
			ll R=n-1;
			while(L<R){
				if(abs(v[i]+v[L]+v[R])<ans){
					ans=abs(v[i]+v[L]+v[R]);
					c[0]=v[i];
					c[1]=v[L];
					c[2]=v[R];
				}
				if(v[i]+v[L]+v[R]<0){
					++L;
				}else{
					--R;
				}
			}
		}
		for(ll i=0;i<3;++i){
			cout<<c[i]<<" ";
		}
	}
	return 0;
}