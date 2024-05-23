#include <iostream>
#include <map>
#include <algorithm>
#include <cmath>
#include <vector>
using namespace std;


#define ll long long

int main() {
	
	
	ios_base :: sync_with_stdio(false); 
	cin.tie(NULL); 
	cout.tie(NULL);
	
	int t=1;
	while(t--){
		ll N,M;
		cin>>N>>M;
		vector<ll> v(N,0);
		for(ll i=0;i<N;++i){
			cin>>v[i];
		}
		ll L=0, R=1000000000000;
		ll ans=R;
		while(L<=R){
			ll mid=(L+R)/2;
			ll cur_sum=0;
			for(ll i=0;i<N;++i){
				cur_sum+=mid/v[i];
			}
			if(cur_sum>=M){
				ans=min(ans,mid);
				R=mid-1;
			}else{
				L=mid+1;
			}
		}
		cout<<ans;
	}
	

	

	return 0;
}