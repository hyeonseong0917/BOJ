#include <iostream>
#include <algorithm>
#include <vector>
#include <cstring>
#include <map>
#include <deque>
#include <cmath>
using namespace std;

#define ll long long
#define pb push_back

ll board[100+1][100+1];

int main() {
	ios_base :: sync_with_stdio(false); 
	cin.tie(NULL); 
	cout.tie(NULL);
	ll t=1;
	// cin>>t;
	while(t--){
		ll n,m;
		cin>>n>>m;
		// 1906
		// 1 2 2 1
		// 1 1 1 2
		// 1 2 1 2

		for(ll i=0;i<n;++i){
			for(ll j=0;j<m;++j){
				cin>>board[i][j];
			}
		}
		ll ans=0;
		ll L=0, R=0;
		for(ll i=0;i<n;++i){
			// 0 1 2 3 4 5 6 7 8
			// 1 1 2 2 1 1 2 2 1
			L=0, R=0;
			for(ll j=0;j<m;++j){
				if(board[i][j]==0){
					// [L,R]에서 
					// 1. 1의 구간 개수
					ll one_cnt=0;
					bool one_seg=0;
					for(ll k=L;k<=R;++k){
						if(board[i][k]==1){
							if(!one_seg){
								++one_cnt;
								one_seg=1;
							}
						}else{
							one_seg=0;
						}
					}
					ll sed_cnt=0;
					bool sed_seg=0;
					for(ll k=L;k<=R;++k){
						if(board[i][k]==2){
							if(!sed_seg){
								++sed_cnt;
								sed_seg=1;
							}
						}else{
							sed_seg=0;
						}
					}
					L=j+1;
					R=j+1;
					if(one_cnt==0 && sed_cnt==0) continue;
					if(one_cnt==0 || sed_cnt==0){
						ans+=1;
					}else{
						ans+=min(one_cnt,sed_cnt)+1;
					}
				}else{
					R=j;
				}
			}
			if(L>=m || R>=m) continue;
			ll one_cnt=0;
			bool one_seg=0;
			for(ll k=L;k<=R;++k){
				if(board[i][k]==1){
					if(!one_seg){
						++one_cnt;
						one_seg=1;
					}
				}else{
					one_seg=0;
				}
			}
			ll sed_cnt=0;
			bool sed_seg=0;
			for(ll k=L;k<=R;++k){
				if(board[i][k]==2){
					if(!sed_seg){
						++sed_cnt;
						sed_seg=1;
					}
				}else{
					sed_seg=0;
				}
			}
			if(one_cnt==0 && sed_cnt==0) continue;
			if(one_cnt==0 || sed_cnt==0){
				ans+=1;
			}else{
				ans+=min(one_cnt,sed_cnt)+1;
			}
		}
		cout<<ans;

	} 
	return 0;
}