#include <iostream>
#include <algorithm>
#include <vector>
#include <cstring>
#include <map>
#include <queue>
#include <sstream>
using namespace std;

#define ll long long

vector<ll> v[50+1];
ll mod=10007;
ll dp[50+1][50000+1];

int main() {
	ios_base :: sync_with_stdio(false); 
	cin.tie(NULL); 
	cout.tie(NULL);
	ll o=1;
	while(o--){
		ll n,m,h;
		cin>>n>>m>>h;
		cin.ignore();
		for(int i = 1; i <= n; i++){
			string str;
			getline(cin,str);
			stringstream sstr(str);
			ll num;

			while(sstr >> num) v[i].push_back(num);
    	}
		for(ll i=0;i<=n;++i){
			for(ll j=0;j<=50000;++j){
				dp[i][j]=0;
			}
		}
		// for(ll i=1;i<=n;++i){
		// 	dp[i][0]=1;
		// }
		// for(ll i=0;i<v[1].size();++i){
		// 	dp[1][v[1][i]]=1;
		// }
		dp[0][0]=1;
		for(ll i=1;i<=n;++i){
			for(ll j=0;j<=h;++j){
				dp[i][j]+=dp[i-1][j]%mod;
				dp[i][j]%=mod;
				for(ll k=0;k<v[i].size();++k){
					if(j>=v[i][k]){
						dp[i][j]+=dp[i-1][j-v[i][k]]%mod;
						dp[i][j]%=mod;
					}
				}
			}
		}
		cout<<dp[n][h]%mod;
		
	} 
	return 0;
}