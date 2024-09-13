#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <map>
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
		vector<ll> v(n,0),dp(n,0);
		vector<ll> ans;
		for(ll i=0;i<n;++i){
			cin>>v[i];
		}
		dp[0]=1;
		for(ll i=1;i<n;++i){
			for(ll j=0;j<i;++j){
				if(v[j]<v[i]){
					dp[i]=max(dp[i],dp[j]+1);
				}
			}
		}
		ll lis=0;
		for(ll i=0;i<n;++i){
			lis=max(lis,dp[i]);
		}
		ll idx=-1;
		for(ll i=n-1;i>=0;--i){
			if(lis==dp[i]){
				ans.push_back(v[i]);
				idx=i-1;
				--lis;
				break;
			}
		}
		for(ll i=idx;i>=0;--i){
			if(lis==dp[i] && v[i]<ans[ans.size()-1]){
				ans.push_back(v[i]);
				--lis;
			}
		}
		ll as=ans.size();
		cout<<as<<"\n";
		sort(ans.begin(),ans.end());
		for(ll i=0;i<ans.size();++i){
			cout<<ans[i]<<" ";
		}cout<<"\n";
	}
	return 0;
}