#include <iostream>
#include <algorithm>
#include <vector>
#include <cstring>
#include <map>
#include <cmath>
#include <queue>
#include <unordered_map>
using namespace std;

#define ll long long

ll dp[200+1][200+1];

int main() {
	ios_base :: sync_with_stdio(false); 
	cin.tie(NULL); 
	cout.tie(NULL);
	ll o=1;
	string a,b;
	while(cin>>a>>b){
		ll as=a.size();
		ll bs=b.size();
		for(ll i=0;i<200+1;++i){
			for(ll j=0;j<200+1;++j){
				dp[i][j]=0;
			}
		}
		for(ll i=0;i<as;++i){
			for(ll j=0;j<bs;++j){
				if(a[i]==b[j]){
					dp[i][j]=max(dp[i][j],1ll);
				}
				if(i==0 && j==0){
					if(a[i]==b[j]){
						dp[i][j]=1;
					}
				}else{
					ll c=(a[i]==b[j])?1:0;
					if(j>0){
						dp[i][j]=max(dp[i][j],dp[i][j-1]);
					}
					if(i>0){
						dp[i][j]=max(dp[i][j],dp[i-1][j]);
					}
					if(i>0 && j>0){
						dp[i][j]=max(dp[i][j],dp[i-1][j-1]+c);
					}
				}
			}
		}
		ll ans=0;
		for(ll i=0;i<as;++i){
			for(ll j=0;j<bs;++j){
				ans=max(ans,dp[i][j]);
			}
		}
		cout<<ans<<"\n";
	}
	return 0;
}