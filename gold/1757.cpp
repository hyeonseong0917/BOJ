#include <iostream>
#include <algorithm>
#include <vector>
#include <cstring>
#include <map>
#include <queue>
#include <cmath>
using namespace std;

#define ll long long

ll dp[10000+1][500+1];

int main() {
	ios_base :: sync_with_stdio(false); 
	cin.tie(NULL); 
	cout.tie(NULL);
	ll o=1;
	while(o--){
		// 1417
		// N분안에 완주 가능
		// 1분 달리면 지침지수 +1
		// 1분 쉬면 지침지수 -1
		// 지침지수>M: 더이상 못달림

		// I분에 달렸다면 d[i]만큼 달리기 가능
		// 쉬기 시작하면 지침지수 0전까지 못달림

		// 최대한 멀리 갈 수 있는 거리?
		ll n,m;
		cin>>n>>m;
		vector<ll> D(10000+1,0);
		for(ll i=0;i<n;++i){
			cin>>D[i];
		}
		// 5 2
		// 0 1 2 3 4
		// 5 3 4 2 10
		
		// 마지막에는 쉬어야함 무조건
		// dp[x][y]: x인덱스까지 봤을 때 지침 지수가 y인 경우 최댓값
		// dp[x][y]=max(dp[x-1][y-1]+D[x],dp[x-1][y])
		for(ll i=0;i<n;++i){
			for(ll j=0;j<=m;++j){
				dp[i][j]=0;
			}
		}
		dp[0][1]=D[0];
		for(ll i=1;i<n;++i){
			ll k=min(i+1,m);
			for(ll j=1;j<=k;++j){
				dp[i][j]=dp[i-1][j-1]+D[i];
				if(i-j>=0){
					dp[i][0]=max(dp[i][0],dp[i-j][j]);
					dp[i][0]=max(dp[i-j][0],dp[i][0]);
				}
			}
		}
		cout<<dp[n-1][0]<<"\n";
		
	}
	return 0;
}