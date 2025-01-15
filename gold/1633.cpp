#include <iostream>
#include <algorithm>
#include <vector>
#include <cstring>
#include <map>
using namespace std;

#define ll long long

ll dp[1000+1][15+1][15+1];
vector<pair<ll,ll>> v;
int main() {
	ios_base :: sync_with_stdio(false); 
	cin.tie(NULL); 
	cout.tie(NULL);
	ll o=1;
	while(o--){
		ll a,b;
		while(cin>>a>>b){
			v.push_back({a,b});
		}
		ll n=v.size();
		for(ll i=0;i<=1000;++i){
			for(ll k=0;k<=15;++k){
				for(ll p=0;p<=15;++p){
					dp[i][k][p]=0;
				}
			}
		}
		// 팀은 흑 15명과 백 15명
		// 전체 팀의 능력치= 흑 15명의 능력치 + 백 15명의 능력치
		// 가장 높은 팀의 능력치를 만드는 방법??
		// 백으로 할 때 전투력과 흑으로 할 때의 전투력이 주어짐
		// i번째 값에 대해 i번째 값을 흑으로 플레이 했을 때 최댓값?
		// dp[i][흑 개수][백 개수]
		// 1000*15*15
		// i번쨰 인덱스까지 봤을 때, 
		// 흑을 x개, 백을 y개 가져간 경우의 최댓값
		// dp[i][x][y]=max(dp[i-1][x-1][y]+v[i].first,dp[i-1][x][y-1]+v[i].second)
		// vs dp[i-1][x][y] -> i번째 값을 가져가지 않는 것이 이득일 경우
		dp[0][1][0]=v[0].first;
		dp[0][0][1]=v[0].second;
		ll ans=0;
		for(ll i=1;i<n;++i){
			// i번째 인덱스까지 봤을 때 최대 돌개수, 흑 개수 + 백 개수=i+1
			for(ll j=0;j<=min(i+1,(ll)15);++j){
				// 흑 개수 j
				for(ll k=0;k<=min(i+1-j,(ll)15);++k){
					// 백 개수 k
					ll fst_num=0, sed_num=0;
					if(j>0){
						fst_num=dp[i-1][j-1][k]+v[i].first;
					}
					if(k>0){
						sed_num=dp[i-1][j][k-1]+v[i].second;
					}
					dp[i][j][k]=max(fst_num,sed_num);
					dp[i][j][k]=max(dp[i][j][k],dp[i-1][j][k]);
					if(j+k==30){
						ans=max(ans,dp[i][j][k]);
					}
				}
			}
		}
		cout<<ans;

	}
	return 0;
}