#include <iostream>
#include <algorithm>
#include <vector>
#include <cstring>
using namespace std;

#define ll long long

ll dp[2+1][100+1][100+1];
string v[2];

int main() {
	ios_base :: sync_with_stdio(false); 
	cin.tie(NULL); 
	cout.tie(NULL);
	ll o=1;
	while(o--){
		ll n;
		for(ll i=0;i<2;++i){
			for(ll j=0;j<100+1;++j){
				for(ll k=0;k<100+1;++k){
					dp[i][j][k]=0;
				}
			}
		}
		string s;
		cin>>s;
		for(ll i=0;i<2;++i){
			cin>>v[i];
			n=v[i].size();
		}
		if(v[0][0]==s[0]){
			dp[0][0][1]=1;
		}
		if(v[1][0]==s[0]){
			dp[1][0][1]=1;
		}
		for(ll i=1;i<n;++i){
			if(v[0][i]==s[0]){
				dp[0][i][1]=1;
			}
			if(v[1][i]==s[0]){
				dp[1][i][1]=1;
			}
			for(ll j=2;j<=i+1;++j){
				if(v[0][i]==s[j-1]){
					for(ll k=0;k<i;++k){
						dp[0][i][j]+=dp[1][k][j-1];
					}
				}
				if(v[1][i]==s[j-1]){
					for(ll k=0;k<i;++k){
						dp[1][i][j]+=dp[0][k][j-1];
					}
				}
			}
		}
		ll m=s.size();
		ll ans=0;
		for(ll i=0;i<2;++i){
			for(ll j=0;j<n;++j){
				ans+=dp[i][j][m];
			}
		}
		cout<<ans;
	}
	return 0;
}