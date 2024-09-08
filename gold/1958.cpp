#include <iostream>
#include <algorithm>
#include <vector>
#include <math.h>
#include <map>
#include <set>
#include <queue>
using namespace std;

#define ll long long

int main() {
	// your code goes here
	ios_base :: sync_with_stdio(false); 
	cin.tie(NULL); 
	cout.tie(NULL);
	int o=1;
	while(o--){
		string a,b,c;
		cin>>a;
		cin>>b;
		cin>>c;
		ll x=a.size();
		ll y=b.size();
		ll z=c.size();
		string fst_str=" ", sed_str=" ", trd_str=" ";
		fst_str+=a;
		sed_str+=b;
		trd_str+=c;
		ll dp[x+1][y+1][z+1];
		for(ll i=0;i<x+1;++i){
			for(ll j=0;j<y+1;++j){
				for(ll k=0;k<z+1;++k){
					dp[i][j][k]=0;
				}
			}
		}
		for(ll i=1;i<=x;++i){
			for(ll j=1;j<=y;++j){
				for(ll k=1;k<=z;++k){
					if(fst_str[i]==sed_str[j] && sed_str[j]==trd_str[k]){
						dp[i][j][k]=dp[i-1][j-1][k-1]+1;
					}else{
						priority_queue<ll> pq;
						pq.push(dp[i-1][j][k]);
						pq.push(dp[i-1][j-1][k]);
						pq.push(dp[i-1][j-1][k-1]);
						pq.push(dp[i-1][j][k-1]);
						pq.push(dp[i][j-1][k]);
						pq.push(dp[i][j-1][k-1]);
						pq.push(dp[i][j][k-1]);
						ll max_num=pq.top();
						dp[i][j][k]=max(dp[i][j][k],max_num);
					}
				}
			}
		}
		ll ans=0;
		for(ll i=1;i<x+1;++i){
			for(ll j=1;j<y+1;++j){
				for(ll k=1;k<z+1;++k){
					ans=max(ans,dp[i][j][k]);
				}
			}
		}		
		cout<<ans;
	}
	return 0;
}