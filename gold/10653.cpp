#include <iostream>
#include <algorithm>
#include <vector>
#include <cstring>
#include <map>
#include <queue>
#include <cmath>
using namespace std;

#define ll long long

ll dp[500+1][500+1];
int main() {
	ios_base :: sync_with_stdio(false); 
	cin.tie(NULL); 
	cout.tie(NULL);
	ll o=1;
	while(o--){
		// n<=500개의 체크포인트
		// 1번 체크포인트에서 다 지나고 n번에서 끝나야함
		// k개를 몰래 건너뛰려고 함
		// -1000<=x,y<=1000
		ll n,k;
		cin>>n>>k;
		vector<pair<ll,ll>> v;
		for(ll i=0;i<n;++i){
			ll a,b;
			cin>>a>>b;
			v.push_back({a,b});
		}
		for(ll i=0;i<n;++i){
			for(ll j=0;j<n;++j){
				dp[i][j]=2023101800;
			}
		}
		
		// dp[x][y]: x번째 인덱스까지 봤을 때 y개를 건너뛰었을 때 최솟값
		// dp[x][y]=min(dp[x-1][y],dp[x-1][y-1])
		// dp[x-1][y-1]+dist를 선택하는 경우 => 
		dp[0][0]=0;
		for(ll i=1;i<n;++i){
			dp[i][0]=dp[i-1][0]+abs(v[i].first-v[i-1].first)+abs(v[i].second-v[i-1].second);
		}
		for(ll i=1;i<n;++i){
			ll y=v[i].first;
			ll x=v[i].second;
			for(ll j=0;j<=k;++j){
				// j개를 삭제할 경우
				ll c=2023101800;
				for(ll p=1;p<=k;++p){
					if(i-p<0) continue;
					if(j-p+1<0) continue;
					c=min(c,dp[i-p][j-p+1]+abs(y-v[i-p].first)+abs(x-v[i-p].second));
				}
				dp[i][j]=c;
			}
			
		}
		
		cout<<dp[n-1][k];
	}
	return 0;
}