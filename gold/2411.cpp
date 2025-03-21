#include <iostream>
#include <algorithm>
#include <vector>
#include <cstring>
#include <map>
#include <queue>
#include <cmath>
using namespace std;

#define ll long long

ll board[100+1][100+1];
ll dp[100+1][100+1];
int main() {
	ios_base :: sync_with_stdio(false); 
	cin.tie(NULL); 
	cout.tie(NULL);
	ll o=1;
	// cin>>o;
	while(o--){
		// 1541
		ll n,m,a,b;
		cin>>n>>m>>a>>b;
		for(ll j=0;j<=n;++j){
			for(ll k=0;k<=m;++k){
				board[j][k]=0;
			}
		}
		vector<pair<ll,ll>> v;
		for(ll i=0;i<a;++i){
			ll y,x;
			cin>>y>>x;
			v.push_back({y,x});
		}
		v.push_back({1,1});
		sort(v.begin(),v.end());
		v.push_back({n,m});
		for(ll i=0;i<b;++i){
			ll y,x;
			cin>>y>>x;
			board[y][x]=-1;
		}
		dp[1][1]=1;
		ll ans=1;
		for(ll i=1;i<v.size();++i){
			ll fy=v[i-1].first;
			ll fx=v[i-1].second;
			ll cy=v[i].first;
			ll cx=v[i].second;
			for(ll j=fy;j<=cy;++j){
				for(ll k=fx;k<=cx;++k){
					if(board[j][k]==-1) continue;
					ll c=0;
					if(board[j][k-1]!=-1){
						c+=dp[j][k-1];
					}
					if(board[j-1][k]!=-1){
						c+=dp[j-1][k];
					}
					dp[j][k]=max(dp[j][k],c);
				}
			}
		}
		cout<<dp[n][m];


	}	
	return 0;
}