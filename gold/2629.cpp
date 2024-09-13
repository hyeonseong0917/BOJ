#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <map>
using namespace std;

#define ll long long

ll R_dp[15000+1][30+1];
ll L_dp[15000+1][30+1];
int main() {
	ios_base :: sync_with_stdio(false); 
	cin.tie(NULL); 
	cout.tie(NULL);
	ll o=1;
	while(o--){
		ll n;
		cin>>n;
		vector<ll> dp(15000+1,0);
		vector<ll> v(n,0);
		for(ll i=0;i<n;++i){
			cin>>v[i];
			++dp[v[i]];
		}
		
		for(ll i=0;i<15000+1;++i){
			for(ll j=0;j<30+1;++j){
				R_dp[i][j]=0;
				L_dp[i][j]=0;
			}
		}
		R_dp[v[n-1]][n-1]=1;
		ll idx=n-2;
		while(idx>=0){
			R_dp[v[idx]][idx]=1;
			for(ll i=0;i<15000+1;++i){
				if(R_dp[i][idx+1]){
					if(v[idx]+i<=15000){
						R_dp[v[idx]+i][idx]=1;
						
					}
					R_dp[i][idx]=1;
				}
			}
			--idx;
		}
		L_dp[v[0]][0]=1;
		idx=1;
		while(idx<n){
			L_dp[v[idx]][idx]=1;
			for(ll i=0;i<15000+1;++i){
				if(L_dp[i][idx-1]){
					if(v[idx]+i<=15000){
						L_dp[v[idx]+i][idx]=1;
					}
					L_dp[i][idx]=1;
				}
			}
			++idx;
		}
		vector<ll> lv[30+1], rv[30+1];
		map<pair<ll,ll>,ll> l,r;
		
		for(ll i=0;i<15000+1;++i){
			for(ll j=0;j<30+1;++j){
				if(L_dp[i][j] && !l[{i,j}]){
					l[{i,j}]=1;
					lv[j].push_back(i);
					++dp[i];
				}
				if(R_dp[i][j] && !r[{i,j}]){
					r[{i,j}]=1;
					rv[j].push_back(i);
					++dp[i];
				}
			}
		}
		// lv[x]: [0~x]인덱스까지 만들 수 있는 값들
		// rv[y]: [y~n-1]인덱스까지 만들 수 있는 값들
		// vector<ll> dp(15000+1,0);
		for(ll x=0;x<lv[n-1].size();++x){
			for(ll y=0;y<rv[0].size();++y){
				ll cur_num=abs(lv[n-1][x]-rv[0][y]);
				if(cur_num<=15000){
					++dp[cur_num];
				}
			}
		}
		for(ll i=0;i<n-1;++i){
			// L_dp[x][i]와 R_dp[y][i+1]
			// lv[i]와 rv[i+1]
			for(ll x=0;x<lv[i].size();++x){
				for(ll y=0;y<rv[i+1].size();++y){
					++dp[lv[i][x]];
					++dp[rv[i+1][y]];
					ll new_num=lv[i][x]+rv[i+1][y];
					if(new_num<=15000){
						++dp[new_num];
					}
					
				}
			}
		}
		
		ll k;
		cin>>k;
		for(ll i=0;i<k;++i){
			ll a;
			cin>>a;
			if(a>15000){
				cout<<"N"<<" ";
			}else{
				if(dp[a]){
					cout<<"Y"<<" ";
				}else{
					cout<<"N"<<" ";
				}
			}
		}

	}
	return 0;
}