#include <iostream>
#include <algorithm>
#include <vector>
#include <math.h>
#include <map>
#include <set>
using namespace std;

#define ll long long

ll board[50+1][50+1];

int main() {
	// your code goes here
	ios_base :: sync_with_stdio(false); 
	cin.tie(NULL); 
	cout.tie(NULL);
	int o=1;
	while(o--){
		ll n,m;
		cin>>n>>m;
		for(ll i=0;i<n;++i){
			for(ll j=0;j<m;++j){
				cin>>board[i][j];
			}
		}
		ll ans=2023101800;
		for(ll i=0;i<n;++i){
			// i번째 줄을 조커 줄로 했을 때
			vector<ll> v(m,0);
			ll cnt=0; // 0 0 0이거나 1 0 0인 행의 개수
			for(ll j=0;j<n;++j){
				if(i==j) continue;
				// j번째 줄에서는 어떤 카드를 남기고 i번째 줄로 다 보낼지?
				// 1 0 0 0 0, 0 0 0 0 0 얘네는 안건드리는게
				ll cur_cnt=0;
				ll cur_idx=-1;
				for(ll k=0;k<m;++k){
					if(!board[j][k]) continue;
					++cur_cnt;
					cur_idx=k;
				}
				if(cur_idx==-1){
					++cnt;
					continue;
				}
				if(cur_cnt==1){
					if(!v[cur_idx]){
						++v[cur_idx];
						++cnt;
					}
				}
			}
			ans=min(ans,n-1-cnt);
		}
		cout<<ans;
	}
	return 0;
}