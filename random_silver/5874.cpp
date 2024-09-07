#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;

#define ll long long

int main() {
	ios_base :: sync_with_stdio(false); 
	cin.tie(NULL); 
	cout.tie(NULL);
	ll o=1;
	while(o--){
		ll n;
		string s;
		cin>>s;
		n=s.size();
		if(n<4){
			cout<<0;
			break;
		}
		vector<ll> dp(n+1,0);
		for(ll i=n-2;i>=0;--i){
			dp[i]=dp[i+1];
			if(s[i]==')' && s[i+1]==')'){
				++dp[i];
			}
		}
		ll ans=0;
		for(ll i=1;i<n;++i){
			if(s[i]=='(' && s[i-1]=='('){
				ans+=dp[i];
			}
		}
		cout<<ans;
	}
	return 0;
}