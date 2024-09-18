#include <iostream>
#include <algorithm>
#include <vector>
#include <math.h>
#include <map>
#include <set>
#include <queue>
using namespace std;

#define ll long long

const int MAX=100000+2;
ll v[MAX];
ll dp[MAX][4+1][4+1];

ll calc(ll a, ll b){
	if(a==b) return 1;
	ll tmp_a=min(a,b);
	ll tmp_b=max(a,b);
	// 0,1,2,3,4
	if(tmp_a==0){
		return 2;
	}else if(tmp_a==1){
		if(tmp_b==2){
			return 3;	
		}else if(tmp_b==3){
			return 4;
		}else if(tmp_b==4){
			return 3;
		}
	}else if(tmp_a==2){
		if(tmp_b==3){
			return 3;	
		}else if(tmp_b==4){
			return 4;
		}
	}else if(tmp_a==3){
		return 3;
	}
	return -1;
}
ll INF=1222232421;

int main() {
	// your code goes here
	ios_base :: sync_with_stdio(false); 
	cin.tie(NULL); 
	cout.tie(NULL);
	int o=1;
	while(o--){
		ll idx=0;
		while(1){
			ll a;
			cin>>a;
			if(a==0) break;
			v[idx++]=a;
		}
		if(idx==0){
			cout<<0;
			break;
		}
		ll n=idx;
		for(ll i=0;i<n;++i){
			for(ll j=0;j<=4;++j){
				for(ll k=0;k<=4;++k){
					dp[i][j][k]=INF;
				}
			}
		}
		dp[0][v[0]][0]=2;
		dp[0][0][v[0]]=2;
		for(ll i=1;i<n;++i){
			for(ll j=0;j<=4;++j){
				for(ll k=0;k<=4;++k){
					if(dp[i-1][j][k]!=INF){
						ll cur_num=v[i];
						ll pre_num=dp[i-1][j][k];
						dp[i][cur_num][k]=min(dp[i][cur_num][k],pre_num+calc(cur_num,j));
						dp[i][j][cur_num]=min(dp[i][j][cur_num],pre_num+calc(cur_num,k));
					}
				}
			}
		}
		ll ans=INF;
		for(ll i=0;i<=4;++i){
			for(ll j=0;j<=4;++j){
				ans=min(ans,dp[n-1][i][j]);
			}
		}
		cout<<ans;
	}
	return 0;
}