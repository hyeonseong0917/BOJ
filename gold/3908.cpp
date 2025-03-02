#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <map>
#include <cmath>
using namespace std;

#define ll long long

ll dp[1120+1][14+1];

int main() {
	ios_base :: sync_with_stdio(false); 
	cin.tie(NULL); 
	cout.tie(NULL);
	int o=1;
	cin>>o;
	for(ll i=0;i<=1120;++i){
		for(ll j=0;j<=14;++j){
			dp[i][j]=0;
		}
	}
	vector<ll> tmp;
	dp[2][1]=1;
	map<ll,ll> check;
	++check[2];
	tmp.push_back(2);
	for(ll i=3;i<=1120;i+=2){
		// i가 소수인지?
		bool flag=0;
		for(ll j=3;j<=sqrt(i);++j){
			if(i%j==0){
				flag=1;
				break;
			}
		}
		if(!flag){
			dp[i][1]=1;
			tmp.push_back(i);
			++check[i];
		}
	}
	ll ts=tmp.size();
	vector<ll> psum(ts,0);
	for(ll i=0;i<ts;++i){
		psum[i]=(i==0)?tmp[i]:psum[i-1]+tmp[i];
	}
	for(ll i=1;i<tmp.size();++i){
		ll cur_num=tmp[i];
		for(ll j=min(psum[i-1],1120ll);j>=2;--j){
			for(ll k=1;k<=i;++k){
				if(j>=cur_num && k==1) continue;
				if(dp[j][k] && j+cur_num<=1120 && k+1<=14){
					// if(j+cur_num==24 && k+1==3){
					// 	cout<<j<<" "<<k<<" "<<cur_num<<"\n";
					// }
					dp[j+cur_num][k+1]+=dp[j][k];
				}
			}
		}
	}
	
	while(o--){
		ll n,k;
		cin>>n>>k;
		if(n==1){
			cout<<0<<"\n";
			continue;
		}
		cout<<dp[n][k]<<"\n";
		// n을 서로 다른 k개의 소수로 나타내는 방법?
		ll ans=0;
		
		
	}

	return 0;
}