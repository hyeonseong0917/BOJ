#include <iostream>
#include <algorithm>
#include <vector>
#include <cstring>
#include <map>
#include <queue>
#include <cmath>
using namespace std;

#define ll long long
#define pb push_back

int main() {
	ios_base :: sync_with_stdio(false); 
	cin.tie(NULL); 
	cout.tie(NULL);
	ll o=1;
	while(o--){
		// 동시에 두 개의 웍을 사용 가능
		// 필요 이상 크기의 웍을 사용하지 않음
		// 주문받은 짜장면의 그릇 수에 딱 맞게 요리
		// 4그릇을 요리할 수 있는 웍에 3그릇 이하 ㄴㄴ
		// 1+3
		// 1
		// 짜장면의 수와 웍의 크기, 최소 몇 번의 요리 필요?
		ll n,m;
		cin>>n>>m;
		// n개의 짜장면을 처리해야함
		vector<ll> v(m,0),p(m,0);
		for(ll i=0;i<m;++i){
			cin>>v[i];
			p[i]=v[i];
		}
		sort(v.begin(),v.end());
		// 한 번 요리를 하는 것에는 모든 웍을 사용할 수 있음
		// 언제 모두 처리할 수 없을까?
		// 1. 최소 크기의 웍이 짜장면 수보다 큼
		// n개의 짜장면을 요리하기 위해 필요한 최소 요리 횟수
		// dp[n]=dp[n-1],dp[n-3],dp[n-4]...2개의 웍?
		
		for(ll i=0;i<m;++i){
			for(ll j=i+1;j<m;++j){
				p.push_back(v[i]+v[j]);
			}
		}
		vector<ll> dp(n+1,2023101800);
		dp[0]=0;
		for(ll i=1;i<=n;++i){
			for(ll j=0;j<p.size();++j){
				if(i-p[j]>=0){
					dp[i]=min(dp[i],dp[i-p[j]]+1);
				}
			}
		}
		if(dp[n]==2023101800){
			cout<<-1;
		}else{
			cout<<dp[n];
		}
	}
	return 0;
}