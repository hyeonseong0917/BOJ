#include <iostream>
#include <algorithm>
#include <vector>
#include <cstring>
#include <map>
#include <deque>
#include <cmath>
using namespace std;

#define ll long long
#define pb push_back



int main() {
	ios_base :: sync_with_stdio(false); 
	cin.tie(NULL); 
	cout.tie(NULL);
	ll t=1;
	// cin>>t;
	while(t--){
		ll n;
		cin>>n;
		vector<ll> v(n,0);
		for(ll i=0;i<n;++i){
			cin>>v[i];
		}
		ll L=v[0];
		ll R=v[1];
		for(ll i=2;i<n;++i){
			if(L==R){
				L+=v[i];
			}else{
				if(L<R){
					L+=v[i];
				}else{
					R+=v[i];
				}
			}
		}
		ll p[7]={1,2,5,10,20,50,100};
		ll diff=abs(R-L);
		ll ans=0;
		for(ll i=6;i>=0;--i){
			ll q=diff/p[i];
			ans+=q;
			diff-=q*p[i];
		}
		cout<<ans;
	} 
	return 0;
}