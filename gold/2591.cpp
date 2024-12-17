#include <iostream>
#include <algorithm>
#include <vector>
#include <cstring>
#include <map>
#include <queue>
using namespace std;

#define ll long long


int main() {
	ios_base :: sync_with_stdio(false); 
	cin.tie(NULL); 
	cout.tie(NULL);
	ll o=1;
	while(o--){
		string s;
		cin>>s;
		int n=s.size();
		vector<ll> dp(n,0);
		if(n==1){
			cout<<1;
		}else{
			if(s[0]!='0'){
				dp[0]=1;
			}
			dp[1]=dp[0];
			ll cur_num=stoll(s.substr(0,2));
			if(1<=cur_num && cur_num<=34 && s[1]!='0'){
				++dp[1];
			}
			for(ll i=2;i<n;++i){
				if(s[i]=='0'){
					ll cur_num=stoll(s.substr(i-1,2));
					dp[i]=dp[i-2];
				}else{
					dp[i]=dp[i-1];
					ll cur_num=stoll(s.substr(i-1,2));
					if(cur_num>=1 && cur_num<=34 && s[i-1]!='0'){
						dp[i]+=dp[i-2];
					}
				}
			}
			// for(ll i=0;i<n;++i){
			// 	cout<<i<<" "<<dp[i]<<"\n";
			// }
			cout<<dp[n-1];
		}
	}
	return 0;
}