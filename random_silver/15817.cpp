#include <iostream>
#include <map>
#include <algorithm>
#include <cmath>
#include <vector>
using namespace std;

#define ll long long

ll dp[10000+1];
int main() {
	// your code goes here
	ios_base :: sync_with_stdio(false); 
	cin.tie(NULL); 
	cout.tie(NULL);
	int t=1;
	while(t--){
		ll n,x;
		cin>>n>>x;
		vector<ll> num(n,0), cnt(n,0);
		for(ll i=0;i<n;++i){
			cin>>num[i]>>cnt[i];
		}
		
		for(ll i=0;i<10000+1;++i){
			dp[i]=0;
		}
		dp[0]=1;
		for(ll i=0;i<n;++i){
			ll cur_num=num[i];
			ll cur_cnt=cnt[i];
			for(ll j=x;j>=1;--j){
				for(ll k=1;k<=cur_cnt && j-cur_num*k>=0;++k){
					dp[j]+=dp[j-k*cur_num];
				}
			}
		}
		cout<<dp[x];
	}
	return 0;
}