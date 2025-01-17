#include <iostream>
#include <algorithm>
#include <vector>
#include <cstring>
#include <map>
#include <queue>
using namespace std;

#define ll long long

ll dp[40+1][40+1];

int main() {
	ios_base :: sync_with_stdio(false); 
	cin.tie(NULL); 
	cout.tie(NULL);
	ll o=1;
	while(o--){
		string s,t;
		cin>>s;
		cin>>t;
		for(ll i=0;i<=40;++i){
			for(ll j=0;j<=40;++j){
				dp[i][j]=0;
			}
		}
		// 두 문자열에 존재하는 공통으로 가장 긴 문자열
		// dp[x]: x문자열까지 봤을 때 공통으로 가장 긴 문자열?
		// dp[x]=max(dp[x-1],dp[y-1]+1)
		ll ss=s.size();
		ll ts=t.size();
		
		// s가 더 길어짐
		// t가 더 짧음
		for(ll i=0;i<ss;++i){
			for(ll j=0;j<ts;++j){
				if(s[i]==t[j]){
					dp[i+1][j+1]=dp[i][j]+1;
				}else{
					dp[i+1][j+1]=max(dp[i][j+1],dp[i+1][j]);
				}
			}
		}
		// cout<<dp[s.size()][t.size()];
		ll k=dp[s.size()][t.size()];
		string ans="";
		for(ll i=s.size()-1;i>=0;--i){
			for(ll j=t.size()-1;j>=0;--j){
				if(s[i]==t[j] && dp[i+1][j+1]==k && k){
					ans+=s[i];
					--k;
					break;
				}
			}
		}
		reverse(ans.begin(),ans.end());
		cout<<ans;
	} 
	return 0;
}