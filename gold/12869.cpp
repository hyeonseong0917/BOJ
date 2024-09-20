#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <map>
using namespace std;

#define ll long long

const int MAX=60+1;
ll sed_dp[MAX][MAX];
ll trd_dp[MAX][MAX][MAX];
ll get_sed_dp(ll x, ll y){
	if(x==0 && y==0) return 0;
	if(sed_dp[x][y]!=0) return sed_dp[x][y];
	ll cx=x-9;
	if(cx<0) cx=0;
	ll cy=y-3;
	if(cy<0) cy=0;
	ll nx=x-3;
	if(nx<0) nx=0;
	ll ny=y-9;
	if(ny<0) ny=0;
	return sed_dp[x][y]=min(get_sed_dp(cx,cy),get_sed_dp(nx,ny))+1;
}
ll trd_hp[3]={1,3,9};
ll get_trd_dp(ll x, ll y, ll z){
	if(x==0 && y==0 && z==0) return 0;
	if(trd_dp[x][y][z]!=0) return trd_dp[x][y][z];
	ll min_num=2023101800;
	for(ll i=0;i<3;++i){
		for(ll j=0;j<3;++j){
			for(ll k=0;k<3;++k){
				if(i==j || i==k || j==k) continue;
				ll cx=max((ll)0,x-trd_hp[i]);
				ll cy=max((ll)0,y-trd_hp[j]);
				ll cz=max((ll)0,z-trd_hp[k]);
				
				min_num=min(min_num,get_trd_dp(cx,cy,cz));
			}
		}
	}
	return trd_dp[x][y][z]=min_num+1;
}
int main() {
	ios_base :: sync_with_stdio(false); 
	cin.tie(NULL); 
	cout.tie(NULL);
	ll o=1;
	while(o--){
		ll n;
		cin>>n;
		ll x,y,z;
		if(n==1){
			cin>>x;
			if(x%9==0){
				cout<<x/9;
			}else{
				cout<<(x/9)+1;
			}
		}else if(n==2){
			for(ll i=0;i<MAX;++i){
				for(ll j=0;j<MAX;++j){
					sed_dp[i][j]=0;
				}
			}
			cin>>x>>y;
			cout<<get_sed_dp(x,y);
		}else{
			for(ll i=0;i<MAX;++i){
				for(ll j=0;j<MAX;++j){
					for(ll k=0;k<MAX;++k){
						trd_dp[i][j][k]=0;
					}
				}
			}
			cin>>x>>y>>z;
			cout<<get_trd_dp(x,y,z);
		}
	}
	return 0;
}