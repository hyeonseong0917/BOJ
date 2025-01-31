#include <iostream>
#include <algorithm>
#include <vector>
#include <cstring>
#include <map>
#include <queue>
using namespace std;

#define ll long long

ll dp[100000+1];

int main() {
	ios_base :: sync_with_stdio(false); 
	cin.tie(NULL); 
	cout.tie(NULL);
	ll o=1;
	while(o--){
		ll d,p;
		cin>>d>>p;
		vector<pair<ll,ll>> v;
		for(ll i=0;i<p;++i){
			ll a,b;
			cin>>a>>b;
			if(a<=d){
				v.push_back({a,b});
			}
		}
		for(ll i=0;i<=100000;++i){
			dp[i]=0;
		}
		sort(v.begin(),v.end());
		dp[0]=2023101800;
		for(ll i=0;i<v.size();++i){
			ll L=v[i].first;
			ll C=v[i].second;
			for(ll j=100000;j>=0;--j){
				if(dp[j]){
					if(j+L<=100000){
						dp[j+L]=max(dp[j+L],min(dp[j],C));
					}
					if(j-L>=0){
						dp[j]=max(dp[j],min(dp[j-L],C));
					}
				}
			}
			// cout<<"hd"<<i<<" "<<dp[2]<<"\n";
			dp[L]=max(dp[L],C);
		}
		cout<<dp[d];
	}
	return 0;
}