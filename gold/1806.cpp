#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <queue>
using namespace std;

#define ll long long
int main() {
	// your code goes here
	ios_base :: sync_with_stdio(false); 
	cin.tie(NULL); 
	cout.tie(NULL);
	ll N,S;
	cin>>N>>S;
	vector<ll> v(N,0);
	vector<ll> psum(N,0);
	ll ans=1222232421;
	for(ll i=0;i<N;++i){
		cin>>v[i];
		if(v[i]>=S){
			ans=1;
		}
	}
	
	psum[0]=v[0];
	for(ll i=1;i<N;++i){
		psum[i]=psum[i-1]+v[i];
		
	}
	if(ans==1){
		cout<<ans;
	}else{
		ll L=0, R=0;
		ll cur_sum=0;
		while(L<=R){
			// cout<<psum[R]-psum[L]<<"\n";
			if(S<=psum[R]-psum[L]+v[L]){
				ans=min(ans,R-L+1);
				++L;
			}else{
				++R;
				if(R==N){
					break;
				}
			}
		}	
		if(ans==1222232421){
			cout<<0;
		}else{
			cout<<ans;
		}
	}
	
	return 0;
}