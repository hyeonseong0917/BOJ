#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

#define ll long long

int main() {
	ios_base :: sync_with_stdio(false); 
	cin.tie(NULL); 
	cout.tie(NULL);
	ll o=1;
	while(o--){
		ll n;
		cin>>n;
		vector<ll> v(n,0);
		for(ll i=0;i<n;++i){
			cin>>v[i];
		}
		ll cnt=1;
		ll start_idx=-1;
		ll last_milk=0;
		for(ll i=0;i<n;++i){
			if(v[i]==0){
				start_idx=i;
				break;
			}
		}
		if(start_idx==-1){
			cout<<0;
		}else{
			for(ll i=start_idx+1;i<n;++i){
				if(last_milk==0){
					if(v[i]==1){
						last_milk=1;
						++cnt;
					}
				}else if(last_milk==1){
					if(v[i]==2){
						last_milk=2;
						++cnt;
					}
				}else{
					if(v[i]==0){
						last_milk=0;
						++cnt;
					}
				}
			}
			cout<<cnt;
		}
	}
	return 0;
}