#include <iostream>
#include <algorithm>
#include <vector>
#include <cstring>
#include <map>
#include <deque>
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
		ll p,q;
		cin>>p>>q;
		ll ans=0;
		for(ll i=1;i<=p;++i){
			if(!q) break;
			if(p%i==0){
				--q;
				ans=i;
			}
		}
		if(q==0){
			cout<<ans;
		}else{
			cout<<0;
		}
	}
	return 0;
}