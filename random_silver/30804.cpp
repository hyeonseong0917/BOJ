#include <iostream>
#include <map>
#include <algorithm>
#include <cmath>
#include <vector>
using namespace std;

#define ll long long
int main() {
	// your code goes here
	ios_base :: sync_with_stdio(false); 
	cin.tie(NULL); 
	cout.tie(NULL);
	ll o=1;
	// 1409
	while(o--){
		ll n;
		cin>>n;
		vector<ll> v(n,0);
		vector<ll> check(10,0);
		for(ll i=0;i<n;++i){
			cin>>v[i];
		}
		ll L=0, R=0;
		ll ans=1;
		ll cnt=1;
		++check[v[0]];
		// ++check[v[0]];
		while(L<=R && R<n-1){
			// cout<<L<<" "<<R<<" "<<cnt<<" "<<check[2]<<endl;
			if(L==R){
				++R;
				if(!check[v[R]]){
					++cnt;
				}
				++check[v[R]];
				// --check[v[L]];
				ans=max(ans,R-L+1);
			}else{
				if(cnt<2){
					++R;
					if(!check[v[R]]){
						++cnt;
					}
					++check[v[R]];
				}else{
					// cnt==2
					if(!check[v[R+1]]){
						--check[v[L]];
						if(!check[v[L]]){
							--cnt;
						}
						++L;
						
					}else{
						++check[v[R+1]];
						++R;
					}
				}
				ans=max(ans,R-L+1);
			}
		}
		cout<<ans;
		

	}
	

	

	return 0;
}