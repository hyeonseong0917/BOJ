#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <cmath>
using namespace std;

#define ll long long

ll dp[500+1][500+1][2];

int main() {
	// your code goes here
	ll o=1;
	while(o--){
		// 자신 차례가 되었을 때 꺼내지 못하면 짐
		vector<ll> v;
		for(ll i=0;i<3;++i){
			ll a;
			cin>>a;
			v.push_back(a);
			// a<=30
		}
		for(ll i=0;i<=500;++i){
			for(ll j=0;j<=500;++j){
				for(ll k=0;k<2;++k){
					dp[i][j][k]=0;
				}
			}
		}
		for(ll i=0;i<3;++i){
			dp[v[i]][0][0]=1;
			dp[0][v[i]][0]=1;
		}
		// [1][0][0]=1
		// [3][0][0]=1
		// [4][0][0]=1

		for(ll i=0;i<=500;++i){
			for(ll j=0;j<=500;++j){
				for(ll k=0;k<3;++k){
					if(i-v[k]>=0){
						dp[i][j][0]|=1-dp[i-v[k]][j][1];
						dp[i][j][1]|=1-dp[i-v[k]][j][0];
					}
					if(j-v[k]>=0){
						dp[i][j][0]|=1-dp[i][j-v[k]][1];
						dp[i][j][1]|=1-dp[i][j-v[k]][0];
					}
				}
			}
		}
		// dp[x][y][0]: x개, y개가 남았을 때 a턴이면 이길 수 있는지?
		// 0개,0개로 만들기 위해 필요한 횟수
		// 1 3 4
		// 홀수면 A가 이김
		// A가 이길 수 있는지만 확인해보자
		// dp[3][0][0]=1
		// dp[1][0][0]=1
		// dp[4][0][0]=1;
		// dp[3][0][1]=0; // b턴임
		// 0,0,0=0, 0,0,1=1
		// dp[0][1][0]=dp[0][0][1]|
		// dp[0][1][1]=dp[0][0][0] 
		// dp[3][1][0]=dp[2][1][1] | dp[0][1][1]
		// dp[1][1]=
		for(ll i=0;i<5;++i){
			ll k1,k2;
			cin>>k1>>k2;
			// k1,k2<=500
			if(dp[k1][k2][0]){
				cout<<"A"<<"\n";
			}else{
				cout<<"B"<<"\n";
			}
		}
	}
	return 0;
}