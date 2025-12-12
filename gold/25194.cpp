#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <queue>
#include <cmath>
using namespace std;

#define ll long long

int main() {
	// your code goes here
	ios_base :: sync_with_stdio(false); 
	cin.tie(NULL); 
	cout.tie(NULL);
	ll o=1;
	while(o--){
		ll n;
		cin>>n;
		vector<ll> v(n,0);
		for(ll i=0;i<n;++i){
			cin>>v[i];
		}
		// 오늘은 월요일. 금요일에 일을 정확히 끝낼 수 있다면?
		// sum%7이 4라면 가능하다
		ll dp[n][7];
		for(ll i=0;i<n;++i){
			for(ll j=0;j<7;++j){
				dp[i][j]=0;
			}
		}
		dp[0][v[0]%7]=1;
		for(ll i=1;i<n;++i){
			dp[i][v[i]%7]=1;
			for(ll j=0;j<7;++j){
				if(dp[i-1][j]){
					dp[i][j]=1;
					dp[i][(j+v[i])%7]=1;
				}
			}
		}
		bool flag=0;
		for(ll i=0;i<n;++i){
			if(dp[i][4]){
				flag=1;
			}
		}
		if(flag){
			cout<<"YES";
		}else{
			cout<<"NO";
		}
		// 3
		// 4 4 4
		// 월화수목
		// 5
		// 5 5 5 5 5
		// 월화수목금
		// 토일월화수
		// 목금토일월
		// 화수목금토
		// 일월화수목
	}
	return 0;
}