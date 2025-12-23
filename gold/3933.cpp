#include <iostream>
#include <algorithm>
#include <vector>
#include <cstring>
#include <map>
#include <cmath>
#include <queue>
using namespace std;

#define ll long long

ll dp[32768+1][4+1];

int main() {
	ios_base :: sync_with_stdio(false); 
	cin.tie(NULL); 
	cout.tie(NULL);
	ll o=1;
	while(o--){
		// dp[n][m]: 제곱수 m개를 활용해서 n을 만드는 경우의 수
		vector<ll> sq;
		for(ll i=0;i<=32768;++i){
			for(ll j=0;j<=4;++j){
				dp[i][j]=0;
			}
		}
		for(ll i=1;i*i<=32768;++i){
			sq.push_back(i*i);
		}
		dp[0][0]=1;
		for(ll i=0;i<sq.size();++i){
			ll cur_num=sq[i];
			for(ll j=1;j<=4;++j){
				for(ll k=cur_num;k<=32768;++k){
					dp[k][j]+=dp[k-cur_num][j-1];
				}
			}
		}
		while(1){
			ll a;
			cin>>a;
			if(a==0) break;
			cout<<dp[a][1]+dp[a][2]+dp[a][3]+dp[a][4]<<"\n";
		}
	}
	return 0;
}