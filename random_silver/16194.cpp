#include <iostream>
#include <map>
#include <algorithm>
#include <cmath>
#include <vector>
#include <queue>
using namespace std;

#define ll long long

int main() {
	// your code goes here
	ios_base :: sync_with_stdio(false); 
	cin.tie(NULL); 
	cout.tie(NULL);
	int o=1;
	while(o--){
		ll n;
		cin>>n;
		vector<ll> v(n+1,0),dp(n+1,0);
		ll INF=2023101800;
		for(ll i=1;i<=n;++i){
			cin>>v[i];
			dp[i]=INF;
		}
		// v[i]: 카드 i개 묶음 팩의 가격


		// dp[n]을 구해보기
		// dp[x]: 카드 x개를 갖기 위한 최소 비용
		dp[1]=v[1];
		for(ll i=2;i<=n;++i){
			for(ll j=0;j<i;++j){
				dp[i]=min(dp[i],dp[j]+v[i-j]);
			}
		}
		cout<<dp[n];

	}
	return 0;
}