#include <iostream>
#include <algorithm>
#include <vector>
#include <cstring>
#include <map>
#include <queue>
using namespace std;

#define ll long long

ll a,b,d,n;
ll dp[1010000+1], p[1010000+1], death[1010000+1];
ll mod=1000;
int main() {
	ios_base :: sync_with_stdio(false); 
	cin.tie(NULL); 
	cout.tie(NULL);
	ll o=1;
	while(o--){
		cin>>a>>b>>d>>n;
		for(ll i=0;i<=n+a;++i){
			p[i]=0;
			dp[i]=0;
			death[i]=0;
			
		}
		
		for(ll i=a;i<=b-1;++i){
			p[i]=1;
		}
		// a b d n
		// 2 4 6 6
		p[0]=1;
		for(ll i=a+a;i<=n;++i){
			p[i]=p[i-1]%mod+p[i-a]%mod;
			if(i-b>=0){
				// i-1번째날이 마지막으로 생식할 수 있는 날이었음
				p[i]=(p[i]+mod-p[i-b])%mod;
			}
			p[i]%=mod;
		}
		dp[0]=1;
		++death[d];
		for(ll i=1;i<=n;++i){
			if(p[i]){
				death[i+d]+=p[i]%mod;
				death[i+d]%=mod;
			}
			dp[i]=(dp[i-1]+p[i]-death[i]+mod)%mod;
			dp[i]%=mod;
		}
		// for(ll i=0;i<=n;++i){
		// 	// cout<<i<<" "<<p[i]<<" "<<dp[i]<<"\n";
		// 	cout<<i<<" "<<p[i]<<"\n";
		// }
		cout<<dp[n];
	} 
	return 0;
}