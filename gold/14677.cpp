#include <iostream>
#include <algorithm>
#include <vector>
#include <math.h>
#include <map>
#include <set>
#include <queue>
using namespace std;

#define ll long long

ll dp[1500+5][1500+5];
int main() {
	// your code goes here
	ios_base :: sync_with_stdio(false); 
	cin.tie(NULL); 
	cout.tie(NULL);
	int o=1;
	// cin>>o;
	while(o--){
		for(ll i=0;i<=1504;++i){
			for(ll j=0;j<=1504;++j){
				dp[i][j]=0;
			}
		}
		ll n;
		cin>>n;
		string s;
		cin>>s;
		n*=3;
		dp[0][0]=1;
		ll ans=0;
		for(ll i=0;i<=n;++i){
			for(ll j=0;j<=n;++j){
				if(i+j>n || !dp[i][j]) continue;
				ll cur_time=(i+j)%3;
				ll L=i;
				ll R=n-j-1;
				if(cur_time==0){
					if(L<n && s[L]=='B'){
						++dp[i+1][j];
					}
					if(R<n && R>=0 && s[R]=='B'){
						++dp[i][j+1];
					}
				}else if(cur_time==1){
					if(L<n && s[L]=='L'){
						++dp[i+1][j];
					}
					if(R<n && R>=0 && s[R]=='L'){
						++dp[i][j+1];
					}
				}else{
					if(L<n && s[L]=='D'){
						++dp[i+1][j];
					}
					if(R<n && R>=0 && s[R]=='D'){
						++dp[i][j+1];
					}
				}
			}
		}
		for(ll i=0;i<=n;++i){
			for(ll j=0;j<=n;++j){
				if(i+j>n || !dp[i][j]) continue;
                if(i==0 && j==0) continue;
				ans=max(i+j,ans);
			}
		}
		cout<<ans;
	}
	return 0;
}