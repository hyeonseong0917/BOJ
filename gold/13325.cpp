#include <iostream>
#include <algorithm>
#include <vector>
#include <cstring>
#include <map>
#include <cmath>
using namespace std;

#define ll long long

ll n;
vector<ll> g[20+1];
vector<ll> dp[20+1];

int main() {
	ios_base :: sync_with_stdio(false); 
	cin.tie(NULL); 
	cout.tie(NULL);
	ll o=1;
	while(o--){
		cin>>n;
		ll ans=0;
		for(ll i=0;i<2;++i){
			ll a;
			cin>>a;
			g[0].push_back(a);
			ans+=a;
		}
		g[1]=vector<ll>(4,0);
		ll cur_cnt=0;
		ll cur_height=1;
		while(cur_height<n){
			ll a;
			cin>>a;
			ans+=a;
			g[cur_height][cur_cnt]=a;
			++cur_cnt;
			if(cur_cnt==(ll)pow(2,cur_height+1)){
				cur_cnt=0;
				++cur_height;
				g[cur_height]=vector<ll>((ll)pow(2,cur_height+1),0);
			}
		}
		cur_height=n-1;
		ll cnt=0;
		dp[cur_height]=vector<ll>((ll)pow(2,cur_height+1),0);
		while(cur_height>=0){
			
			if(cur_height==n-1){
				dp[cur_height][cnt]=g[cur_height][cnt];
			}else{
				dp[cur_height][cnt]=dp[cur_height+1][cnt*2]+g[cur_height][cnt];
				// cout<<cur_height<<" "<<cnt<<" "<<g[cur_height][cnt*2]<<endl;
				dp[cur_height][cnt]=max(dp[cur_height+1][cnt*2+1]+g[cur_height][cnt],dp[cur_height][cnt]);
				
			}
			// cout<<cur_height<<" "<<cnt<<" "<<dp[cur_height][cnt]<<endl;
			++cnt;
			if(cnt==(ll)pow(2,cur_height+1)){
				cnt=0;
				--cur_height;
				if(cur_height>=0){
					dp[cur_height]=vector<ll>((ll)pow(2,cur_height+1),0);
				}
			}
			
		}
		// for(ll i=0;i<n;++i){
		// 	for(ll j=0;j<(ll)pow(2,i+1);++j){
		// 		cout<<i<<" "<<j<<" "<<dp[i][j]<<endl;
		// 	}
		// }
		// cout<<dp[0][0]<<endl;
		cur_height=0;
		cnt=0;		
		while(cur_height<=n-1){
			for(ll i=0;i<(ll)pow(2,cur_height);++i){
				ans+=abs(dp[cur_height][2*i]-dp[cur_height][2*i+1]);
				// cout<<cur_height<<" "<<i<<" "<<ans<<endl;
			}
			++cur_height;
		}
		cout<<ans;
	}
	return 0;
}