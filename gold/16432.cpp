#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <map>
using namespace std;

#define ll long long

ll c,p;
vector<ll> v[1000+1];
ll dp[1000+1][10];
int main() {
	// your code goes here
	int t=1;
	while(t--){
		// 1번부터 9번까지
		// 호랑이는 전날 먹었던 떡이면 먹지 않음
		// 줄 수 있는 떡 없다면 ㅈㅈ
		// N일동아 잡아먹히지 않는 방법
		ll n;
		cin>>n;
		for(ll i=0;i<n;++i){
			for(ll j=0;j<=9;++j){
				dp[i][j]=0;
			}
		}
		for(ll i=0;i<n;++i){
			ll m;
			cin>>m;
			for(ll j=0;j<m;++j){
				ll a;
				cin>>a;
				v[i].push_back(a);
			}
		}
		for(ll i=0;i<v[0].size();++i){
			dp[0][v[0][i]]=1;
		}
		for(ll i=1;i<n;++i){
			for(ll j=0;j<v[i].size();++j){
				ll cur_num=v[i][j]; // 현재 떡의 번호
				for(ll k=1;k<=9;++k){
					if(k==cur_num) continue;
					dp[i][cur_num]|=dp[i-1][k];
				}
			}
		}
		bool flag=0;
		vector<ll> ans;
		for(ll i=1;i<=9;++i){
			if(dp[n-1][i]){
				flag=1;
				ans.push_back(i);
				break;
			}
		}
		if(!flag){
			cout<<-1;
		}else{
			for(ll i=n-2;i>=0;--i){
				for(ll j=1;j<=9;++j){
					if(ans[ans.size()-1]==j) continue;
					if(!dp[i][j]) continue;
					ans.push_back(j);
					break;
				}
			}
			reverse(ans.begin(),ans.end());
			for(ll i=0;i<n;++i){
				cout<<ans[i]<<"\n";
			}
			// for(ll i=0;i<n;++i){
			// 	for(ll j=1;j<=9;++j){
			// 		cout<<i<<" "<<j<<" "<<dp[i][j]<<"\n";
			// 	}
			// }
		}
		
		// x번째 날에 있는 떡의 후보군 y들 중에서서
		// dp[x][y]= x번째 날에 y번째 떡을 먹을 수 있는지?
		// dp[x][y]=dp[x-1][y아닌거]
	}

	return 0;
}