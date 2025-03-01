#include <iostream>
#include <algorithm>
#include <vector>
#include <cstring>
#include <map>
#include <queue>
#include <cmath>
using namespace std;

#define ll long long

ll dp[5000+1][5000+1];

int main() {
	ios_base :: sync_with_stdio(false); 
	cin.tie(NULL); 
	cout.tie(NULL);
	ll o=1;
	while(o--){
		// 1443
		// 최소 개수의 문자를 삽입하여 팰린드롬이 되도록
		// Ab3bd
		// dAb3bAd
		// N^2가능
		ll n;
		cin>>n;
		string s;
		cin>>s;
		for(ll i=0;i<n;++i){
			for(ll j=0;j<n;++j){
				dp[i][j]=0;
			}
		}
		for(ll i=1;i<n;++i){
			for(ll j=i-1;j>=0;--j){
				if(s[i]!=s[j]){
					dp[j][i]=min(1+dp[j][i-1],1+dp[j+1][i]);
				}else{
					dp[j][i]=dp[j+1][i-1];
				}
				// cout<<j<<" "<<i<<" "<<dp[j][i]<<"\n";
			}
		}
		cout<<dp[0][n-1];
	}
	return 0;
}